#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "LineInfo.h"

using namespace std;

int inputShapeChoice;
int shapeCount;

//Variables used for constructing a shape of type "Circle"
double x, y, radius;
//Variables used for constructing a shape of type "Rectangle"
double width, length;

const int MAX_NUMBER_SHAPES = 3;

int main()
{
    int inputShapeChoice;
    int shapeCount = 0;

    //Variables used for constructing a shape of type "Circle"
    double x;
    double y;
    double radius;
    //Variables used for constructing a shape of type "Rectangle"
    double width, length;

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
                case 1:
                    cout << "Enter the Circles Radius, X value and Y Value : "; cin >> radius >> x >> y;




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

                case 2:
                    cout << "Enter the Rectangles Width and Length : ";
                    cin >> width >> length;

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

                default:
                    cout << "Wrong menu value : " << inputShapeChoice << "\n";
                    cout << "Please try a different value" << "\n\n";
            }
        } while (shapeCount < MAX_NUMBER_SHAPES);

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