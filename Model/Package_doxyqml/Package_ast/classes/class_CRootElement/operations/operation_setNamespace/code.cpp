//~~ void setNamespace(const std::string& Namespace) [CRootElement] ~~
m_Namespace = Namespace;
size_t pos;

do {
    pos = m_Namespace.find('.');
    if (pos != std::string::npos)
    {
        m_Namespace.erase(pos,1);
        m_Namespace.insert(pos,"::");
    }
} while (pos != std::string::npos);
