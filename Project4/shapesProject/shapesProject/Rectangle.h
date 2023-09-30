/*
This is the Rectangle Class File
It is derived from the BaseShape Class
*/ 


#include <iostream>
#include "BaseShape.h"

using namespace std;

class Rectangle : public BaseShape
{
private:
	double width, length;

public:
	/*
	Name:              Rectangle
	Function Purpose : Constructs a Rectangle Object
	Function Design:   Runs a series error checks on the input values
					   Following the error checks, assigns the input values to their respective variables
	Inputs:            widInput, lenInput
	Outputs:           By function name, an object of the type "Rectangle"
	*/
	Rectangle(double widInput, double lenInput)
	{
		if (widInput < 0 || lenInput < 0) {
			string errorString = "";
			if (widInput < 0)
				errorString += "Width valueis negative\n";
			else if (lenInput < 0)
				errorString += "Length value is negative\n";
			throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
		}

		width = widInput;
		length = lenInput;
		setArea(calculateArea());
	}

	/*
	Name:              calculateArea
	Function Purpose : Calculates the area of the Rectangle.
	Function Design:   Multiplies the width and length variables together, then returns the output
					   not a negative amount
	Inputs:            None
	Outputs:           By function name an double that represents the area.
	*/
	double calculateArea() override
	{
		return (width * length);
	}

	/*
	Name:              display
	Function Purpose : Displays all attributes of the Rectangle
	Function Design:   Runs a series of cout statements,
					   lists the attribute and the value of it on different lines
	Inputs:            None
	Outputs:           By function name a series of text-lines listing the attributes
	*/
	void display() override
	{
		cout << "Shape is a Rectangle :\n";
		cout << " Width  : " << width << "\n";
		cout << " Length : " << length << "\n";
		cout << " Area   : " << BaseShape::getArea() << "\n\n";
	}
};