// Put in a prologue

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

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


void displayMatrix(int matrix[][MAX_MATRIX_SIZE], unsigned height, unsigned width) {
    for (unsigned row = 0; row < height; row++)
    {
        for (unsigned col = 0; col < width; col++)
        {
            cout << setw(WIDTH_DISPLAY) << matrix[row][col];
        }
        cout << "\n";
    }
    // cout << endl;
}


void displayCalcMatrixSums(int matrix[][MAX_MATRIX_SIZE], unsigned height, unsigned width, int colSums[MAX_MATRIX_SIZE]) 
{
    for (unsigned col = 0; col < width; col++)
    {
        colSums[col] = 0;
        for (unsigned row = 0; row < height; row++)
        {
            colSums[col] += matrix[row][col];
            
        }
        cout << setw(WIDTH_DISPLAY) << colSums[col];
        //cout << "\n";
    }
    cout << endl;
 }
 

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
