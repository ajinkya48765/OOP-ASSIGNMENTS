/*
    DEQUEUE USING STL
*/

#include<iostream>
#include<cstdlib>
#include<list>
#include<iterator>
using namespace std;

class QUEUE
{
public:
    list<int> lst;

    void benqueue(int a);
    void fdequeue();
    void fenqueue(int a);
    void bdequeue();
    void display();
};

void QUEUE::display()
{
    list<int>::iterator st, en;
    st = lst.begin();
    en = lst.end();

    if(st == en)
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {
        cout<<"DISPLAYING QUEUE"<<endl;
        while(st != en)
        {
            cout<<*st<<" ";
            st++;
        }
        cout<<endl;
    }
}

void QUEUE::fdequeue()
{
    lst.pop_front();
}

void QUEUE::bdequeue()
{
    lst.pop_back();
}

void QUEUE::benqueue(int a)
{
    lst.push_back(a);
}

void QUEUE::fenqueue(int a)
{
    lst.push_front(a);
}

int main()
{
    QUEUE q;

    q.fenqueue(1);
    q.fenqueue(2);
    q.fenqueue(3);
    q.fenqueue(4);

    q.display();

    q.benqueue(5);
    q.benqueue(6);
    q.benqueue(7);

    q.display();

    q.fdequeue();
    q.bdequeue();

    q.display();
}
