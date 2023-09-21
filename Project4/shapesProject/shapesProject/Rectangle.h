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
		width = widInput;
		length = lenInput;
	}

	double CalculateArea()
	{
		return (width * length);
	}
};