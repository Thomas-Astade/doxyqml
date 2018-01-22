//~~ void addChild(CQmlObject* child) [CRootElement] ~~
if (state==0)
    myChilds.push_back(child);
else
    myMemberChilds.push_back(child);
