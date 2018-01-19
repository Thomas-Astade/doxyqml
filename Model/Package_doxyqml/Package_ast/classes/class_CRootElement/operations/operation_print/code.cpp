//~~ void print() [CRootElement] ~~
CQmlObject::print();
printf("class %s ",m_Classname.c_str());
if (!m_BaseClass.empty())
    printf(": public %s",m_BaseClass.c_str());
printf(" {\n");
printf("};\n");
