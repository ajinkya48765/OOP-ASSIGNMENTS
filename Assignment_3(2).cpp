/*
    ==========================================================
    ASSIGNMENT 1 : CALCULATOR USING SWITCH AND WITHOUT CLASSES 
    ==========================================================
 
    Code by: SAHIL HADKE
    Roll No: 17
    Batch: S1
    Question: Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The program
	      should take two operands from user and performs the operation on those two operands
	      depending upon the operator entered by user. Use a switch statement to select the operation.
	      Finally, display the result. 
*/

#include<iostream>
using namespace std;

float Add(float a, float b)
{
	return a + b;
}

float Sub(float a, float b)
{
	return a - b;
}

float Mul(float a, float b)
{
	return a * b;
}

float Div(float a, float b)
{
	return a / b;
}

int Mod(float a, float b)
{
	return (int)a / (int)b;
}

int main()
{
	float num1, num2, condition = 1;
	char op;
	do {
		cout << "Enter num1 op num2 :";
		cin >> num1 >> op >> num2;
		cout << endl;

		switch (op)
		{
		case '+':
			cout << Add(num1, num2)<<endl;
			break;
		case '-':
			cout << Sub(num1, num2) << endl;
			break;
		case '/':
			cout << Div(num1, num2) << endl;
			break;
		case '*':
			cout << Mul(num1, num2) << endl;
			break;
		case '%':
			cout << Mod(num1, num2) << endl;
			break;
		default:
			cout << "Wrong operator!" << endl;
			break;	    
		}
		
		do {
			cout << "Press 1: Continue\nPress 0: Exit\n";
			cin >> condition;
		} while (!(condition || !condition));
	} while (condition);
	
	return 0;
}
