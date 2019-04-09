//~~ void print() [CProperty] ~~
if (!m_internal)
{
    printf("public: Q_PROPERTY(%s);\n",m_CommentText.c_str());
}     
