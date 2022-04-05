#include "polynomialType.h"
#include <cmath>
#include <iostream>
using namespace std;

// The comments for these methods are included in the header file. 

polynomialType::polynomialType(int size) 
{ 
  length = size;
  real=new double[length];
  imaginary=new double[length];
  for (int i = 0; i < size; i++){
      imaginary[i]=0;
      real[i]=0;
  }
}


void polynomialType::operator () (double realNum, double imagNum)
{
  double realSum=0,ImagSum=0,x,y,tempx;
  int index;
  polynomialType temp;
  
  for (int i = 0; i < length; i++)
  { 
    x=real[i];
    y=imaginary[i];
    tempx=real[i];
    index=0;
    while (index<i){
      tempx=x;
      x=(x*realNum) - (y*imagNum);
      y=(tempx*imagNum) + (y*realNum);
      index++;
    }
    realSum=realSum+x;
    ImagSum=ImagSum+y;
  }
  if (ImagSum<0){
    ImagSum=-1*ImagSum;
    cout << endl << "The value of the polynomial is " << realSum << " - " << ImagSum << "i" << endl;
  }
  else{
    cout << endl << "The value of the polynomial is " << realSum << " + " << ImagSum << "i" << endl;
  }
}

polynomialType polynomialType::operator + (const polynomialType& right)
{
  int size = max(length, right.length);

  polynomialType temp(size); // polynomial to store the sum

  for (int i = 0; i < min(length, right.length); i++){
      temp.real[i] = real[i] + right.real[i];
      temp.imaginary[i] = imaginary[i] + right.imaginary[i];
  }
  
  if (size == length){
      for (int i = min(length, right.length); i < length; i++){
          temp.real[i] = real[i];
          temp.imaginary[i]=imaginary[i];
      }
  }
  else{
      for (int i = min(length, right.length); i < right.length;i++){
          temp.real[i] = right.real[i];
          temp.imaginary[i]=right.imaginary[i];
      }
  }
  return temp;
}

polynomialType polynomialType::operator - (const polynomialType& right)
{
  int size = max(length, right.length);

  polynomialType temp(size); //polynomial to store the sum

  for (int i = 0; i < min(length, right.length); i++){
      temp.real[i] = real[i] - right.real[i];
      temp.imaginary[i] = imaginary[i] - right.imaginary[i];
  }
  
  if (size == length){
      for (int i = min(length, right.length); i < length; i++){
          temp.real[i] = real[i];
          temp.imaginary[i]=imaginary[i];
      }
  }
  else{
      for (int i = min(length, right.length); i < right.length;i++){
          temp.real[i] = -right.real[i];
          temp.imaginary[i]=right.imaginary[i];
      }
  }
  return temp;
}

polynomialType polynomialType::operator * (const polynomialType& right)
{
  int newsize;
  newsize=length + right.length - 1;
  polynomialType temp(newsize);
  for (int i=0;i<length;i++){
    for (int j=0;j<right.length;j++){
      temp.real[i+j]=0;
      temp.imaginary[i+j]=0;
    }
  }
  for (int i=0; i<length;i++){
    for (int j=0; j<right.length; j++){
      temp.real[i+j] = temp.real[i+j] + (real[i] * right.real[j]) - (imaginary[i] * right.imaginary[j]);
      temp.imaginary[i+j] = temp.imaginary[i+j] + (real[i] * right.imaginary[j]) + (imaginary[i] * right.real[j]);
      }
    }
  return temp;
}

polynomialType polynomialType::operator ~ (){
  int newsize=length-1;
  polynomialType temp(newsize);
  for (int i=0; i<newsize; i++){
    if ((real[i+1]!=0) || (imaginary[i+1]!=0)){
      temp.real[i]=real[i+1]*(i+1);
      temp.imaginary[i]=imaginary[i+1]*(i+1);
    }
  }
  return temp;
}


int polynomialType::min(int x, int y) const
{
	if (x <= y)
		return x;
	else
		return y;
}

int polynomialType::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}


string returnSign(double num){
  if (num>0){
    return " + ";
  }
  else if (num < 0 ){
    return " - ";
  }
  else{
    return " + ";
  }
}

ostream& operator << (ostream& os, const polynomialType& p){
  int indexFirstNonzeroCoeff = 0;
  for (int i=0; i<p.length;i++){
    if ((p.real[i] || p.imaginary[i])!=0){
      indexFirstNonzeroCoeff=i;
      break;
    }
  }

  if (indexFirstNonzeroCoeff < p.length)
  {
    if (indexFirstNonzeroCoeff==0){
      os << "(" << p.real[indexFirstNonzeroCoeff] << returnSign(p.imaginary[indexFirstNonzeroCoeff]) << abs(p.imaginary[indexFirstNonzeroCoeff])<< "i)";
  }
    else{
      os << "( " << p.real[indexFirstNonzeroCoeff] << returnSign(p.imaginary[indexFirstNonzeroCoeff]) << abs(p.imaginary[indexFirstNonzeroCoeff])<< "i)x^"<<indexFirstNonzeroCoeff;
    }
    for (int i=indexFirstNonzeroCoeff +1; i<p.length;i++)
    {
      if ((p.real[i] || p.imaginary[i])!=0){
        os << " + ("<< p.real[i] << returnSign(p.imaginary[i]) << abs(p.imaginary[i])<< "i)x^"<<i;
      }
    }
  }
  else{
    os << "0";
  }
  return os;
}


istream& operator >> (istream& is, polynomialType& p)
{
  cout << "The degree of this polynomial is: "
        << p.length - 1 << endl;
  
  for (int i = 0; i < p.length; i++)
  {
      cout << endl << "For the co-efficient of x^"<<i<<" : "<<endl;
      cout << "Enter the REAL value: ";
      is >> p.real[i];
      cout << "Enter the IMAGINARY value: ";
      is >> p.imaginary[i];
      
  }

  return is;
}