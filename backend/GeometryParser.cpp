#include "GeometryParser.h"
#include <iostream>

GeometryParser::GeometryParser () {
    this->objectNames = {"point", "circle", "line", "triangle", "square", "rectangle"};
    this->functionNames = {"angle", "intersection"};
}

std::string GeometryParser::identify (std::string s) {
    // check for object
    for (int i = 0; i < this->objectNames.size(); ++i) {
        std::size_t found = s.find(this->objectNames[i]);

        if (found != std::string::npos) {
            return this->objectNames[i];
        }
    }

    // check for function
    for (int i = 0; i < this->functionNames.size(); ++i) {
        std::size_t found = s.find(this->functionNames[i]);

        if (found != std::string::npos) {
            return this->functionNames[i];
        }
    }

    return "";
}

std::unordered_map <std::string, Object*> GeometryParser::parseObject (std::string s) {
    std::string objName = "";
    int objParams = 0;

    // find the object
    for (int i = 0; i < this->objectNames.size(); ++i) {
        std::size_t found = s.find(this->objectNames[i]);

        if (found != std::string::npos) {
            objName = this->objectNames[i];
            objParams = (int)found + objName.length();
            break;
        }
    }

    // if objParams > 0, we found an object to work with
    if (objParams) {
        // find all numbers
        int sign = 1;
        std::vector <double> numbers (0);
        
        for (int i = objParams; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                // found number
                if (s[i] - 1 == '-') {
                    sign = -1;
                }

                double tmpNumber = std::stod(s.substr(i));
                tmpNumber *= sign;
                numbers.push_back(tmpNumber);

                size_t cPos = s.substr(i).find(",");
                size_t pPos = s.substr(i).find("|");
                size_t pos;

                if (cPos == std::string::npos && pPos == std::string::npos) break;
                if (cPos == std::string::npos) pos = pPos;
                else if (pPos == std::string::npos) pos = cPos;
                else pos = std::min(cPos, pPos);

                i += pos;
            }
        }

        // create object and add to map
        if (objName == "point" || objName == "Point") {
            if (numbers.size() == 2) {
                Circle *tmp = new Circle(Point (numbers[0], numbers[1]), 1);
                this->objects["P" + std::to_string(++this->objectNum['P'])] = tmp;
            }
        } else if (objName == "circle" || objName == "Circle") {
            if (numbers.size() == 3) {
                Circle *tmp = new Circle(Point (numbers[0], numbers[1]), numbers[3]);
                this->objects["C" + std::to_string(++this->objectNum['C'])] = tmp;
            }
        } else if (objName == "line" || objName == "Line") {
            if (numbers.size() == 4) {
                Line *tmp = new Line(Point (numbers[0], numbers[1]), Point (numbers[2], numbers[3]));
                this->objects["L" + std::to_string(++this->objectNum['L'])] = tmp;
            }
        } else if (objName == "triangle" || objName == "Triangle") {
            if (numbers.size() == 6) {
                Triangle *tmp = new Triangle(Point (numbers[0], numbers[1]), Point (numbers[2], numbers[3]), Point (numbers[4], numbers[5]));
                this->objects["T" + std::to_string(++this->objectNum['T'])] = tmp;
            }
        } else if (objName == "square" || objName == "Square") {
            if (numbers.size() == 4) {
                Square *tmp = new Square(Point (numbers[0], numbers[1]), Point (numbers[2], numbers[3]));
                this->objects["S" + std::to_string(++this->objectNum['S'])] = tmp;
            }
        } else if (objName == "rectangle" || objName == "Rectangle") {
            if (numbers.size() == 8) {
                Rectangle *tmp = new Rectangle(Point (numbers[0], numbers[1]), Point (numbers[2], numbers[3]), Point (numbers[4], numbers[5]), Point (numbers[6], numbers[7]));
                this->objects["R" + std::to_string(++this->objectNum['R'])] = tmp;
            }
        }
    }

    // return map of objects
    return this->objects;
}

std::vector <Object*> GeometryParser::parseParameters (std::string s) {
    std::vector <Object*> vec (0);

    for (auto p : this->objects) {
        size_t pos = s.find(p.first);
        if (pos != std::string::npos) {
            vec.push_back(p.second);
        }
    }

    // if only one object in vector, duplicate it
    if (vec.size() == 1) vec.push_back(vec[0]);

    return vec;
}