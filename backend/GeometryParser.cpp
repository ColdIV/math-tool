#include "GeometryParser.h"
#include <iostream>

GeometryParser::GeometryParser () {
    this->objectNames = {"point", "circle", "line", "triangle", "square", "rectangle", "punkt", "kreis", "linie", "dreieck", "quadrat", "rechteck"};
    this->functionNames = {"angle", "intersection", "winkel", "schnittpunkt"};

    // add translations
    // objects
    this->nameTranslations["point"] = "point";
    this->nameTranslations["punkt"] = "point";
    this->nameTranslations["circle"] = "circle";
    this->nameTranslations["kreis"] = "circle";
    this->nameTranslations["line"] = "line";
    this->nameTranslations["linie"] = "line";
    this->nameTranslations["triangle"] = "triangle";
    this->nameTranslations["dreieck"] = "triangle";
    this->nameTranslations["square"] = "square";
    this->nameTranslations["quadrat"] = "square";
    this->nameTranslations["rectangle"] = "rectangle";
    this->nameTranslations["rechteck"] = "rectangle";

    // functions
    this->nameTranslations["angle"] = "angle";
    this->nameTranslations["winkel"] = "angle";
    this->nameTranslations["intersection"] = "intersection";
    this->nameTranslations["schnittpunkt"] = "intersection";
}

std::string GeometryParser::identify (std::string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // check for object
    for (int i = 0; i < this->objectNames.size(); ++i) {
        std::size_t found = s.find(this->objectNames[i]);

        if (found != std::string::npos) {
            return this->nameTranslations[this->objectNames[i]];
        }
    }

    // check for function
    for (int i = 0; i < this->functionNames.size(); ++i) {
        std::size_t found = s.find(this->functionNames[i]);

        if (found != std::string::npos) {
            return this->nameTranslations[this->functionNames[i]];
        }
    }

    return "";
}

std::unordered_map <std::string, Object*> GeometryParser::parseObject (std::string s) {
    std::string objName = "";
    int objParams = 0;
    std::string sLower = s;
    transform(sLower.begin(), sLower.end(), sLower.begin(), ::tolower);

    // find the object
    for (int i = 0; i < this->objectNames.size(); ++i) {
        std::size_t found = sLower.find(this->objectNames[i]);

        if (found != std::string::npos) {
            objName = this->objectNames[i];
            objParams = (int)found + objName.length();
            objName = this->nameTranslations[objName];
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
                if (s[i - 1] == '-') {
                    sign = -1;
                }

                double tmpNumber = std::stod(s.substr(i));
                tmpNumber *= sign;
                sign = 1;
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
        if (objName == "point") {
            if (numbers.size() == 2) {
                Circle *tmp = new Circle(Point (numbers[0], numbers[1]), 5);
                this->objects["P" + std::to_string(++this->objectNum['P'])] = tmp;
            }
        } else if (objName == "circle") {
            if (numbers.size() == 3) {
                Circle *tmp = new Circle(Point (numbers[0], numbers[1]), numbers[2]);
                this->objects["C" + std::to_string(++this->objectNum['C'])] = tmp;
            }
        } else if (objName == "line") {
            if (numbers.size() == 4) {
                Line *tmp = new Line(Point (numbers[0], numbers[1]), Point (numbers[2], numbers[3]));
                this->objects["L" + std::to_string(++this->objectNum['L'])] = tmp;
            }
        } else if (objName == "triangle") {
            if (numbers.size() == 6) {
                Triangle *tmp = new Triangle(Point (numbers[0], numbers[1]), Point (numbers[2], numbers[3]), Point (numbers[4], numbers[5]));
                this->objects["T" + std::to_string(++this->objectNum['T'])] = tmp;
            }
        } else if (objName == "square") {
            if (numbers.size() == 4) {
                Square *tmp = new Square(Point (numbers[0], numbers[1]), Point (numbers[2], numbers[3]));
                this->objects["S" + std::to_string(++this->objectNum['S'])] = tmp;
            }
        } else if (objName == "rectangle") {
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
