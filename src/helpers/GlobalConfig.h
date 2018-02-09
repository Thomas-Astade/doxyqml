#include <QtQuick/QQuickItem>
#include <qt5/QtCore/QStandardPaths>
#include "PropertyHelper.h"

/**@brief contains program wide properties which are stored between sessions
 * 
 * The data is stored in a json file.
 */

class CGlobalConfig : public QQuickItem
{
    Q_OBJECT

    WRITABLE_PROPERTY_EXTRA_ON_CHANGE_DOCUMENTED(QString, filenameToken, setFilename(), this string is to make your config filename unique for your application. select a string to identify your application - it will be used as part of the filename.);
    READONLY_PROPERTY_DOCUMENTED(bool, modified, this is for indicating data modification);
    READONLY_PROPERTY_DOCUMENTED(QString, filename, this is the filename of the global config file);

public:
    
    ///@brief function to save all properties to a json file
    Q_INVOKABLE void save();

    ///@brief function to load all properties from a json file
    Q_INVOKABLE void load();
    
    ///@brief constructor initializes the member variables
    CGlobalConfig(QQuickItem *parent = Q_NULLPTR);
    
private:

    void setFilename(){m_filename = QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation)+"/Precitec/"+m_filenameToken+"_global.json";};
};
