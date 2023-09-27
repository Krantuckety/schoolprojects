#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

int main()
{
    try
    {
        Circle testCircle = Circle(0, 0, 5);
        testCircle.display();
        //Rectangle testRectangle = Rectangle(2, 3);
        //testRectangle.display();
    }
    
    catch (exception& e) {
        cout << e.what() << endl;
        cout << endl << "Press the enter key once or twice to leave..." << endl;
        cin.ignore(); cin.get();
        exit(EXIT_FAILURE);
    }//catch

}