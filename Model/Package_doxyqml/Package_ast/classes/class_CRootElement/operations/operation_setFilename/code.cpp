//~~ void setFilename(const std::string& filename) [CRootElement] ~~
m_Classname = filename;
m_Filename = filename;

size_t pos = m_Classname.rfind('.');
if (pos != std::string::npos)
    m_Classname.erase(pos);

pos = m_Classname.rfind('/');
if (pos != std::string::npos)
    m_Classname.erase(0,pos+1);

m_Namespace = filename;

const char* qml_strip = getenv("doxyqml_strip");
if (qml_strip == 0)
    qml_strip = "/qml/";

pos = m_Namespace.find(qml_strip);
if (pos != std::string::npos)
    m_Namespace.erase(0,pos+1);

pos = m_Namespace.rfind('/');
if (pos != std::string::npos)
    m_Namespace.erase(pos);

do {
    pos = m_Namespace.find("../");
    if (pos != std::string::npos)
        m_Namespace.erase(pos,3);
} while (pos != std::string::npos);

do {
    pos = m_Namespace.find("./");
    if (pos != std::string::npos)
        m_Namespace.erase(pos,2);
} while (pos != std::string::npos);

do {
    pos = m_Namespace.find('/');
    if (pos != std::string::npos)
    {
        m_Namespace.erase(pos,1);
        m_Namespace.insert(pos,"::");
    }
} while (pos != std::string::npos);
