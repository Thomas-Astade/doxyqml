//~~ void print() [CNamespaceImport] ~~
if ((m_NamespaceName+"::") == m_filename)
    printf("// ");

printf("namespace %s = %s;\n",m_NamespaceName.c_str(),m_filename.c_str());
