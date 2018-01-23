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
/** a single line comment
 *  @file CSinglelineComment.cpp
 ******************************************************************/

#include "CSinglelineComment.h"	 // own header



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

doxyqml::CSinglelineComment::CSinglelineComment(const std::string& comment) :
	m_CommentText(comment)
{
	NOTIFY_CONSTRUCTOR(5, "CSinglelineComment", "const std::string& comment")
//[Package_doxyqml/Package_ast/classes/class_CSinglelineComment/operations/constructor/code.cpp]
	//~~ CRootElement(const std::string& filename) [CRootElement] ~~
//[EOF]
}

void doxyqml::CSinglelineComment::print() const
{
	NOTIFY_FUNCTION_CALL(this, 5, "CSinglelineComment", "print", "", "void ")
//[Package_doxyqml/Package_ast/classes/class_CSinglelineComment/operations/operation_print/code.cpp]
	//~~ void print() [CSinglelineComment] ~~
	printf("//%s\n",m_CommentText.c_str());
//[EOF]
}

