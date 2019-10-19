
//Program to implement stack and queue using SSL






#include <algorithm> 
#include <stack> 
#include <queue>
#include <iostream> 
#include <iterator> 
#include <string>
using namespace std;

int showstack(stack <int>);

int displayqueue( queue <int>);
int displaystack( stack <int>);
int main()
{
	char choice;
	int n;
	stack <int>s;
	queue <int>q;

	while(1)
	{
		cout<<"\n\n*** PROGRAM FOR IMPLEMENTATION OF STACK AND QUEUE USING STL ***"<<endl;

		cout<<"(1) Stack Operations \n(2) Queue Operations"<<endl;
		
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		if(choice=='1')
		{
			while(1)
			{
				cout<<"\nYou are in stack\n";
				cout<<"(1) push \n(2) pop \n(3) size \n(4) display \n(5) top \n(6) exit  "<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>choice;

				switch(choice)
				{
					case '1':
						cout<<"\nenter the number to push\n";
						cin>>n;
						s.push(n);
						break;
					case '2':
						if(s.empty()==1)
						{
							cout<<"\nstack is empty\n";
							break;
						}
						else
						{
							s.pop();
							cout<<"\nelement popped successfully\n";
							break;
						}
					case '3':
						cout<<"\nSize of stack is "<<s.size()<<endl;
						break;
					case '4':
						displaystack(s);
						break;
					case '5':
						cout<<"\nTop of stack is "<<s.top()<<endl;
						break;
					default:
						cout<<"\nout of the stack now....\n\n";
						goto exit;
						break;
				}
			}
		}
		else if(choice=='2')
		{
			while(1)
			{
				cout<<"\nYou are in queue\n";
				cout<<"(1) add \n(2) remove \n(3) size \n(4) display \n(5) front \n(6) end \n(7) exit  "<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>choice;

				switch(choice)
				{
					case '1':
						cout<<"\nenter the number to add\n";
						cin>>n;
						q.push(n);
						break;
					case '2':
						if(q.empty()==1)
						{
							cout<<"\nqueue is empty\n";
							break;
						}
						else
						{
							q.pop();
							cout<<"\nelement removed successfully\n";
							break;
						}
					case '3':
						cout<<"\nSize of queue is "<<q.size()<<endl;
						break;
					case '4':
						displayqueue(q);
						break;
					case '5':
						cout<<"\nFront of queue is "<<q.front()<<endl;
						break;
					case '6':
						cout<<"\nEnd of queue is "<<q.back()<<endl;
						break;
					default:
						cout<<"\nout of the queue now....\n\n";
						goto exit;
						break;
				}
			}
		}
		else
		{
			cout<<"\nwrong choice\n";
		}
exit:
		cout<<"\n Do you want to continue(Y/N)\n";
		cin>>choice;
		if(choice=='y')
			choice='Y';
		if (choice!='Y')
			break;
	}
}

int displaystack(stack <int>s)
{
	while(!s.empty())
	{
		cout<<"    "<<s.top()<<endl;
		s.pop();
	}
	return 0;
}

int displayqueue(queue <int>q)
{
	while(!q.empty())
	{
		cout<<"    "<<q.front()<<endl;
		q.pop();
	}
	return 0;
}
