/*
Program Name: Vertical Matrix Project
Date: 9/15/2023
Author: Noah S Ferenczhalmy
Module Purpose
This program reads matrixes from a file and creates a matrix in the program from what it reads. 
The program then displays the matrixes it read as well as the sums of all columns within the matrix and checks whether the columns possess vertical symmetry.
The program will then sort each row in ascending order from left to right. 
After all functions are completed, it will prompt the user have it read the next matrix and perform the same functions until all matrixes within the file have been read.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constant containing the maximum size for a Matrix.
const unsigned MAX_MATRIX_SIZE   = 20;
const unsigned WIDTH_DISPLAY     = 12;

bool    readMatrixFromFile (int [][MAX_MATRIX_SIZE], unsigned&, unsigned&, ifstream&);
void         displayMatrix (int [][MAX_MATRIX_SIZE], unsigned,  unsigned);
void displayCalcMatrixSums (int [][MAX_MATRIX_SIZE], unsigned,  unsigned,  int[MAX_MATRIX_SIZE]);
void   symmetryCheckMatrix (int [], unsigned,  unsigned);
void        sortMatrixRows (int [][MAX_MATRIX_SIZE], unsigned,  unsigned);


int main() {
  unsigned height,
           width;
  int      matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE],
           colSums[MAX_MATRIX_SIZE];
  string   INPUT_FILE_NAME = "matrixes.txt";
  ifstream inputFileStreamObj(INPUT_FILE_NAME);

  if (inputFileStreamObj.fail()) {
     cout << "File " << INPUT_FILE_NAME << "could not be opened !" << endl; 
     cout << endl << "Press the enter key once or twice to leave..." << endl; cin.ignore(); cin.get();
     exit(EXIT_FAILURE); 
   }

   do {  

     if (readMatrixFromFile(matrix, height, width, inputFileStreamObj) )
       break;

     cout << "Input:" << endl;
     displayMatrix        (matrix, height, width);
     displayCalcMatrixSums(matrix, height, width, colSums);
     symmetryCheckMatrix  (colSums, width, height);
     sortMatrixRows       (matrix,  width, height);
     cout << "Sorted:" << endl;
     displayMatrix        (matrix, height, width);

     cout << endl << "Press the enter key once or twice to continue..." << endl; cin.ignore(); cin.get(); 
     
   } while (true);

   cout << "Program Done" << endl;

   exit(EXIT_SUCCESS);
}

// The readMatrixFromFile method checks if there is a valid height and width inputed in the file it is reading from.
// If the height and width are valid, then a nested for loop runs through as many columns as the "height" variable says there are and as many rows as the "width" variable says there is.
// All values are then stored in the same order then were in the original file inside of a matrix.
bool readMatrixFromFile(int matrix[][MAX_MATRIX_SIZE], unsigned& height, unsigned& width, ifstream& inputFileStreamObj) 
{
    if (!(inputFileStreamObj >> height))
        return true;
    inputFileStreamObj >> width;

    for (unsigned row = 0; row < height; row++)
        for (unsigned col = 0; col <  width; col++)
            inputFileStreamObj >> matrix[row][col];
        return(false);
}

// The displayMatrix method uses a nested for loop to go through every value in an matrix that fits between the given height and width values. Then, it display them as they were in the matrixes.txt file
void displayMatrix(int matrix[][MAX_MATRIX_SIZE], unsigned height, unsigned width) {
    for (unsigned row = 0; row < height; row++)
    {
        for (unsigned col = 0; col < width; col++)
        {
            cout << setw(WIDTH_DISPLAY) << matrix[row][col];
        }
        cout << "\n";
    }
    cout << endl;
}

// The displayCalcMatrixSums method uses a nested for loop to filter through every row that has a value in a column. 
// Once it has gotten the sum of all values in the column, it will output the sum and move to the next column until all columns sums have been added together.
void displayCalcMatrixSums(int matrix[][MAX_MATRIX_SIZE], unsigned height, unsigned width, int colSums[MAX_MATRIX_SIZE]) 
{
    for (unsigned col = 0; col < width; col++)
    {
        colSums[col] = 0;
        for (unsigned row = 0; row < height; row++)
        {
            // It will collect the value of each row in the column and add them together.
            colSums[col] += matrix[row][col];
            
        }
        cout << setw(WIDTH_DISPLAY) << colSums[col];
    }
    cout << endl;
 }
 
// The symetryCheckMatrix method uses a for loop to compare columns on opposite ends of the matrix that are the same distance away from the minimum and maximum width respectively.
// The local variable "symmetryCheck" stores a boolean value for if 2 columns are vertically symmetric. If it ever outputs false, the for loop is exited.
// If the for loop exits at the original condition of "posS <= posE", then the matrix is vertically symmetric. If it exits earlier, it is declared not vertically symmetric.
void symmetryCheckMatrix(int colSums[], unsigned width, unsigned height) {
    bool symmetryCheck = false;
    for (unsigned posS = 0, posE = width - 1; posS <= posE; posS++, posE--)
    {
        symmetryCheck = (colSums[posS] == colSums[posE]);
        if (!symmetryCheck)
            break;
    }
    if (symmetryCheck)
        cout << "\nThis Matrix is Vertically Symmetric.\n\n";
    else
        cout << "\nThis matrix is not Vertically Symmetric.\n\n";
}

// The sortMatrixRows method used a for loop to filter through every value in a matrix.
// Within each row, it compares a value starting from the value in position 1 to the value before it. 
// If the previous value is greater than the current value being examined, then they are swapped and the row is checked from the position at value 1 again.
// The method ends once all rows have been sorted.
void sortMatrixRows(int matrix[][MAX_MATRIX_SIZE], unsigned width, unsigned height) {
    unsigned colStore;
    for (unsigned row = 0; row < height; row++)
    {
        for (unsigned col = 1; col < width;)
        {
            if (matrix[row][col - 1] > matrix[row][col])
            {
                colStore = matrix[row][col];
                matrix[row][col] = matrix[row][col - 1];
                matrix[row][col - 1] = colStore;
                col = 1;
            }
            else
                col++;
        }
    }

 }
