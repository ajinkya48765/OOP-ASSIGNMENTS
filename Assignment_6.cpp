/*
==================================
 ASSIGNMENT 6 : Student Database
==================================

Name : Sahil Hadke
Roll No. : 17
Batch : S2

Develop an object oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. etc Construct the
database with suitable member functions for initializing and destroying the data viz
constructor, default constructor, Copy constructor, destructor, static member functions, friend
class, this pointer, in-line code and dynamic memory allocation operators-new and delete.
*/

#include <iostream>
#include <string>
using namespace std;

class DateOfBirth
{
public:
    int Day, Month, Year;

    DateOfBirth()
    {
        //default constructor
    }

    DateOfBirth(DateOfBirth &obj) //Copy Constructor
    {
        Day = obj.Day;
        Month = obj.Month;
        Year = obj.Year;
    }

    void getData()
    {
        cout<<"Date of Birth"<<endl;
        cout<<"Enter Day(int) :";
        cin>>Day;
        cout<<"Enter Month(int) :";
        cin>>Month;
        cout<<"Enter Year(int) :";
        cin>>Year;
    }

    void PrintData()
    {
        cout<<"DOB              : "<<Day<<"/"<<Month<<"/"<<Year<<endl;
    }
};

class Student
{
public:

    static int studentCount;
    string name, _class, blood, address, tele_num, lic_num;
    char division;
    int roll;
    DateOfBirth DOB;

    Student() //Default Constructor
    {
        studentCount++;
    }

    Student(Student &obj) //Copy Constructor
    {
        name = obj.name;
        _class = obj._class;
        blood = obj.blood;
        division = obj.division;
        roll = obj.roll;
        address = obj.address;
        tele_num = obj.tele_num;
        lic_num = obj.lic_num;
        DOB = obj.DOB;
        studentCount++;
    }

    ~Student() //Destructor
    {
        studentCount--;
    }

    void getData();
    void printData();
};

int Student::studentCount = 0;

void Student::getData()
{
    cout<<"Enter student name(string) :";
    getline(cin, name);
    cout<<"Enter student address(string) :";
    getline(cin, address);
    cout<<"Enter student class(string) :";
    getline(cin, _class);
    cout<<"Enter blood group(string) :";
    getline(cin, blood);
    cout<<"Enter student division(char) :";
    cin>>division;
    cout<<"Enter student roll number(int) :";
    cin>>roll;
    cin.ignore();
    cout<<"Enter student telephone number(string) :";
    getline(cin, tele_num);
    cout<<"Enter student license number(string) :";
    getline(cin, lic_num);
    DOB.getData();
}

void Student::printData()
{
    cout<<endl;
    cout<<"STUDENT INFORMATION"<<endl<<endl;
    cout<<"Name             : "<<name<<endl;
    cout<<"Roll No          : "<<roll<<endl;
    cout<<"Class            : "<<_class<<endl;
    cout<<"Division         : "<<division<<endl;
    cout<<"Address          : "<<address<<endl;
    cout<<"Telephone Number : "<<tele_num<<endl;
    cout<<"License Number   : "<<lic_num<<endl;
    cout<<"Blood Group      : "<<blood<<endl;
    DOB.PrintData();
    cout<<"Total No.        : "<<studentCount<<endl;
    cout<<endl;
}

int main()
{
    Student *s1 = new Student; //using new operator to instantiate.
    s1->getData();
    cout<<"Printing data of s1"<<endl;
    s1->printData();

    Student *s2 = new Student(*s1); //copy constructor
    cout<<"Printing data of s2"<<endl;
    s2->printData();

    delete s2;
    delete s1;

    cout<<"Both students deleted"<<endl;
    cout<<"students count : "<<Student::studentCount<<endl;

    return 0;
}
