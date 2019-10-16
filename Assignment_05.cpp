/*
    ==========================================================
      ASSIGNMENT 5 : Array Operations & Operator Overloading
    ==========================================================
    Code by: SAHIL HADKE
    Roll No: 17
    Batch: S1
    Question: Implement a class CppArray which is identical to a one-dimensional C++ array (i.e., the index
              set is a set of consecutive integers starting at 0) except for the following :
              1. It performs range checking.
              2. It allows one to be assigned to another array through the use of the assignment
              operator (e.g. cp1= cp2)
              3. It supports a function that returns the size of the array.
              4. It allows the reading or printing of array through the use of cout and cin.
*/

#include<iostream>
#define max 10
using namespace std;

class cppArray
{
public:
    int arr[max], len;

    cppArray()
    {
        len = 0;
    }

    cppArray(const cppArray &obj) //copy constructor
    {
        len = obj.len;
        for(int i = 0; i < obj.len; i++)
        {
            arr[i] = obj.arr[i];
        }
    }

    int Range()
    {
        int min = arr[0], _max = arr[0];

        for(int i = 0; i < len; i++)
        {
            if(arr[i] < min)
                min = arr[i];
            if(arr[i] > _max)
                _max = arr[i];
        }

        return _max-min;
    }

    friend istream & operator >>(istream &i, cppArray &obj);
    friend ostream & operator <<(ostream &o, cppArray &obj);
};

istream & operator >>(istream &i, cppArray &obj)
{
    int n;
    cout<<"Enter the number of elements :";
    i>>n;
    obj.len = n;
    for(int i = 0; i < n; i++)
        cin>>obj.arr[i];

    return i;
}

ostream & operator <<(ostream &o, cppArray &obj)
{
    for(int i = 0; i < obj.len; i++)
    {
        o<<obj.arr[i]<<" ";
    }
    o<<endl;
    return o;
}

int main()
{
    cppArray a1;
    cin>>a1;
    cout<<a1;

    cppArray a2 = a1;
    cout<<a2;

    cout<<a2.Range();
    return 0;
}
