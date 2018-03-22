#include <iostream>
#include<conio.h>
#define MAXSIZE 100  // or const int MAXSIZE=100;

using namespace std;


class stack
	/*
	objective: Create a class for implementing Stack using array
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the stack class
	*/
{
	char *arr;					// for dynamic array 
	int top;
	int capacity;					// checks size defined by user
public:
	stack(int size = MAXSIZE);			// constructor to create array dynamically
	~stack();					// destructor to delete dynamically created array
	void push(char &);
	char pop();
	char peek();
	int size();					// Current size of stack
	bool isEmpty();
	bool isFull();
	
};

int weight(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':return 3;
		default:return 0;
	}
}


			
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
	arr=new char[size];
}
void stack::push(char &ele)
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

char stack::pop()
{
	/*
	objective:to pop an element from stack
	input parametrs:none
	output parameters:ele-popped element (an integer value)
	*/
	if(top==-1)
		{
			cout<<"UNDERFLOW!!";
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

char stack::peek()
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
		return -1;
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
void conversion(string infix,int n)
{
	
	int i;
	char x;
	stack s(n);
	for(i=0;i<n;i++)
	{
		if(infix[i]=='(')
			s.push(infix[i]);
		else if(infix[i]==')')
		{
			x=s.pop();
			while(x!='(')
				{
					cout<<x;
					x=s.pop();
				}
		}
			 
		else if((infix[i]>=65&&infix[i]<=90)||(infix[i]>=97||infix[i]<=122))
			cout<<infix[i];
		else if (weight(s.peek())>=weight(infix[i]))
			{
				while(weight(s.peek())>=weight(infix[i]))
				{
				cout<<s.pop();
				}
				s.push(infix[i]);
			}
		else
			s.push(infix[i]);
	
	}
}
int main()
{
	/*
	objective:to implement stack operations
	*/
	int ch,n,ele,x;
	string str;
	bool ans;
	char c;
	cout<<"Enter size";
	cin>>n;
	stack s(n);
	cout<<"/nENTER INFIX EXPRESSION";
	cin>>str;
	conversion(str,str.length());	
	getch();
	
}

