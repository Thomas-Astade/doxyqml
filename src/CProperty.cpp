/******************************************************************
 * This code was generated by the Astade CppGenerator.            *
 * The generated code is not per se a derivative work of Astade;  *
 * the original copyright to this code is held by the holder(s)   *
 * of the copyright to the underlying model at the time this code *
 * was generated; this code may be distributed under terms of     *
 * his/her/their choice.                                          */
/** a property
 *  @file CProperty.cpp
 ******************************************************************/

#include "CProperty.h"	 // own header



//****** Trace Macros ***************
#ifndef NOTIFY_CONSTRUCTOR
#  define NOTIFY_CONSTRUCTOR(a,b,c)
#endif
#ifndef NOTIFY_DESTRUCTOR
#  define NOTIFY_DESTRUCTOR(a,b)
#endif
#ifndef NOTIFY_FUNCTION_CALL
#  define NOTIFY_FUNCTION_CALL(a,b,c,d,e,f)
#endif
#ifndef NOTIFY_RETURN_VALUE
#  define NOTIFY_RETURN_VALUE(a)
#endif
#ifndef RETURN
#  define RETURN(a) return(a)
#endif

#ifndef LOG
#  define LOG(...)
#endif

doxyqml::CProperty::CProperty(const std::string& comment)
{
	NOTIFY_CONSTRUCTOR(5, "CProperty", "const std::string& comment")
//[Package_doxyqml/Package_ast/classes/class_BELKKAUG/operations/constructor_YPQJPKPZ/code.cpp]
	//~~ CProperty(const std::string& comment) [CProperty] ~~
	m_CommentText = trim(comment);
//[EOF]
}

void doxyqml::CProperty::print() const
{
	NOTIFY_FUNCTION_CALL(this, 5, "CProperty", "print", "", "void ")
//[Package_doxyqml/Package_ast/classes/class_BELKKAUG/operations/operation_RVONLULC/code.cpp]
	//~~ void print() [CProperty] ~~
	printf("Q_PROPERTY(%s)\n",m_CommentText.c_str());
//[EOF]
}

