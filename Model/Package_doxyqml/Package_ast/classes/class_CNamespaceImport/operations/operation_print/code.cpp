//~~ void print() [CNamespaceImport] ~~
if ((m_NamespaceName+"::") == m_filename)
    printf("// ");

if (m_NamespaceName == m_filename)
    return;

printf("namespace %s = %s;\n",m_NamespaceName.c_str(),m_filename.c_str());
