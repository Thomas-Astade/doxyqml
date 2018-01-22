/******************************************************************
 * This code was generated by the Astade CppGenerator.            *
 * The generated code is not per se a derivative work of Astade;  *
 * the original copyright to this code is held by the holder(s)   *
 * of the copyright to the underlying model at the time this code *
 * was generated; this code may be distributed under terms of     *
 * his/her/their choice.                                          */
/** the root of the abstract syntax tree
 *  @file CRootElement.cpp
 ******************************************************************/

//****** implementation prolog ******
//[Package_doxyqml/Package_ast/classes/class_CRootElement/prolog.cpp]
#include <typeinfo>
#include "CObjectDeclaration.h"
//[EOF]
//***********************************

#include "CRootElement.h"	 // own header

// Relation includes:
#include "CQmlObject.h"


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

void doxyqml::CRootElement::addChild(CQmlObject* child)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "addChild", "CQmlObject* child", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_RXRCQJOW/code.cpp]
	//~~ void addChild(CQmlObject* child) [CRootElement] ~~
	if (state==0)
	    myChilds.push_back(child);
	else
	    myMemberChilds.push_back(child);
//[EOF]
}

doxyqml::CRootElement::CRootElement() :
	state(0)
{
	NOTIFY_CONSTRUCTOR(5, "CRootElement", "")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/constructor/code.cpp]
	//~~ CRootElement(const std::string& filename) [CRootElement] ~~
//[EOF]
}

void doxyqml::CRootElement::print() const
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "print", "", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_print/code.cpp]
	//~~ void print() [CRootElement] ~~
	CQmlObject::print();
	
	printf("namespace %s {\n",m_Namespace.c_str());
	printf("class %s ",m_Classname.c_str());
	
	if (!m_BaseClass.empty())
	    printf(": public %s",m_BaseClass.c_str());
	    
	printf(" {\n");
	
	for (std::vector<CQmlObject*>::const_iterator it = myMemberChilds.begin(); it != myMemberChilds.end(); it++)
	    (*it)->print();
	    
	printf("};\n");
	printf("}\n");
//[EOF]
}

void doxyqml::CRootElement::setBaseClass(const std::string& baseClass)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "setBaseClass", "const std::string& baseClass", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_setBaseClass/code.cpp]
	//~~ void setBaseClass(const std::string& baseClass) [CRootElement] ~~
	m_BaseClass = baseClass;
//[EOF]
}

void doxyqml::CRootElement::setFilename(const std::string& filename)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "setFilename", "const std::string& filename", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_setFilename/code.cpp]
	//~~ void setFilename(const std::string& filename) [CRootElement] ~~
	m_Classname = filename;
	m_Filename = filename;
	
	size_t pos = m_Classname.find('.');
	if (pos != std::string::npos)
	    m_Classname.erase(pos);
	
	pos = m_Classname.rfind('/');
	if (pos != std::string::npos)
	    m_Classname.erase(0,pos+1);
	
	m_Namespace = filename;
	
	pos = m_Namespace.rfind('/');
	if (pos != std::string::npos)
	    m_Namespace.erase(pos);
	
	
	do {
	    pos = m_Namespace.find('/');
	    if (pos != std::string::npos)
	    {
	        m_Namespace.erase(pos,1);
	        m_Namespace.insert(pos,"::");
	    }
	} while (pos != std::string::npos);
//[EOF]
}

void doxyqml::CRootElement::setMemberState()
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "setMemberState", "", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_JIUHNTZD/code.cpp]
	//~~ void setMemberState() [CRootElement] ~~
	state = 1;
//[EOF]
}

