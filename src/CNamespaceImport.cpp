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
/** an import with namespace
 *  @file CNamespaceImport.cpp
 ******************************************************************/

#include "CNamespaceImport.h"	 // own header



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

doxyqml::CNamespaceImport::CNamespaceImport(const std::string& filename, const std::string& namespaceName) :
	m_filename(filename),
	m_NamespaceName(namespaceName)
{
	NOTIFY_CONSTRUCTOR(5, "CNamespaceImport", "const std::string& filename, const std::string& namespaceName")
//[Package_doxyqml/Package_ast/classes/class_CNamespaceImport/operations/constructor/code.cpp]
	//~~ CNamespaceImport(const std::string& filename, const std::string& namespaceName) [CNamespaceImport] ~~
	size_t pos;
	
	do {
	    pos = m_filename.find("../");
	    if (pos != std::string::npos)
	        m_filename.erase(pos,3);
	} while (pos != std::string::npos);
	
	do {
	    pos = m_filename.find('/');
	    if (pos != std::string::npos)
	    {
	        m_filename.erase(pos,1);
	        m_filename.insert(pos,"::");
	    }
	} while (pos != std::string::npos);
//[EOF]
}

void doxyqml::CNamespaceImport::print() const
{
	NOTIFY_FUNCTION_CALL(this, 5, "CNamespaceImport", "print", "", "void ")
//[Package_doxyqml/Package_ast/classes/class_CNamespaceImport/operations/operation_print/code.cpp]
	//~~ void print() [CNamespaceImport] ~~
	printf("namespace %s = %s;\n",m_NamespaceName.c_str(),m_filename.c_str());
//[EOF]
}

