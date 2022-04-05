// The name of the program: Part 2 of Lab 3.
// This program is derived from the programming example: polynomial operations in Data Structure Using C++ by author D.S. Malik. It is then written by Saurav Pandey (pandey1@kenyon.edu) and Lucas (Yiyang) Lu (lu1@kenyon.edu). We contributed about equally to the development of the program and we followed the guidelines for Pair Programming.
// This program asks users to enter two polynomials and calculates the addition, subtraction, multiplication, and derivative of the two functions.



#include <iostream>
#include "polynomialType.h"
using namespace std;


int main()
{ 
  int size1,size2,real,imag,again=1, choice;
  // This while loop allows users to run the program again if they want to.
  while (again==1){
    cout << "Complex numbers are in the form (a + bi). a is the real part and b is the imaginary part of the complex number" << endl << endl;
    cout << "Enter the size (number of terms) in your first polynomial: ";
    cin >> size1;

    // This part of the program asks users to re-enter if the size of the first polynomial is less or equal to 0.
    while (size1<=0){
      cout << "The size should be positive. Please re-enter: ";
      cin >> size1;
    }

    // declaring the first polynomial
    polynomialType p(size1);
    polynomialType add, subtract1, subtract2, derivative;
    cin >> p;
    cout << endl << "First polynomial p(x): " << p << endl;
    cout << endl << "Enter the size (number of terms) in your second polynomial: ";
    cin >> size2;

    // This part of the program asks users to re-enter if the size of the second polynomial is less or equal to 0.
    while (size2<=0){
      cout << "The size should be positive. Please re-enter: ";
      cin >> size2;
    }
    
    // declaring the second polynomial
    polynomialType q(size2);
    cin >> q;
    cout << endl << "Second polynomial q(x): " << q << endl;
    
    // After the user entered the two polynomials, this part of the program performs all the possible operations (addition, subtraction, multiplication, and derivative).
    add = p+q;
    subtract1 = p-q;
    subtract2 = q-p;
    cout << endl;
    cout << "------------------------------------------" <<endl<<endl;
    cout << "First polynomial p(x) = " << p << endl;
    cout << "Second polynomial q(x) = " << q << endl;
    cout << endl;
    cout << "p(x) + q(x): " << add << endl;
    cout << "p(x) - q(x): " << subtract1 << endl;
    cout << "q(x) - p(x): " << subtract2 << endl;
    cout << "p(x) * q(x): " << p*q << endl;
    cout << "The derivative of p(x): " << ~p <<endl;
    cout << "The derivative of q(x): " << ~q <<endl<<endl;
    
    cout << "------------------------------------------" << endl << endl;

    cout << "*** Evaluating first polynomial p(x) *** "<<endl;
    cout << endl << "p(x) = " << p << endl;
    cout << endl << "Enter the real value (a) of the complex number (a + bi) you want to evaluate p(x) at: ";
    cin >> real;
    cout << "Enter the imaginary value (b) of the complex number (a + bi) you want to evaluate p(x) at: ";
    cin >> imag;
    p(real,imag); //passing real and imaginary values to evaluate p(x) through operator overloading

    cout << endl<< "*** Evaluating second polynomial q(x) *** "<<endl;
    cout << endl << "q(x) = " << q << endl;
    cout << endl << "Enter the real value (a) of the complex number (a + bi) you want to evaluate q(x) at: ";
    cin >> real;
    cout << "Enter the imaginary value (b) of the complex number (a + bi) you want to evaluate q(x) at: ";
    cin >> imag;
    q(real,imag);// passing real and imaginary values to evaluate q(x) through operator overloading

    // This part of the program asks users if they want to try again.
    cout << endl << "Thank you for using our polynomial calculator. Would you like to use it again?" << endl;
    cout << "Enter 1 to continue. Enter any other number to exit: ";
    cin >> again;
    cout << endl << endl << "---------------------------------------------------" << endl << endl << endl;
  }
  return 0;
}