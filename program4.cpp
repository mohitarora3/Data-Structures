#include<iostream>
#include<conio.h>
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
	node *next;
	friend class circular;
	public:
		node()
		{
			next=NULL;
		}
		node(int ele,node*ptr=NULL)
		{
			info=ele;
			next=ptr;
		}
};
class circular
{
	/*
	objective: Create a class for implementing circular linklist
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the circular class
	*/

	node *head;
	public:
		circular()
		{
			head=NULL;
		}
		void add(int);
		void display();
		void split();
};

void circular::add(int ele)
{
	/*
	objective:to insert element at the end of the circular linklist
	input parameters:
		ele-(integer value)-element to be inserted into circular linklist
	return value:none
	*/	
	
	if(head==NULL)
	{
			head=new node(ele);
			head->next=head;
	}
	else
	{
		head->next=new node(ele,head->next);
		head=head->next;
	}
}
void circular::display()
{
	/*
	objective:to display elements of circular linklist
	input parameters:none
	return value:none
	approach:-starting from head display every element of  circular linklist
	*/	
	
	node *temp=head;
	if(temp){
	
	while(temp->next!=head)
	{
		cout<<temp->info<<" ";
		temp=temp->next;
	}
	cout<<temp->info;
	}
}
void circular::split()
{
	
	/*
	objective:to split a circular linklist into two halves
	input parameters:none
	return value:none
	approach:-using floyd cycle algorithm
				using two pointers
				fast_ptr-it moves one step fast as compared to slow_ptr
				slow_ptr-it moves one step slow as compared to fast_ptr
	*/	
	if(head)
	{
	circular c1,c2;
	node *fast_ptr=head,*slow_ptr=head;
	node *head1,*head2;
	
	cout<<"\n\tAFTER SPLITTING:";
	if(head->next==head)	
	{
		c1.head=head;
		c2.head=NULL;
	}
	else
	{
	while(fast_ptr->next!=head&&fast_ptr->next->next!=head)
	{
		fast_ptr=fast_ptr->next->next;
		slow_ptr=slow_ptr->next;
	}
	if(fast_ptr->next->next==head)
		fast_ptr=fast_ptr->next;
	head1=head;
	head2=slow_ptr->next;
	slow_ptr->next=head1;
	fast_ptr->next=head2;
	c1.head=head1;
	c2.head=head2;
	
	}
	cout<<"\n\tFIRST CIRCULAR LINKLIST:";
	c1.display();
	cout<<"\n\tSECOND CIRCULAR LINKLIST:";
	c2.display();
	}
}
int main()
{
	/*
	objective:to split a circular linklist into two halves
	input parameters:
			ele-(integer value)-element to be inserted into cirular linklist
	return value:none
	approach:-using function split
	*/	
	circular c;
	int ele;
	char ch;
		
	do
	{
		cout<<"\n\tENTER ELEMENT:";
		cin>>ele;
		c.add(ele);
		cout<<"\n\twant to enter more(enter y or Y)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	cout<<"\n\tELEMENTS OF CIRCULAR LINKLIST:";
	c.display();
	c.split();
	getch();
}
