//~~ CRootElement(const std::string& filename) [CRootElement] ~~
size_t pos = m_Classname.find('.');
if (pos != std::string::npos)
    m_Classname.erase(pos);

pos = m_Classname.rfind('/');
if (pos != std::string::npos)
    m_Classname.erase(0,pos+1);
