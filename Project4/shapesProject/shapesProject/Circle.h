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
		if (radiusInput < 0 || xInput < 0 || yInput < 0) 
		{
			string errorString = "";
			if (radiusInput < 0)
				errorString += "radius is negative\n";
			else if (xInput < 0)
				errorString += "Center X value is negative\n";
			else if (yInput < 0)
				errorString += "Center Y value is negative\n";
			throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
		}

		centerX = xInput;
		centerY = yInput;
		radius = radiusInput;
		setArea(calculateArea());
	}

	double calculateArea() override
	{
		return (pi * radius * radius);
	}

	void display() override
	{
		cout << "Shape is a Circle :\n";
		cout << " Center X : " << centerX << "\n";
		cout << " Center Y : " << centerY << "\n";
		cout << " Radius   : " << radius << "\n";
		cout << " Area     : " << BaseShape::getArea() << "\n\n";
	}
};
