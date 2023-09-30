/*
This is the Circle Class File
It is derived from the BaseShape Class
*/

#include <iostream>
#include "BaseShape.h"

using namespace std;

class Circle : public BaseShape
{
private:
	const double pi = 3.14159;
	double centerX, centerY, radius;

public:
	/*
	Name:              Circle
	Function Purpose : Constructs a Circle Object
	Function Design:   Runs a series error checks on the input values
					   Following the error checks, assigns the input values to their respective variables
	Inputs:            widInput, lenInput
	Outputs:           By function name, an object of the type "Rectangle"
	*/
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

	/*
	Name:              calculateArea
	Function Purpose : Calculates the area of the Circle.
	Function Design:   Multiplies the constant PI times the radius squared, then returns the output
					   not a negative amount
	Inputs:            None
	Outputs:           By function name an double that represents the area.
	*/
	double calculateArea() override
	{
		return (pi * radius * radius);
	}

	/*
	Name:              display
	Function Purpose : Displays all attributes of the Circle
	Function Design:   Runs a series of cout statements,
					   lists the attribute and the value of it on different lines
	Inputs:            None
	Outputs:           By function name a series of text-lines listing the attributes
	*/
	void display() override
	{
		cout << "Shape is a Circle :\n";
		cout << " Center X : " << centerX << "\n";
		cout << " Center Y : " << centerY << "\n";
		cout << " Radius   : " << radius << "\n";
		cout << " Area     : " << BaseShape::getArea() << "\n\n";
	}
};
