/*
===========================
  ASSIGNMENT 7 : BOOK SHOP
===========================
Name : Sahil Hadke
Roll No : 17
Batch : S2
A book shop maintains the inventory of books that are being sold at the shop.
The list includes details such as author, title, price, publisher and stock position.
Whenever a customer wants a book,
the sales person inputs the title and author and the system searches the list and displays whether it is available or not.
If it is not, an appropriate message is displayed.
If it is, then the system  displays  the  book  details  and  requests  for  the  number  of  copies  required.
If the requested copies book details and requests for the number of copies required.
If the requested copies are available, the total cost of the requested copies is displayed;
otherwise the message "Required copies not in stock"  is displayed.
Design a system using a class called books with suitable  member functions and Constructors.
Use  new  operator  in  constructors to allocate memory space required.
Implement C++ program for the system.
*/

#include<iostream>
#define max 5
using namespace std;

class book
{
public:
    string title, author, publisher;
    int stock, price;

    book()
    {
        getData();
    }

    void Display();
    void getData();
    void Buy(int n);
    int Check(string t, string a, string p, int s);
};

book *books[max];

void book::getData()
{
    cout<<"Enter the title of book : ";
    getline(cin, title);

    cout<<"Enter the author of book : ";
    getline(cin, author);

    cout<<"Enter the publisher of the book : ";
    getline(cin, publisher);

    cout<<"Enter the price of the book : ";
    cin>>price;

    cout<<"Enter stock : ";
    cin>>stock;
}

int book::Check(string t, string a, string p, int s)
{
    if(t != title || a != author || p != publisher || s > stock)
        return 0;
    return 1;
}

void book::Display()
{
    cout<<"Title : "<<title<<endl;
    cout<<"Publisher : "<<publisher<<endl;
    cout<<"Author : "<<author<<endl;
    cout<<"Price : "<<price<<endl;
    cout<<"Stock : "<<stock<<endl;
}

void book::Buy(int n)
{
    if(n > stock)
    {
        cout<<"NO STOCK"<<endl;
        cin.ignore();
        return;
    }
    stock = stock-n;
    cout<<"Total Price = "<<price*n<<endl;
    cout<<n<<" book(s) brought"<<endl;
}

void RequestBook()
{
    string title, author, publisher;
    int stock, flag = 0;

    cout<<"Enter the title of book : ";
    getline(cin, title);

    cout<<"Enter the author of book : ";
    getline(cin, author);

    cout<<"Enter the publisher of the book : ";
    getline(cin, publisher);

    cout<<"Enter stock : ";
    cin>>stock;

    for(int i = 0; i < max; i++)
    {
        if(books[i]->Check(title, author, publisher, stock))
        {
            flag = 1;
            books[i]->Buy(stock);
            break;
        }
    }
    if(!flag)
        cout<<"NO BOOK FOUND"<<endl;
}
int main()
{
    int i = 0,n = 1, m = 1;

    while(n)
    {
        cout<<"DETAILS OF BOOK YOU WANT TO ADD TO THE STORE"<<endl;
        books[i] = new book;
        i++;

        cout<<"Press\n1 to add more books\n0 to buy book : ";
        cin>>n;

        cin.ignore();
    }

    while(m)
    {
        cout<<"DETAILS OF BOOK YOU WANT TO BUY FROM THE STORE"<<endl;

        RequestBook();

        cout<<"\tPress\n1 to buy more books\n0 to exit : ";
        cin>>m;
        cin.ignore();
    }

    return 0;

}
