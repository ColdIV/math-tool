#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Object.h"

class Circle : virtual public Object {
	private:
		double radius;
	public:
		Circle ();
		
		Circle (Point point, double radius);
		
		void setRadius (double radius);
		
		double getRadius ();
};

#endif