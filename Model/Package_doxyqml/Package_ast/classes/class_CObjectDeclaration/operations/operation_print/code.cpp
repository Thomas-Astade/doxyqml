//~~ void print() [CObjectDeclaration] ~~
if (m_id.empty())
{
    printf ("private: attr_%d %s;\n",idCounter++, m_ObjectName.c_str());
}
else
{
    printf ("private: %s %s;\n",m_id.c_str(), m_ObjectName.c_str());
}
