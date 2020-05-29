#ifndef _GEOMETRYPARSER_H_
#define _GEOMETRYPARSER_H_

#include "Object.h"
#include "Point.h"
#include "Circle.h"
#include "Line.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include <unordered_map>
#include <string>

class GeometryParser {
    private:
        std::unordered_map <std::string, Object*> objects;
        std::unordered_map <char, int> objectNum;

        std::vector <std::string> objectNames;
        std::vector <std::string> functionNames;

    public:
        GeometryParser ();

        // returns 1 for object, 0 for function, -1 for invalid string
        std::string identify (std::string s);

        std::unordered_map <std::string, Object*> parseToObject (std::string s);

};

#endif