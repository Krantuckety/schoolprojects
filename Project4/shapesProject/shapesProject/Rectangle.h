#include <iostream>
#include "BaseShape.h"

using namespace std;

class Rectangle : public BaseShape
{
private:
	double width, length;

public:
	// Constructor
	Rectangle(double widInput, double lenInput)
	{
		if (widInput < 0 || lenInput < 0) {
			string errorString = "";
			if (widInput < 0)
				errorString += "width is negative\n";
			if (lenInput < 0)
				errorString += "length is negative\n";
			throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
		}

		width = widInput;
		length = lenInput;
		calculateArea();
	}

	double calculateArea() override
	{
		BaseShape::setArea(width * length);
		return BaseShape::getArea();
	}

	void display() override
	{
		cout << "Shape is a Rectangle :\n";
		cout << " Width  : " << width << "\n";
		cout << " Length : " << length << "\n";
		cout << " Area   : " << BaseShape::getArea() << "\n";
	}
};