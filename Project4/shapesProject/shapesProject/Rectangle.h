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
				errorString += "Width valueis negative\n";
			else if (lenInput < 0)
				errorString += "Length value is negative\n";
			throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
		}

		width = widInput;
		length = lenInput;
		setArea(calculateArea());
	}

	double calculateArea() override
	{
		return (width * length);
	}

	void display() override
	{
		cout << "Shape is a Rectangle :\n";
		cout << " Width  : " << width << "\n";
		cout << " Length : " << length << "\n";
		cout << " Area   : " << BaseShape::getArea() << "\n\n";
	}
};