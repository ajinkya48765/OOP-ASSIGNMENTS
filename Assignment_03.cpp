#include <iostream>
using namespace std;
int main()
{
    char o,ch;
    float num1,num2;
    do
    {
    cout << "Enter operands , operator and operand: ";
    cin >> num1>>o>>num2;
    switch(o)
    {
        case '+':
            cout << num1+num2;
            break;
        case '-':
            cout << num1-num2;
            break;
        case '*':
            cout << num1*num2;
            break;
        case '/':
            cout << num1/num2;
            break;
        default:
            /* If operator is other than +, -, * or /, error message is shown */
            cout << "Error! operator is not correct";
            break;
    }
    cout<<"\n\n do you want to Continue?";
    cin>>ch;
    }while(ch!='n' && ch!='N');
    return 0;
}
