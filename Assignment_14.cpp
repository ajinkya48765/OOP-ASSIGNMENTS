/*
    STACK AND QUEUE USING STL
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

    void enqueue(int a);
    void dequeue();
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

void QUEUE::dequeue()
{
    lst.pop_front();
}

void QUEUE::enqueue(int a)
{
    lst.push_back(a);
}

class STACK
{
public:
    list<int>lst;

    void display();
    void push(int a);
    void pop();
};

void STACK::display()
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
        cout<<"DISPLAYING STACK"<<endl;
        while(st != en)
        {
            cout<<*st<<" ";
            st++;
        }
        cout<<endl;
    }
}

void STACK::push(int a)
{
    lst.push_back(a);
}

void STACK::pop()
{
    lst.pop_back();
}

int main()
{
    QUEUE s;

    s.display();

    s.enqueue(5);
    s.enqueue(1);
    s.enqueue(10);

    s.display();

    s.dequeue();

    s.display();
}
