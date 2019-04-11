//~~ void print(bool hasComment) [CQmlObject] ~~
std::vector<CQmlObject*>::const_iterator old = myChilds.end();


for (std::vector<CQmlObject*>::const_iterator it = myChilds.begin(); it != myChilds.end(); it++)
{
    bool isDocumented = (old != myChilds.end()) && ((dynamic_cast<const CSinglelineComment*>(*old) != 0) || (dynamic_cast<const CMultilineComment*>(*old) != 0));
        
    (*it)->print(isDocumented);
    
    old = it;
}