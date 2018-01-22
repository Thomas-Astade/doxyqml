/******************************************************************
 * This code was generated by the Astade CppGenerator.            *
 * The generated code is not per se a derivative work of Astade;  *
 * the original copyright to this code is held by the holder(s)   *
 * of the copyright to the underlying model at the time this code *
 * was generated; this code may be distributed under terms of     *
 * his/her/their choice.                                          */
/** base class for QML objects
 *  @file CQmlObject.h
 ******************************************************************/

#ifndef __CQMLOBJECT_H
#  define __CQMLOBJECT_H

//****** specification prolog ******
//[Package_doxyqml/Package_ast/classes/class_CQmlObject/prolog.h]
#include <vector>
#include <string>
//[EOF]
//**********************************



/** all doxyqml dependend classes
*/
namespace doxyqml {
/** base class for QML objects
*/
class CQmlObject
{

public:
/** used to add a child to the object
@param child the new child
*/
	virtual void addChild(CQmlObject* child);

/** print the generated code to stdout
*/
	virtual void print() const = 0;

/** helper function tpo trimm a string
@param s the sring to trim
*/
	const std::string trim(const std::string& s);


protected:
/** the childs of the object
*/
	std::vector<CQmlObject*>	myChilds;


private:
};
} // namespace doxyqml

#endif
