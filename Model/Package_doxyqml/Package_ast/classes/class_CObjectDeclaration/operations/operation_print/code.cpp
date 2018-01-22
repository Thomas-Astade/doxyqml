//~~ void print() [CObjectDeclaration] ~~
if (m_id.empty())
{
    printf ("private: %s attr_%d;\n", m_ObjectName.c_str(),idCounter++);
}
else
{
    printf ("private: %s %s;\n", m_ObjectName.c_str(), m_id.c_str());
}
