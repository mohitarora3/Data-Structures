#include <iostream>
#include <cstdlib>
#include<conio.h>
#include<process.h>
#define MAXSIZE 100  // or const int MAXSIZE=100;

using namespace std;


class stack
{
	/*
	objective: Create a class for implementing Stack using array
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the stack class
	*/
	
	int *arr;					// for dynamic array 
	int top;
	int capacity;					// checks size defined by user
	public:
		stack(int size = MAXSIZE);			// constructor to create array dynamically
		~stack();					// destructor to delete dynamically created array
		void push(int &);
		int pop();
		int peek();
		int size();					// Current size of stack
		bool isEmpty();
		bool isFull();
};
stack::stack(int size)
{
	/*
	objective:to initialize class variables with an initial value and dynamically create an array of given size
	input parameters:
					size-integer value
	output paramaters:none
	*/
	capacity=size;
	top=-1;
	arr=new int[size];
}
void stack::push(int &ele)
{
	/*
	objective:to push an element in stack
	input parametrs:
					ele-element to be pushed(an integer value)
	output parameters:none
	*/
	if(top==capacity-1)
		{
			cout<<"OVERFLOW!!";
			exit(0);
		}
	else
		arr[++top]=ele;
}

int stack::pop()
{
	/*
	objective:to pop an element from stack
	input parametrs:none
	output parameters:ele-popped element (an integer value)
	*/
	if(top==-1)
		{
			cout<<"UNDERFLOW!!";
			exit(0);
			return -1;
		}
	else
		return arr[top--];
}

int stack::size()
{
	/*
	objective:to return current size of stack
	input parametrs:none
	output parameters:top +1 (an integer value)
	*/
	return top+1;
}

int stack::peek()
{
	/*
	objective:to return top element of stack
	input parametrs:none
	output parameters:topmost element of stack(an integer value)
	*/
	
	if(top!=-1)
			return arr[top];
	else
	{
		cout<<"\nUNDERFLOW!";
		exit(0);
	}	
}

bool stack::isEmpty()
{
	
	/*
	objective:to check wheteher stack is empty or not
	input parametrs:none
	output parameters:
					1-if stack is empty(a boolean value)
					0-if stack is not empty
	*/
	if(top==-1)
		return 1;
	else
		return 0;
}

bool stack::isFull()
{
	
	/*
	objective:to check wheteher stack is full or not
	input parametrs:none
	output parameters:
					1-if stack is full(a boolean value)
					0-if stack is not full
	*/
	if(top==capacity-1)
		return 1;
	else
		return 0;
}

stack::~stack()
{
	/*
	objective:to delete dynamically created array
	input parameters :none
	output parameters:none
	*/
	delete []arr;
}

int main()
{
	/*
	objective:to implement stack operations
	*/
	int ch,n,ele,x;
	bool ans;
	char c;
	cout<<"Enter size";
	cin>>n;
	stack s(n);
	do
	{
	cout<<"STACK IMPLEMENTATION::";
	cout<<"\n1.PUSH";
	cout<<"\n2.POP";
	cout<<"\n3.TOPMOST ELEMENT";
	cout<<"\n4.CURRENT SIZE";
	cout<<"\n5.IS STACK EMPTY?";
	cout<<"\n6.IS STACK FULL?";
	cout<<"\n\tenter your choice";
	cin>>ch;
	
	switch(ch)
	{
		
		case 1:cout<<"\nEnter element";
				cin>>ele;
				s.push(ele);
				break;
				
		case 2:x=s.pop();
				cout<<"\nPOPPED ELEMENT IS: "<<x;
				break;
		
		case 3:x=s.peek();
				if(x)
					cout<<"\nPPEKED ELEMENT IS: "<<x;
				break;
		case 4:x=s.size();
				cout<<"\nCURRENT SIZE is: "<<x;
				break;
		case 5:ans=s.isEmpty();
				if(ans)
					cout<<"\nSTACK IS EMPTY";
				else
					cout<<"\nSTACK IS NOT EMPTY";
				break;
		case 6:ans=s.isFull();
				if(ans)
					cout<<"\nSTACK IS FULL";
				else
					cout<<"\nSTACK IS NOT FULL";
				break;
		default:cout<<"\nWRONG CHOICE!!";
				exit(0);
				
	}
	cout<<"\nwant to continue (enter Y or Y) ";
	cin>>c;	
		
	}while(c=='y'||c=='Y');
	
	
}
