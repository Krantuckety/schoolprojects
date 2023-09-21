#ifndef BaseShape_HEADER
#define BaseShape_HEADER

#include <iostream>

using namespace std;

class BaseShape
{
private:
	double area;

public:
	double getArea()
	{
		return area;
	}

	void setArea(double inputArea)
	{
		area = inputArea;
	}

	virtual void calculateArea()
	{

	}
};

#endif