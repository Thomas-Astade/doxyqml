//~~ void print(bool hasComment) [CProperty] ~~
if (m_internal)
{
    if (!hasComment)
        printf("///Only for internal use.\n");
    printf("private: Q_PROPERTY(%s);\n",m_CommentText.c_str());
} 
else    
{
    printf("public: Q_PROPERTY(%s);\n",m_CommentText.c_str());
}     
