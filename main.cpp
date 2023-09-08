/*
Program Name: Factorial Overflow Project
Date: 09-08-2023
Author: Noah S Ferenczhalmy
Module Purpose
The program is to be designed to calculate factorials until an overflow is encountered using both a loop technique and recursive method. 
Inputs for the program are different allocations of memory.
*/

#include <chrono>
#include <limits>
#include <locale>

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
using namespace chrono;

template <class TypeMultiply>
bool isSafeMultiply (TypeMultiply mult01, TypeMultiply mult02, TypeMultiply &multResult) 
{

/*$$
add code to check if mult01 or mult02 = 0
if so, set multResult to 0 and leave with a true
*/
    if (mult01 == 0 || mult02 == 0)
    {
        multResult = 0;
        return true;
    }


/*$$
calculate the multResult from mult01 and mult02
check if mult01 is equal to the multResult divided by mult02
if it is equal then leave with a true
if not then leave with a false
*/
    multResult = mult01 * mult02;
    if (mult01 == (multResult/mult02))
    {
        return true;
    }
    else 
    {
        return false;
    }


}
template <class TypeMultiply>
void calculateTimeFactorialLoopFunc(void) 
{

  //$$ set time start to time now 
    auto timeStart = steady_clock::now();

    TypeMultiply    multiplier = 1,
                    factorialResult = 1,
                    multResult;

  /*$$ invoke isSafeMultiply with multiplier and factorialResult*/
    while (isSafeMultiply(multiplier, factorialResult, multResult)) 
    {
        // display the multiplier and the factorialresult using field wdths of 3 and 27 respectively
        // increment the multiplier
        factorialResult = multResult;

        cout << endl;
        cout << setw(3) << multiplier << setw(27) << factorialResult;

        multiplier++;
    }

  // calculate timeElapsed as described in the assignment
  auto timeElapsed = duration_cast<nanoseconds> (steady_clock::now() - timeStart);

  cout << endl;
  cout << "Unsigned overflow at : " << setw(15) << multiplier << endl;
  cout << "Time Elapsed (nano)  : " << setw(15) << timeElapsed.count() << endl;

}//calculateTimeFactorialLoopFunc

 //------------------------------------------
template <class TypeMultiply>
void factorialRecursiveFunc (TypeMultiply &multiplier, TypeMultiply factorialResult) 
{
  TypeMultiply multResult;

    /*$$ invoke isSafeMultiply <TypeMultiply> with multiplier and factorial result)*/
  if (isSafeMultiply(multiplier, factorialResult, multResult))
  {
      factorialResult = multResult;

      cout << setw(3) << multiplier << setw(27) << factorialResult << endl;
      factorialRecursiveFunc(++multiplier, factorialResult);
    //$$ invoke factorialRecursiveFunc with ++multiplier and factorialResult
  }
  return;
}//factorialRecursive

 //------------------------------------------  
template <class TypeMultiply>
void calculateTimeFactorialRecursiveFunc() 
{

  auto timeStart = steady_clock::now();

  TypeMultiply mult01 = 1;
  TypeMultiply multResult;

  factorialRecursiveFunc <TypeMultiply> (mult01, 1);

  auto timeElapsed = duration_cast<nanoseconds>(steady_clock::now() - timeStart);

  cout << endl;
  cout << "Unsigned overflow at : " << setw(15) << mult01 << endl;
  cout << "Time Elapsed (nano)  : " << setw(15) << timeElapsed.count() << endl;

}//calculateTimeFactorialRecursiveFunc()

template <typename TYPESIZE> 
class FactorialCalculationClass 
{

private:
  unsigned typeSizeBits;

public:
  // Constructor
  FactorialCalculationClass(unsigned typeSize) 
  {
    //$$ set typeSizeBits to typeSize;
      typeSizeBits = typeSize;
  }

  void executeFactorialForType() 
  {

    cout <<
      typeSizeBits <<
      " bit unsigned Factorial Loop" << endl <<
      "------------------------------" << endl;
    calculateTimeFactorialLoopFunc <TYPESIZE>();
    cout << endl << endl;

    cout <<
      typeSizeBits <<
      " bit unsigned Factorial Recursion" << endl <<
      "-----------------------------------" << endl;
    calculateTimeFactorialRecursiveFunc <TYPESIZE>();
    cout << endl << endl;

  }

};// template <class TYPESIZE> class factorialCalculationClass

int main() 
{
  // condition cout set to local digit separation comas (USA)
  cout.imbue(locale(""));

  /*$$
  create an object of FactorialCalculationClass <uintnn_t> called factorialCalculateUintnnObj(nn)
  where nn is the size in bits for the tempalte type uintnn_t, the object name factorialCalculateUintnnObj
  and the nn for the argument (nn) to the constructor
  nn must equal nn = 16, 32 and 64 to make the 3 objects
  */
  FactorialCalculationClass <uint16_t> factorialCalculateUint16Obj(16);
  FactorialCalculationClass <uint32_t> factorialCalculateUint32Obj(32);
  FactorialCalculationClass <uint64_t> factorialCalculateUint64Obj(64);

  /*$$
  for each of the 3 nn objects factorialCalculateUintnnObj
  invoke the executeFactorialForType()
  */
  factorialCalculateUint16Obj.executeFactorialForType();
  factorialCalculateUint32Obj.executeFactorialForType();
  factorialCalculateUint64Obj.executeFactorialForType();

  cout << "Press enter key once or twice to end"; cin.ignore(); cin.get();

  return 0;
}
