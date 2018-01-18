//~~ void print() [CQmlObject] ~~
for (std::vector<CQmlObject*>::const_iterator it = myChilds.begin(); it != myChilds.end(); it++)
    (*it)->print();