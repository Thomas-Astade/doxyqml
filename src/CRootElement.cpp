/*
Copyright 2018 Thomas Spitzer <doxyqml@astade.de>
All rights reserved.

This software is a fork of the doxyqml tool written in python, by Aurélien Gâteau
(https://github.com/agateau/doxyqml)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
*/

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
#include "CMultilineComment.h"
#include "CObjectDeclaration.h"
#include "CQmlObject.h"
#include "CSinglelineComment.h"


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

void doxyqml::CRootElement::add_namespace(const std::string& Namespace)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "add_namespace", "const std::string& Namespace", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_add_namespace/code.cpp]
	//~~ void add_namespace(const std::string& Namespace) [CRootElement] ~~
	if (lastSubObject != 0)
	    lastSubObject->add_namespace(Namespace);
	else
	{
	    m_BaseClass += "::";
	    m_BaseClass += Namespace;
	}
//[EOF]
}

void doxyqml::CRootElement::addChild(CQmlObject* child)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "addChild", "CQmlObject* child", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_addChild/code.cpp]
	//~~ void addChild(CQmlObject* child) [CRootElement] ~~
	if (state==0)
	    myChilds.push_back(child);
	else
	    myMemberChilds.push_back(child);
//[EOF]
}

void doxyqml::CRootElement::addSubObject(CObjectDeclaration* child)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "addSubObject", "CObjectDeclaration* child", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_addSubObject/code.cpp]
	//~~ void addSubObject(CObjectDeclaration* child) [CRootElement] ~~
	lastSubObject = child;
	myMemberChilds.push_back(child);
//[EOF]
}

doxyqml::CRootElement::CRootElement() :
	lastSubObject(0),
	state(0)
{
	NOTIFY_CONSTRUCTOR(5, "CRootElement", "")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/constructor/code.cpp]
	//~~ CRootElement(const std::string& filename) [CRootElement] ~~
//[EOF]
}

void doxyqml::CRootElement::print(bool hasComment) const
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "print", "bool hasComment", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_print/code.cpp]
	//~~ void print(bool hasComment) [CRootElement] ~~
	printf("namespace %s {\n",m_Namespace.c_str());
	
	CQmlObject::print(true);
	
	printf("class %s ",m_Classname.c_str());
	
	if (!m_BaseClass.empty())
	    printf(": public %s",m_BaseClass.c_str());
	    
	printf(" {\n");
	
	std::vector<CQmlObject*>::const_iterator old = myMemberChilds.end();
	
	for (std::vector<CQmlObject*>::const_iterator it = myMemberChilds.begin(); it != myMemberChilds.end(); it++)
	{
	    bool isDocumented = (old != myMemberChilds.end()) && ((dynamic_cast<const CSinglelineComment*>(*old) != 0) || (dynamic_cast<const CMultilineComment*>(*old) != 0));
	        
	    (*it)->print(isDocumented);
	    
	    old = it;
	}
	
	printf("};\n");
	printf("}\n");
//[EOF]
}

void doxyqml::CRootElement::set_id(const std::string& id)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "set_id", "const std::string& id", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_set_id/code.cpp]
	//~~ void set_id(const std::string& id) [CRootElement] ~~
	if (lastSubObject != 0)
	    lastSubObject->set_id(id);
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
	
	size_t pos = m_Classname.rfind('.');
	if (pos != std::string::npos)
	    m_Classname.erase(pos);
	
	pos = m_Classname.rfind('/');
	if (pos != std::string::npos)
	    m_Classname.erase(0,pos+1);
	
	if (m_Namespace.empty())
	{
	    m_Namespace = filename;
	
	    const char* qml_strip = getenv("doxyqml_strip");
	    if (qml_strip == 0)
	        qml_strip = "/qml/";
	
	    pos = m_Namespace.find(qml_strip);
	    if (pos != std::string::npos)
	        m_Namespace.erase(0,pos+1);
	
	    pos = m_Namespace.rfind('/');
	    if (pos != std::string::npos)
	        m_Namespace.erase(pos);
	
	    do {
	        pos = m_Namespace.find("../");
	        if (pos != std::string::npos)
	            m_Namespace.erase(pos,3);
	    } while (pos != std::string::npos);
	
	    do {
	        pos = m_Namespace.find("./");
	        if (pos != std::string::npos)
	            m_Namespace.erase(pos,2);
	    } while (pos != std::string::npos);
	
	    do {
	        pos = m_Namespace.find('/');
	        if (pos != std::string::npos)
	        {
	            m_Namespace.erase(pos,1);
	            m_Namespace.insert(pos,"::");
	        }
	    } while (pos != std::string::npos);
	}
//[EOF]
}

void doxyqml::CRootElement::setMemberState()
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "setMemberState", "", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_setMemberState/code.cpp]
	//~~ void setMemberState() [CRootElement] ~~
	state = 1;
//[EOF]
}

void doxyqml::CRootElement::setNamespace(const std::string& Namespace)
{
	NOTIFY_FUNCTION_CALL(this, 5, "CRootElement", "setNamespace", "const std::string& Namespace", "void ")
//[Package_doxyqml/Package_ast/classes/class_CRootElement/operations/operation_SYLDGZGK/code.cpp]
	//~~ void setNamespace(const std::string& Namespace) [CRootElement] ~~
	m_Namespace = Namespace;
	size_t pos;
	
	do {
	    pos = m_Namespace.find('.');
	    if (pos != std::string::npos)
	    {
	        m_Namespace.erase(pos,1);
	        m_Namespace.insert(pos,"::");
	    }
	} while (pos != std::string::npos);
//[EOF]
}

