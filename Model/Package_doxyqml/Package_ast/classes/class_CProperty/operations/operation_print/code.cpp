//~~ void print() [CProperty] ~~
if (m_internal)
{
    printf("///Only for internal use.\n");
    printf("private: Q_PROPERTY(%s);\n",m_CommentText.c_str());
} 
else    
{
    printf("public: Q_PROPERTY(%s);\n",m_CommentText.c_str());
}     
