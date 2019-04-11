//~~ void print(bool hasComment) [CObjectDeclaration] ~~
if (!hasComment)
    printf("///This is a private object.\n");
    
if (m_id.empty())
{
    printf("///@todo give this object a meaningful id.\n");
    printf ("private: %s attr_%d;\n", m_ObjectName.c_str(),idCounter++);
}
else
{
    printf ("private: %s %s;\n", m_ObjectName.c_str(), m_id.c_str());
}
