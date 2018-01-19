/******************************************************************
 * This code was generated by the Astade CppGenerator.            *
 * The generated code is not per se a derivative work of Astade;  *
 * the original copyright to this code is held by the holder(s)   *
 * of the copyright to the underlying model at the time this code *
 * was generated; this code may be distributed under terms of     *
 * his/her/their choice.                                          */
/** a declared object
 *  @file CObjectDeclaration.h
 ******************************************************************/

#ifndef __COBJECTDECLARATION_H
#  define __COBJECTDECLARATION_H

//****** specification prolog ******
//[Package_doxyqml/Package_ast/classes/class_CObjectDeclaration/prolog.h]
#include <string>
//[EOF]
//**********************************

// Relation includes:
#include "CQmlObject.h"


/** all doxyqml dependend classes
*/
namespace doxyqml {
/** a declared object
*/
class CObjectDeclaration : public CQmlObject
{

public:
/** construct from a text
@param filename the text of the element
*/
	CObjectDeclaration(const std::string& filename);

/** print the generated code to stdout
*/
	virtual void print() const;

/** accessor
@param baseClass the new base class
*/
	void setBaseClass(const std::string& baseClass);


protected:

private:
/** the name of the base class
*/
	std::string	m_BaseClass;

};
} // namespace doxyqml

#endif
