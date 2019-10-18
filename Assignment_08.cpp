/*

==================================
 ASSIGNMENT 8 : Employee Bio-data
==================================
Name : Sahil Hadke
Roll No. : 17
Batch : S2

Create employee bio-data using following classes
i) Personal record 
ii)Professional record 
iii) Academic record. 
Assume appropriatedata members and member function to accept required data & print bio-data.
Create bio-data using multiple inheritance using C++.
*/
#include<iostream>
#include<string>
using namespace std;

class Personal	//Base Class
{
	//Personal Details
protected:
	string name;
	string address;
	int age;
	string email;	
	char gender;
};

class Professional //Base Class
{
	//Professional Details
protected:
	string progLang;
	string OS;
};

class Academic //Base Class
{
	//Academic Details
protected:
	string EnggCollegeName;
	float EnggGrade;
	float sscPerc;
	float hscPerc;
}; 

class Employee : public Personal, public Professional, public Academic
{
	
public:
	void getData();
	void printData();	
};

void Employee::printData()
{
	cout<<endl<<endl<<endl<<"----------------------PERSONAL DETAILS----------------------"<<endl<<endl;
	cout<<"Name: "<<name;
	cout<<"\tGender: "<<gender<<endl;
	cout<<"Age: "<<age;
	cout<<"\t\t\t\tEmail: "<<email<<endl;
	cout<<"Address: "<<address<<endl;

	cout<<endl<<"----------------------ACADEMIC DETAILS----------------------"<<endl<<endl;
	cout<<"SSC Percentage: "<<sscPerc<<"%"<<endl;
	cout<<"HSC Percentage: "<<hscPerc<<"%"<<endl;
	cout<<"Collge Name: "<<EnggCollegeName<<endl;
	cout<<"Grade: "<<EnggGrade<<endl;

	cout<<endl<<"---------------------PROFESSIONAL DETAILS----------------------"<<endl<<endl;
	cout<<"Programming Languages known: "<<progLang<<endl;
	cout<<"Operating Systems known: "<<OS<<endl;	
	
	cout<<endl<<"------------------------------------------------------------"<<endl<<endl;
}

void Employee::getData()
{
	cout<<"PERSONAL DETAILS"<<endl;
	
	cout<<"Enter your name : ";
	getline(cin, name);
	cout<<"Enter your Gender[M/F] : ";
	cin>>gender;
	cout<<"Enter your age : ";
	cin>>age;
	cout<<"Enter your email address : ";
	cin.ignore();
	getline(cin, email);
	cout<<"Enter your residential address : ";
	getline(cin, address);
	
	cout<<endl<<"POFESSIONAL DETAILS"<<endl;

	cout<<"Enter the programming languages you know(separated by spaces) : ";
	getline(cin, progLang);
	cout<<"Enter the operating systems you know(separated by spaces) : ";
	getline(cin , OS);	

	cout<<endl<<"ACADEMIC DETAILS"<<endl;

	cout<<"Enter college name : ";
	getline(cin, EnggCollegeName);
	cout<<"Enter your engineering grade : ";
	cin>>EnggGrade;
	cout<<"Enter SSC Percentage : ";
	cin>>sscPerc;
	cout<<"Enter HSC Percentage : ";
	cin>>hscPerc;

	
}

int main()
{
	Employee e1;
	e1.getData();
	e1.printData();

	return 0;
}
