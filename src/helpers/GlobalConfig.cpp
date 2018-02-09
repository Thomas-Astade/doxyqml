#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>
#include "GlobalConfig.h"

CGlobalConfig::CGlobalConfig(QQuickItem* parent)
    : QQuickItem(parent)
    , m_modified(false)
    , m_filename(QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation)+"/Precitec/"+m_filenameToken+"_global.json")
{
}

void CGlobalConfig::load()
{
    QFile loadFile(m_filename);

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        ///@todo error handling
        return;
    }

    QByteArray loadData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));

    const QMetaObject* m = metaObject();
    int count = m->propertyCount();
    int offset = m->propertyOffset();
    
    for (int i = offset; i < count; i++)
    {
        QMetaProperty p(m->property(i));
        
        switch (p.type())
        {
            case 1:  if (loadDoc.object().find(p.name()) != loadDoc.object().end())
                        p.write(this, loadDoc.object()[p.name()].toBool());
                break;

            case 2:  if (loadDoc.object().find(p.name()) != loadDoc.object().end())
                        p.write(this, loadDoc.object()[p.name()].toInt());
                break;

            case 6:  if (loadDoc.object().find(p.name()) != loadDoc.object().end())
                        p.write(this, loadDoc.object()[p.name()].toDouble());
                break;

            default: std::cout << p.typeName() << "(" << p.type() << ") " << p.name() << " not supported!" << std::endl;
        }        
    }
    
    set_modified(false);
}
    
void CGlobalConfig::save()
{
    
    
    QFile saveFile(m_filename);

    if (!saveFile.open(QIODevice::WriteOnly))
    {
        ///@todo error handling
        return;
    }

    QJsonObject saveObject;

    const QMetaObject* m = metaObject();
    int count = m->propertyCount();
    int offset = m->propertyOffset();
    
    for (int i = offset; i < count; i++)
    {
        QMetaProperty p(m->property(i));
        
        switch (p.type())
        {
            case 1:  saveObject[p.name()] = p.read(this).toBool();
                break;

            case 2:  saveObject[p.name()] = p.read(this).toInt();
                break;

            case 6:  saveObject[p.name()] = p.read(this).toDouble();
                break;

            default: std::cout << p.typeName() << "(" << p.type() << ") " << p.name() << " not supported!" << std::endl;
        }        
    }
    
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson(QJsonDocument::Indented));

    set_modified(false);
}

