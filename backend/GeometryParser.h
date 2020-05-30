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

        // returns name of object / function if it's valid
        std::string identify (std::string s);

        std::unordered_map <std::string, Object*> parseObject (std::string s);

        std::vector <Object*> parseParameters (std::string s);

};

#endif