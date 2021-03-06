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
/** a signal
 *  @file CSignal.h
 ******************************************************************/

#ifndef __CSIGNAL_H
#  define __CSIGNAL_H

//****** specification prolog ******
//[Package_doxyqml/Package_ast/classes/class_CSignal/prolog.h]
#include <string>
//[EOF]
//**********************************

// Relation includes:
#include "CQmlObject.h"


/** @brief all doxyqml dependend classes
*/
namespace doxyqml {
/** @brief a signal
*/
class CSignal : public CQmlObject
{

public:
/** @brief construct from a text
@param comment the text of the element
@param internal this property is internal
*/
	CSignal(const std::string& comment, bool internal);

/** @brief print the generated code to stdout
@param hasComment info, if there is already comment for that object
*/
	virtual void print(bool hasComment) const;


protected:

private:
/** @brief the text of the comment
*/
	std::string	m_CommentText;

/** @brief is the property only internal?
*/
	bool	m_internal;

};
} // namespace doxyqml

#endif
