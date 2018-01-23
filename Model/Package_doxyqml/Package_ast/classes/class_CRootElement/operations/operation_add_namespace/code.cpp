//~~ void add_namespace(const std::string& Namespace) [CRootElement] ~~
if (lastSubObject != 0)
    lastSubObject->add_namespace(Namespace);
else
{
    m_BaseClass += "::";
    m_BaseClass += Namespace;
}