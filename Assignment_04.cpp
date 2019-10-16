/*
    ==================================
      ASSIGNMENT 4 : COMPLEX NUMBERS
    ==================================
 
    Code by: SAHIL HADKE
    Roll No: 17
    Batch: S1
    QUESTION ==> Implement a class Complex which represents the Complex Number data type. 
    		 Implement the following operations:
    		 1.Constructor (including a default constructor which creates the complex number 0+0i).
    		 2.Overloaded operator+ to add two complex numbers.
		 3.Overloaded operator* to multiply two complex numbers.
    		 4.Overloaded << and >> to print and read Complex Numbers. 
*/
#include<iostream>
using namespace std;

class Complex
{

public:

	int real, imag;

	Complex(int r = 0, int i = 0) //default constructor which initializes complex to 0 + i0
	{
		real = r;
		imag = i;
	}

	//overload + operator
	Complex operator +(Complex &obj)
	{
		Complex obj3;
		obj3.real = real + obj.real; //Here real => real of object before + sign
		obj3.imag = imag + obj.imag;  //Here imag => imag of object before + sign

		return obj3;
	}

	//overload * operator
	Complex operator *(Complex &obj)
	{
		Complex obj3;
		obj3.real = (real * obj.real) - (imag * obj.imag); //Here real => real of object before * sign
		obj3.imag = (real * obj.imag) + ( imag * obj.real); //Here imag => imag of object before * sign

		return obj3;
	}
	
	friend ostream & operator <<(ostream &cout, Complex &obj);
	friend istream & operator >>(istream &cin, Complex &obj);
};

//overloading <<
ostream & operator <<(ostream &cout, Complex &obj)
{
	cout<<obj.real<<" +i"<<obj.imag<<endl;
	return cout;
}

//overloading >>
istream & operator >>(istream &cin, Complex &obj)
{
	cout<<"Enter the real part :";
	cin>>obj.real;
	cout<<"\nEnter the imaginary part :";
	cin>>obj.imag;
	cout<<endl;

	return cin;
}

int main()
{
	Complex c1,c2;
	cout << "Enter complex number 1 :"
	cin >> c1;
	cin >> c2;

	cout<<"\nADDITION\n";
	Complex c3 = c1 + c2;
	cout<<c3;

	cout<<"\nMULTIPLICATION\n";
	Complex c4 = c1 * c2;
	cout<<c4;

	cout<<"\nALREADY INITIALIZED\n";
	Complex c5;
	cout<<c5;

	return 0;
}
