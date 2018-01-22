//~~ CNamespaceImport(const std::string& filename, const std::string& namespaceName) [CNamespaceImport] ~~
size_t pos;

do {
    pos = m_filename.find("../");
    if (pos != std::string::npos)
        m_filename.erase(pos,3);
} while (pos != std::string::npos);

do {
    pos = m_filename.find('/');
    if (pos != std::string::npos)
    {
        m_filename.erase(pos,1);
        m_filename.insert(pos,"::");
    }
} while (pos != std::string::npos);
