#ifndef H_polynomial
#define	H_polynomial
#include <iostream>
using namespace std;

class polynomialType
{
  friend ostream& operator<<(ostream&, const polynomialType&); // Overloads the stream insertion operator
  
  friend istream& operator>>(istream&, polynomialType&); // Overloads the stream extraction operator

  public:
    polynomialType operator+(const polynomialType&); // Overloads the operator +
    
    polynomialType operator-(const polynomialType&); // Overloads the operator -
    
    polynomialType operator*(const polynomialType&); // Overloads the operator *

    polynomialType operator~(); // Overloads the operator ~

    void operator() (double realNum, double imagNum); // Overloads the operator () to evaluate the polynomial at a given point Postcondition: The value of the polynomial at x is calculated and returned

    polynomialType(int size = 100); // constructor

    int min(int x, int y) const; // Function to return the smaller of x and y
    
    int max(int x, int y) const; // Function to return the larger of x and y

  protected:
    double *real; // array to hold the real parts of the complex numbers
    double *imaginary; // array to hold the imaginary parts of the complex numbers
    int length; // to store the length of the list, the length of the list of real parts is the same as the length of the list of imaginary part
    int maxSize; // to store the maximum size of the list
};


#endif