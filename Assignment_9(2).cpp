/*
    Virtual functions
*/
#include<iostream>
using namespace std;

class Base
{
public:
    float initial;
    float converted;

    void getData()
    {
        cout<<"Enter data :";
        cin>>initial;
    }
    void display()
    {
        cout<<converted<<endl;
    }
    virtual void convert() = 0;
};

class kgtopound: public Base
{
public:
    void convert()
    {
        converted = initial * 2.2;
    }
};

class kmtomiles:public Base
{
public:
    void convert()
    {
        converted = initial * 0.62;
    }
};

int main()
{
    kmtomiles k;
    k.getData();
    k.convert();
    k.display();

    return 0;
}
