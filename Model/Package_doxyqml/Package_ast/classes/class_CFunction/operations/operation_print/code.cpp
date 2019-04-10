//~~ void print() [CFunction] ~~
if (m_internal)
{
    printf("///This is a private function.\n");
    printf("private: void %s;\n",m_CommentText.c_str());
}
else
{
    printf("public: void %s;\n",m_CommentText.c_str());
}
