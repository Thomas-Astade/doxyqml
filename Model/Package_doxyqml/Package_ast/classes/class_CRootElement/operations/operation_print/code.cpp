//~~ void print(bool hasComment) [CRootElement] ~~
printf("namespace %s {\n",m_Namespace.c_str());

CQmlObject::print(true);

printf("class %s ",m_Classname.c_str());

if (!m_BaseClass.empty())
    printf(": public %s",m_BaseClass.c_str());
    
printf(" {\n");

std::vector<CQmlObject*>::const_iterator old = myMemberChilds.end();

for (std::vector<CQmlObject*>::const_iterator it = myMemberChilds.begin(); it != myMemberChilds.end(); it++)
{
    bool isDocumented = (old != myMemberChilds.end()) && ((dynamic_cast<const CSinglelineComment*>(*old) != 0) || (dynamic_cast<const CMultilineComment*>(*old) != 0));
        
    (*it)->print(isDocumented);
    
    old = it;
}

printf("};\n");
printf("}\n");
