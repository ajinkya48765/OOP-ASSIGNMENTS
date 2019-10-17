#include<iostream>
using namespace std;

class Calc
{
    float num1, num2;
public:
    Calc(float a, float b){
        num1 = a;
        num2 = b;
    }

    inline float add()
    {
        return num1+num2;
    }

    inline float sub()
    {
        return num1-num2;
    }

    inline float mul()
    {
        return num1*num2;
    }

    inline float div()
    {
        return num1/num2;
    }

    inline int mod()
    {
        return (int)num1%(int)num2;
    }
};

int main()
{
    char op;
    int n1, n2, condi = 1;
    while(condi)
    {
        cout<<"Enter num1 op num2 :";
        cin>>n1>>op>>n2;
        Calc obj(n1, n2);

        switch(op)
        {
            case '+':
                cout<<"Result :"<<obj.add()<<endl;
                break;
            case '-':
                cout<<"Result :"<<obj.sub()<<endl;
                break;
            case '*':
                cout<<"Result :"<<obj.mul()<<endl;
                break;
            case '/':
                cout<<"Result :"<<obj.div()<<endl;
                break;
            case '%':
                cout<<"Result :"<<obj.mod()<<endl;
                break;
            default:
                cout<<"WRONG OPERAND"<<endl;
        }

        cout<<"Enter 1 to continue, 0 to exit :";
        cin>>condi;
        cout<<endl;
    }

    cout<<"Code ended";

    return 0;
}
