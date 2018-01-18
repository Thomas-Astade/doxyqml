//~~ void print() [CRootElement] ~~
for (std::vector<CQmlObject*>::const_iterator it = myChilds.begin(); it != myChilds.end(); it++)
{
    if (dynamic_cast<CObjectDeclaration*>(*it))
    {
        printf("class %s ",m_Classname.c_str());
        if (!m_BaseClass.empty())
            printf(": public %s",m_BaseClass.c_str());
        printf(" {\n");
    }
    (*it)->print();
}
printf("};\n");
