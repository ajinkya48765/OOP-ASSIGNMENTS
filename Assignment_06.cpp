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

constructor,
default constructor,
Copy constructor,
destructor,
static member functions,
friend class,
this pointer,
in-line code,
dynamic memory allocation operators-new and delete.

*/

#include<iostream>
#include<cstring>
using namespace std;

class DOB
{
public:
    int d, m, y;

    void getData()
    {
        cout<<"Enter date of birth :";
        cin>>d;
        cout<<"Enter month of birth :";
        cin>>m;
        cout<<"Enter year of birth :";
        cin>>y;
    }
    DOB()
    {
        d = 0;
        m = 0;
        y = 0;
    }

    DOB(DOB &obj)
    {
        d = obj.d;
        m = obj.m;
        y = obj.y;
    }

    void printData()
    {
        cout<<"Date of birth :"<<d<<"/"<<m<<"/"<<y<<endl;
    }
};

class Student
{
public:
    static int sCount;
    string name, div, bg, ph, add, lic, _class;
    int rn;
    DOB *dob;

    Student()
    {
        Student::sCount++;
    }

    Student(Student &obj)
    {
        sCount++;
        name = obj.name;
        bg=obj.bg;
        ph=obj.ph;
        add=obj.add;
        lic=obj.lic;
        rn = obj.rn;
        _class=obj._class;
        dob = new DOB(*obj.dob);
    }

    ~Student(){
         Student::sCount--;
    }

    void getData();
    void printData();
};

void Student::getData()
{
    cout<<"\nName :";
    getline(cin, name);

    cout<<"\nRoll No :";
    cin>>rn;

    cout<<"\nClass :";
    cin.ignore();
    getline(cin ,_class);

    cout<<"\nDiv :";
    getline(cin ,div);

    cout<<"\nBlood Group :";
    getline(cin , bg);

    cout<<"\nPhone No :";
    getline(cin ,ph);

    cout<<"\nLicense Number :";
    getline(cin ,lic);

    cout<<"\nAddress :";
    getline(cin ,add);

    dob = new DOB;
    dob->getData();
}

void Student::printData()
{
    cout<<"Name :"<<name<<endl;

    cout<<"Roll No :"<<rn<<endl;

    cout<<"Class :"<<_class<<endl;

    cout<<"Div :"<<div<<endl;

    cout<<"Blood Group :"<<bg<<endl;

    cout<<"Phone No :"<<ph<<endl;

    cout<<"License Number :"<<lic<<endl;

    cout<<"Address :"<<add<<endl;

    dob->printData();
}

int Student::sCount = 0;

int main()
{


    Student *s1 = new Student;

    cout<<"S ="<<Student::sCount;

    s1->getData();
    s1->printData();

    Student *s2 = new Student(*s1);
    s2->printData();

    return 0;
}
