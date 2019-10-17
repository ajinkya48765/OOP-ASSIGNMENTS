#include<iostream>
#include<fstream>
using namespace std;

int main()
{


    ofstream file_name;
    file_name.open("a.txt");

    if(!file_name) //file open condition
    {
        cout<<"FILE NOT OPENED"<<endl;
        return 0;
    }

    string name, arr1;
    cout<<"Enter name :";

    while(getline(cin, name))
    {
        if(name == "D")
            break;
        file_name<<name<<endl;
    }

    file_name.close();

    cout<<"OPERATION COMPLETED"<<endl;




    cout<<"READING FROM FILE"<<endl;

    ifstream file_name2("a.txt");

    while(file_name2) //Till end of file
    {
        getline(file_name2, name);
        cout<<name<<endl;
    }

    file_name2.close();

    return 0;
}
