#ifndef BaseShape_HEADER
#define BaseShape_HEADER

#include <iostream>
#include "LineInfo.h"

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

	virtual double calculateArea()
	{
		return 0;
	}

	virtual void display()
	{

	}
};

#endif