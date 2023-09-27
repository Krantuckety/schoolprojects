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
		if (radiusInput < 0) {
			string errorString = "radius is negative\n";
			throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
		}

		centerX = xInput;
		centerY = yInput;
		radius = radiusInput;
		calculateArea();
	}

	double calculateArea() override
	{
		BaseShape::setArea(pi * radius * radius);
		return BaseShape::getArea();
	}

	void display() override
	{
		cout << "Shape is a Circle :\n";
		cout << " Center X : " << centerX << "\n";
		cout << " Center Y : " << centerY << "\n";
		cout << " Radius   : " << radius << "\n";
		cout << " Area     : " << BaseShape::getArea() << "\n";
	}
};
