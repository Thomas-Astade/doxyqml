//~~ void add_namespace(const std::string& Namespace) [CRootElement] ~~
if (!mySubObjects.empty())
    mySubObjects.back()->add_namespace(Namespace);
else
{
    m_BaseClass += "::";
    m_BaseClass += Namespace;
}