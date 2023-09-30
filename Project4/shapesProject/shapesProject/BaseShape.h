// This is the BaseShape Class File

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
	/*
	Name:              getArea
	Function Purpose : Returns the area variables value
	Function Design:   Return statement for the area variable
	Inputs:            None
	Outputs:           By function name, returns a double stored in the area variable.
	*/
	double getArea()
	{
		return area;
	}

	/*
	Name:              setArea
	Function Purpose : Sets the area value to the input
	Function Design:   Sets the area variable equal to the inputArea
	Inputs:            inputArea
	Outputs:           None
	*/
	void setArea(double inputArea)
	{
		area = inputArea;
	}

	// Virtual Method that is replaced in the dependent Rectangle & Circle Classes
	virtual double calculateArea()
	{
		return 0;
	}

	// Virtual Method that is replaced in the dependent Rectangle & Circle Classes
	virtual void display()
	{

	}
};

#endif