/*
    Write C++ program using STL for Sorting and searching with user-defined records such as:
    Person Record (Name, birth date, telephone no)
*/

#include<iostream>
#include<list>
#include<cstring>
using namespace std;

class record
{
public:
    list<string> name, dob, ph;

    void display();
    void sorn();
    void sorp();
    void sord();
    void se(string s);
    void getData();
};

void record::display()
{
    list<string>::iterator i1 = name.begin(), i2 = dob.begin(), i3 = ph.begin();

    for(i1,i2,i3; i1 != name.end() && i2 != dob.end() && i3 != ph.end(); i1++, i2++, i3++)
    {
        cout<<endl<<"Name :"<<*i1<<endl;
        cout<<"DOB :"<<*i2<<endl;
        cout<<"PH :"<<*i3<<endl<<endl;
    }
}

void record::sorn()
{
    string temp;

    list<string>::iterator i1 = name.begin(), i2 = dob.begin(), i3 = ph.begin(), i, j, k;

    while(i1 != name.end())
    {
        i = i1;
        j = i2;
        k = i3;
        k++;
        j++;
        i++;
        while(i != name.end())
        {
            if(*i1 < *i)
            {

                //swap name
                temp = *i1;
                *i1 = *i;
                *i = temp;

                //swap dob
                temp = *i2;
                *i2 = *j;
                *j = temp;

                //swap ph
                temp = *i3;
                *i3 = *k;
                *k = temp;
            }
            j++;
            k++;
            i++;
        }
        i1++;
        i2++;
        i3++;
    }

}

void record::getData()
{
    string temp;
    cout<<"Enter the name :";
    getline(cin, temp);
    name.push_back(temp);

    cout<<"Enter dob :";
    getline(cin, temp);
    dob.push_back(temp);

    cout<<"Enter ph :";
    getline(cin, temp);
    ph.push_back(temp);
}

void record::se(string s)
{
    list<string>::iterator i1 = name.begin(), i2 = dob.begin(), i3 = ph.begin();
    int fl = 0;

    while(i1 != name.end() && i2 != dob.end() && i3 != ph.end())
    {
        if(s == *i1 || s == *i2 || s == *i3)
        {
            cout<<"RECORD FOUND"<<endl;
            cout<<"Name :"<<*i1<<endl;
            cout<<"Dob :"<<*i2<<endl;
            cout<<"Ph :"<<*i3<<endl;
            fl = 1;
            break;
        }
        i1++;
        i2++;
        i3++;
    }

    if(!fl)
    {
        cout<<"NO RECORD FOUND"<<endl;
    }
}

int main()
{

    record r;

    r.getData();
    r.getData();

    r.display();

    r.se("Sahil");

    r.sorn();

    r.display();


    return 0;
}
