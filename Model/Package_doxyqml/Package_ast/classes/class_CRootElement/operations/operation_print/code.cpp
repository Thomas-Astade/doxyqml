//~~ void print() [CRootElement] ~~
CQmlObject::print();

printf("class %s ",m_Classname.c_str());

if (!m_BaseClass.empty())
    printf(": public %s",m_BaseClass.c_str());
    
printf(" {\n");

for (std::vector<CQmlObject*>::const_iterator it = myMemberChilds.begin(); it != myMemberChilds.end(); it++)
    (*it)->print();
    
printf("};\n");
