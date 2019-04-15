//~~ void print(bool hasComment) [CFunction] ~~
if (m_internal)
{
    if (hasComment)
        printf("private: void %s;\n",m_CommentText.c_str());
}
else
{
    printf("public: void %s;\n",m_CommentText.c_str());
}
