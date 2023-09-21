#include <iostream>
#include "BaseShape.h"

using namespace std;

class Circle : public BaseShape
{
private:
	const double pi = 3.14159;
	double centerX, centerY, radius;

public:
	// Constructor 
	Circle(double xInput, double yInput, double radiusInput)
	{
		centerX = xInput;
		centerY = yInput;
		radius = radiusInput;
	}

	double CalculateArea()
	{
		return (pi * radius * radius);
	}
};
