#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class phonebook
{
public:
    char name[10], ph[10];

    void getData()
    {
        cout<<"Enter Name :";
        cin>>name;
        cout<<"Enter Phone Number :";
        cin>>ph;
    }
};


int main()
{
    fstream f;

    string temp; //used to store temp string while displaying records
    char temp_name[10]; //used to store temp name switch case 3

    int choice = 1, while_counter = 1, found1;
    phonebook p;

    while(while_counter)
    {
        cout<<"\n*****PHONEBOOK*****"<<endl;
        cout<<"1. Add to record."<<endl;
        cout<<"2. Display Records."<<endl;
        cout<<"3. Find Number."<<endl;
        cout<<"4. Find Name."<<endl;
        cout<<"5. Update telephone number."<<endl;
        cout<<"6. Exit."<<endl;
        cout<<"Enter choice :";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1: //Add New Record
                f.open("a.txt", ios_base::app);
                p.getData();
                f<<p.name<<" "<<p.ph<<endl;
                f.close();
                break;

            case 2: //Display Record
                f.open("a.txt", ios_base::in);
                while(f)
                {
                    getline(f, temp);
                    cout<<temp<<endl;
                }
                f.close();
                break;

            case 3: //Find Number
                cout<<"Enter the name to search:";
                cin>>temp_name;
                f.open("a.txt", ios_base::in);

                found1 = 1;
                while(f)
                {
                    temp = "";
                    getline(f, temp);
                    for(int i = 0; i < strlen(temp_name); i++)
                    {
                        if(temp_name[i] != temp[i])
                        {
                            found1 = 0;
                            break;
                        }
                    }
                    if(found1 == 1)
                    {
                        cout<<"FOUND :"<<temp<<endl;
                        break;
                    }
                    else if(found1 == 0)
                    {
                        if(!f) //eof returs true if no more data is in file
                        {
                            cout<<"NOT FOUND!"<<endl;
                            break;
                        }
                    }
                }

                f.close();
                break;

            case 4: //Find Name
                break;

            case 5: //Update Telephone
                break;

            case 6: //Exit
                while_counter = 0;
                break;
        }
    }

    return 0;
}
