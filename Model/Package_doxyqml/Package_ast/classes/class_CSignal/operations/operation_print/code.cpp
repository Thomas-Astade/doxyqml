//~~ void print(bool hasComment) [CSignal] ~~
if (m_internal)
{
    printf("private: Q_SIGNALS: %s;\n",m_CommentText.c_str());
} 
else
{
    printf("public: Q_SIGNALS: %s;\n",m_CommentText.c_str());
} 
