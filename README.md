[![Build Status](https://travis-ci.org/agateau/doxyqml.svg?branch=master)](https://travis-ci.org/agateau/doxyqml)

# Goals

Doxyqml turns .qml into pseudo-C++ which Doxygen can then use to generate
documentation.

This project is a clone of the original python project https://github.com/agateau/doxyqml
It is intented to be compatible, but it is a complete redevelopment in C++

# Telling Doxygen to use Doxyqml

To tell Doxygen about Doxyqml you must make a few changes to your Doxygen file.

1. Add the .qml extension to the `FILTER_PATTERNS` key:

        FILTER_PATTERNS = *.qml=doxyqml

    Note: On Windows you may need to use the full path of the `doxyqml.py` file
    instead. For example if you installed Python 3.5 in `C:\Python35`, use this:

        FILTER_PATTERNS = *.qml=C:\Python35\Lib\site-packages\doxyqml\doxyqml.py

2. Add the .qml extension to `FILE_PATTERNS`:

        FILE_PATTERNS = *.qml

3. Since Doxygen 1.8.8, you must also add the .qml extension to
   `EXTENSION_MAPPING`:

        EXTENSION_MAPPING = qml=C++

# Documenting types

QML is partly-typed: functions are untyped, properties and signals are. Doxyqml
provides a way to define types when they are missing or not precise enough.

## Functions

Functions in QML are untyped, but you can define types in the documentation
like this:

    /**
     * Create a user
     * @param type:string firstname User firstname
     * @param type:string lastname User lastname
     * @param type:int User age
     * @return type:User The User object
     */
    function createUser(firstname, lastname, age);

## Properties

QML properties are typed, so Doxyqml uses them by default. You can nevertheless
overwrite the type using the same `type:<name>` syntax. This is useful to
document property aliases:

    /** type:string The user lastname */
    property alias lastname: someObject.text

## Signals

QML signals are typed, so there is no need to use the `type:<name>` syntax to
document their parameters. Using `type:<name>` syntax in signal documentation
will not work: Doxyqml won't strip it out and Doxygen will confuse it with the
parameter name.

    /**
     * User just logged in
     * @param user The user which logged in
     */
    signal loggedIn(User user)

### Useful Links

The official QML syntax is located here: http://code.qt.io/cgit/qt/qtdeclarative.git/tree/src/qml/parser/qqmljs.g

