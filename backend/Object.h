#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include "Point.h"

class Object {
	private:
		std::vector <Point> points;
		
		void setPoint (Point point);
	public:
		Object ();
		
		Object (Point point);
		
		void setPoint (int n, Point point);

		void addPoint (Point point);
		
		Point getPoint ();
		
		Point getPoint (int n);
		
		std::vector <Point> getPoints ();

		virtual std::string toString ();
};

#endif