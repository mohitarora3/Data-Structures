#include<iostream>
#include<conio.h>
#define MAXSIZE 100
using namespace std;
class node
{
	/*
	objective: Create a class for implementing node
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the node class
	*/

	int info;
	node *right;
	node *left;
	friend class binary;
	public:
		node()
		{
			right=0;
			left=0;
		}
		node(int ele,node *p=0,node *t=0)
		{
			info=ele;
			left=p;
			right=t;
		}
	
};
class stack
	/*
	objective: Create a class for implementing Stack using array
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the stack class
	*/
{
	int *arr;					// for dynamic array 
	int top;
	int capacity;					// checks size defined by user
public:
	stack(int size = MAXSIZE);			// constructor to create array dynamically
	~stack();					// destructor to delete dynamically created array
	void push(int &);
	void pop();
	int peek();
	int size();					// Current size of stack
	void display_stack();
	bool isEmpty();
	bool isFull();
};

class binary
{
	/*
	objective: Create a class for implementing binary search tree
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the binary class
	*/

	node *root;
	int count;
	stack s;
	
	public:
	binary()
	{
	/*
	objective: initialize data members of class binary
	input parameters: none
	output value: none
	description:  class constructor
	*/

		root=0;
		count=0;
	}
	void insert(int);
	void display(node *);
	node *ret_root(){
		return root;
	}
	
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

void stack::pop()
{
	/*
	objective:to pop an element from stack
	input parametrs:none
	output parameters:ele-popped element (an integer value)
	*/
	if(top==-1)
		{
			cout<<"UNDERFLOW!!";
			return ;
		}
	else
			top--;
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
void stack::display_stack()
{
	for(int i=0;i<=top;i++)
		cout<<arr[i]<<" ";
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

void binary::insert(int ele)
{
	/*
	objective:insert an element into binary search tree
	input parameters:
		ele-(integer value)-element to be inserted into binary search tree
	approach-starting from root 
			if ele is greater than current element 
				go to right subtree
			else if element is less than current element
				go to left subtree
	*/
	if(root==0)
		root=new node(ele);
	else
	{
		node *temp=root,*prev=0;
		while(temp)
		{
			if(ele>temp->info)
				{
					prev=temp;
					temp=temp->right;
				}
			else if(ele<temp->info)
			{
				prev=temp;
				temp=temp->left;
			}
			
		}
		if(ele>prev->info)
			prev->right=new node(ele);
		else if(ele<prev->info)
			prev->left=new node(ele);
	}
}
void binary::display(node *r)
{
	/*
	objective:print out all its root –to –leaf paths of a binary tree
	input parameters:
		r-node object which is initially initialized to root
	return value:none
	approach:
			push root's info into stack
			recursively call for root's left subtree
			if root is a leaf
				display the whole stack 
			recursively call for root's right subtree
			pop an element fron stack
	*/
	if(r==0)
		return;
	s.push(r->info);
	display(r->left);
	if(r->left==0&&r->right==0)
	{
		cout<<endl;
		cout<<"\t";
		s.display_stack();
	}
	display(r->right);
	s.pop();
}
int main()
{
	/*
	objective:print out all its root –to –leaf paths of a binary tree.
	input parameters:none
	output parameters:none
	approach:by invoking function display
	*/
	binary b;
	int ele,n;
	cout<<"\n\tEENTER SIZE:";
	cin>>n;
	cout<<"\n\tENTER ELEMENTS:";
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		b.insert(ele);
	}
	cout<<"\n\tPATHS FROM ROOT TO ALL LEAF ARE AS FOLLOWS:";
	b.display(b.ret_root());
	getch();	
}
