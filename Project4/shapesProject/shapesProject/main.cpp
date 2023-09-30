/*
Program Name: Shapes Project
Date: 2023-09-29
Author: Noah S. Ferenczhalmy
Module Purpose
This program is a program simulating shapes being created.
One can create up to 3 circles or rectangles. 
After 3 have been created, the program will show the attributes of all 3 shapes.
*/

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "LineInfo.h"

using namespace std;

int main()
{
    int inputShapeChoice;
    int shapeCount = 0;

    // Variables used for constructing a shape of type "Circle"
    double x;
    double y;
    double radius;
    // Variables used for constructing a shape of type "Rectangle"
    double width, length;

    // Constant
    const int MAX_NUMBER_SHAPES = 3;

    BaseShape** shapeArray = new BaseShape * [MAX_NUMBER_SHAPES];

    cout << "Choose 3 shapes and enter in applicable attributes, " << endl
        << "Once a third shape has been entered, the calculated results for all 3 shapes will display";

    try
    {
        do
        {
            cout << "Choose your shape : " << "\n\n";

            cout << "1: Circle" << "\n\n";
            cout << "2: Rectangle" << "\n\n";

            cout << "Enter your choice : ";
            cin >> inputShapeChoice;
            cout << "\n";

            switch (inputShapeChoice)
            {
                // Switch case for if a shape of type "Circle" is chosen.
                case 1:
                    cout << "Enter the Circles Radius, X value and Y Value : "; 
                    cin >> radius >> x >> y;

                    // Checks that none of the input values are negative
                    if ((x < 0) || (y < 0) || (radius < 0))
                    {
                        string errorString = "";
                        if (radius < 0)
                            errorString += "Radius is negative\n";
                        if (x < 0)
                            errorString += "Center X value is negative\n";
                        if (y < 0)
                            errorString += "Center Y value is negative\n";
                        throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
                    }
                    cout << "\n";
                    shapeArray[shapeCount] = new Circle(x, y, radius);
                    shapeCount++;
                break;

                // Switch case for if a shape of type "Rectangle" is chosen.
                case 2:
                    cout << "Enter the Rectangles Width and Length : ";
                    cin >> width >> length;

                    // Checks that none of the input values are negative
                    if (width < 0 || length < 0)
                    {
                        string errorString = "";
                        if (width < 0)
                            errorString += "Width valueis negative\n";
                        else if (length < 0)
                            errorString += "Length value is negative\n";
                        throw domain_error(LineInfo(errorString, __FILE__, __LINE__));
                    }
                    cout << "\n";
                    shapeArray[shapeCount] = new Rectangle(width, length);
                    shapeCount++;
                break;

                // Switch Case if the user did not choose the values "1" or "2"
                default:
                    cout << "Wrong menu value : " << inputShapeChoice << "\n";
                    cout << "Please try a different value" << "\n\n";
            }
        } while (shapeCount < MAX_NUMBER_SHAPES); // Loops if there are less than 3 shapes constructed.

        // Loops through all objects in the shapeArray and runs the display method on them to 
        for (int shapeArrayIndex = 0; shapeArrayIndex < MAX_NUMBER_SHAPES; shapeArrayIndex++)
            shapeArray[shapeArrayIndex]->display();
    }//try
    
    catch (exception& e) {
        cout << e.what() << endl;
        cout << endl << "Press the enter key once or twice to leave..." << endl;
        cin.ignore(); cin.get();
        exit(EXIT_FAILURE);
    }//catch

}//end of main