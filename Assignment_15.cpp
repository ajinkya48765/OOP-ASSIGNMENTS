/*
Write C++ program using STL to add binary numbers (assume one bit as one number); use STL stack.
*/
#include<iostream>
#include<stack>
using namespace std;

stack<int> read()
{
    stack<int>temp;
    char arr[5];

    cout<<"Enter the binary number :";
    cin>>arr;

    for(int i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == '1')
            temp.push(1);
        else if(arr[i] == '0')
            temp.push(0);
    }

    return temp;
}

stack<int> add(stack<int>&s1, stack<int>&s2)
{
    stack<int>temp;
    int b1,b2,sum = 0,carry = 0;

    while(!s1.empty() || !s2.empty())
    {
        b1 = 0, b2 = 0;
        if(!s1.empty())
        {
            b1 = s1.top();
            s1.pop();
        }
        if(!s2.empty())
        {
            b2 = s2.top();
            s2.pop();
        }
        sum = (b1+b2+carry)%2;
        carry = (b1+b2+carry)/2;
        temp.push(sum);
    }
    if(carry == 1)
        temp.push(1);
    return temp;
}

void display(stack<int>&s)
{
    cout<<"DISPLAYING STACK"<<endl;
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int>n1,n2,n3;

    n1 = read();
    n2 = read();
    n3 = (add(n1, n2));
    display(n3);
    return 0;
}
