/******************************************************************
 * This code was generated by the Astade CppGenerator.            *
 * The generated code is not per se a derivative work of Astade;  *
 * the original copyright to this code is held by the holder(s)   *
 * of the copyright to the underlying model at the time this code *
 * was generated; this code may be distributed under terms of     *
 * his/her/their choice.                                          */
/** the root of the abstract syntax tree
 *  @file CRootElement.h
 ******************************************************************/

#ifndef __CROOTELEMENT_H
#  define __CROOTELEMENT_H

//****** specification prolog ******
//[Package_doxyqml/Package_ast/classes/class_CRootElement/prolog.h]
#include <string>
//[EOF]
//**********************************

// Relation includes:
#include "CQmlObject.h"

// Relation forward declarations:
namespace doxyqml {
class CQmlObject;
} // namespace doxyqml

/** all doxyqml dependend classes
*/
namespace doxyqml {
/** the root of the abstract syntax tree
*/
class CRootElement : public CQmlObject
{

public:
/** used to add a child to the object
@param child the new child
*/
	virtual void addChild(CQmlObject* child);

/** construct from a text
*/
	CRootElement();

/** print the generated code to stdout
*/
	virtual void print() const;

/** accessor
@param baseClass the new base class
*/
	void setBaseClass(const std::string& baseClass);

/** accessor
@param filename the text of the element
*/
	void setFilename(const std::string& filename);

/** changes the object state
*/
	void setMemberState();


protected:
/** the member childs of the object
*/
	std::vector<CQmlObject*>	myMemberChilds;


private:
/** holds the filename of the root object
*/
	std::string	m_Filename;

/** holds the classname of the root object
*/
	std::string	m_Classname;

/** the name of the base class
*/
	std::string	m_BaseClass;

/** the parsing state:
0: top
1: members
*/
	unsigned int	state;

/** The class namespace
*/
	std::string	m_Namespace;

};
} // namespace doxyqml

#endif
