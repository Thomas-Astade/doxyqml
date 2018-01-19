//~~ void setFilename(const std::string& filename) [CRootElement] ~~
m_Classname = filename;
m_Filename = filename;

size_t pos = m_Classname.find('.');
if (pos != std::string::npos)
    m_Classname.erase(pos);

pos = m_Classname.rfind('/');
if (pos != std::string::npos)
    m_Classname.erase(0,pos+1);
