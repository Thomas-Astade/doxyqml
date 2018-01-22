/******************************************************************
 * This code was generated by the Astade CppGenerator.            *
 * The generated code is not per se a derivative work of Astade;  *
 * the original copyright to this code is held by the holder(s)   *
 * of the copyright to the underlying model at the time this code *
 * was generated; this code may be distributed under terms of     *
 * his/her/their choice.                                          */
/** a declared object
 *  @file CObjectDeclaration.cpp
 ******************************************************************/

#include "CObjectDeclaration.h"	 // own header



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

unsigned int	doxyqml::CObjectDeclaration::idCounter = 0;

void doxyqml::CObjectDeclaration::add_namespace(const std::string& Namespace)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CObjectDeclaration", "add_namespace", "const std::string& Namespace", "void ")
//[Package_doxyqml/Package_ast/classes/class_CObjectDeclaration/operations/operation_MCJZPSBR/code.cpp]
	//~~ void add_namespace(const std::string& Namespace) [CObjectDeclaration] ~~
	m_ObjectName += "::";
	m_ObjectName += Namespace;
//[EOF]
}

doxyqml::CObjectDeclaration::CObjectDeclaration(const std::string& objectName) :
	m_ObjectName(objectName)
{
	NOTIFY_CONSTRUCTOR(5, "CObjectDeclaration", "const std::string& objectName")
//[Package_doxyqml/Package_ast/classes/class_CObjectDeclaration/operations/constructor/code.cpp]
	//~~ CRootElement(const std::string& filename) [CRootElement] ~~
//[EOF]
}

void doxyqml::CObjectDeclaration::print() const
{
	NOTIFY_FUNCTION_CALL(this, 5, "CObjectDeclaration", "print", "", "void ")
//[Package_doxyqml/Package_ast/classes/class_CObjectDeclaration/operations/operation_print/code.cpp]
	//~~ void print() [CObjectDeclaration] ~~
	if (m_id.empty())
	{
	    printf ("private: %s attr_%d;\n", m_ObjectName.c_str(),idCounter++);
	}
	else
	{
	    printf ("private: %s %s;\n", m_ObjectName.c_str(), m_id.c_str());
	}
//[EOF]
}

void doxyqml::CObjectDeclaration::set_id(const std::string& id)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CObjectDeclaration", "set_id", "const std::string& id", "void ")
//[Package_doxyqml/Package_ast/classes/class_CObjectDeclaration/operations/operation_set_id/code.cpp]
	//~~ void set_id(const std::string& id) [CObjectDeclaration] ~~
	m_id = id;
//[EOF]
}

