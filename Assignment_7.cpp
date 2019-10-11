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
otherwise the message ―Required copies not in stock‖ is displayed.
Design a system using a class called books with suitable  member functions and Constructors.
Use  new  operator  in  constructors to allocate memory space required.
Implement C++ program for the system.
*/

#include <iostream>
#include <cstring>
#define count 20
using namespace std;

class Books
{
public:

	char author[15], title[15], publisher[15];
	float price;
	int stock;
	
	Books()
	{
		cout<<"Enter Title of book :";
		cin>>title;

		cout<<"Enter Author of book :";
		cin>>author;

		cout<<"Enter Publisher of book :";
		cin>>publisher;

		cout<<"Enter price :";
		cin>>price;

		cout<<"Enter stock :";
		cin>>stock;
	}

	void Buy();
	void Display();
};

void Books::Display()
{
	cout<<"Title of book : "<<title<<endl;
	cout<<"Author of book : "<<author<<endl;
	cout<<"Publisher of book : "<<publisher<<endl;
	cout<<"Price : "<<price<<endl;
	cout<<"Stock : "<<stock<<endl<<endl;
}

void Books::Buy()
{
	int n;
	cout<<"Enter the number of books to buy :";
	cin>>n;
	
	if(n > stock)
	{
		cout<<"Required copies not in stock"<<endl;
		return;
	}
	else
	{
		stock -= n;
		cout<<"The total price of books = "<<n*price<<endl;
		cout<<"Books brought!"<<endl;
	}
}

Books* arr[count]; //Array of pointers to Books

void DisplayBooks(int n)
{
	cout<<"==============DISPLAYING BOOKS============="<<endl<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"BOOK "<<i+1<<endl;
		arr[i]->Display();
	}	
	cout<<"==============DISPLAYING END============="<<endl<<endl;
}

void Search(int size)
{
	char tit[15], aut[15];
	cout<<"Enter the title to search :";
	cin>>tit;
	cout<<endl<<"Enter the author to search :";
	cin>>aut;

	for(int i = 0; i < size; i++)
	{
		if(strcmp(arr[i]->title, tit) == 0 && strcmp(arr[i]->author, aut) == 0)
		{
			cout<<"BOOK AVAILABLE"<<endl;
			arr[i]->Buy();
			return;		
		}
	}
}

int main()
{

	int BooksNo, _condition = 1;
	cout<<"Enter the number of books in shop :";
	cin>>BooksNo;
	
	for(int i = 0; i < BooksNo; i++)
	{
		cout<<"BOOK "<<i+1<<endl<<endl;
		Books *b = new Books;
		arr[i] = b;
		cout<<endl;
	}

	do
	{
		int choice;
		cout<<"Press 1 to Display Books\nPress 2 to Search Books"<<endl;
		cout<<"Your Choice :";
		cin>>choice;
		
		switch(choice)
		{	
			case 1:
				DisplayBooks(BooksNo);
				break;
			case 2:
				Search(BooksNo);
				break;
			default:
				cout<<"Wrong Input!"<<endl;
				break;
		}
	
		cout<<"Press 1 to continue, 0 to eixt :";
		cin>>_condition;

	}while(_condition);	

	return 0;
}
