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
	friend class linkedlist;
	public:
		node()
		{
			next=0;
		}
		node(int ele,node *ptr=0)
		{
			info=ele;
			next=ptr;
		}
};
class linkedlist
{
	/*
	objective: Create a class for implementing linklist
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the linkedlist class
	*/

	node *head;
	node *tail;
	public:
		linkedlist()
		{
			head=0;
			tail=0;
		}
		void add_to_tail(int ele);
		void reverse_consec();
		void display();
};
void linkedlist::add_to_tail(int ele)
{
	/*
	objective:to insert element at the end of the linklist
	input parameters:
		ele-(integer value)-element to be inserted into linklist
	return value:none
	*/	
	if(head==0)
	{
		head=new node(ele);
		tail=head;
	} 
	else
	{
		tail->next=new node(ele);
		tail=tail->next;
	}
	
}
void linkedlist::display()
{
	/*
	objective:to display elements of linklist
	input parameters:none
	return value:none
	approach:-starting from head display every element of linklist
	*/	
	node *temp=head;
	while(temp)
	{
		cout<<temp->info;
		temp=temp->next;
		
	}
}
void linkedlist::reverse_consec()
{
	/*
	objective:reverse the linklist in pairs
	input parameters:none
	return value:none
	approach:-starting from head swap elements of every pair
	*/	
	
	int t;
	node *temp=head;
	while(temp&&temp->next!=0)
	{
		t=temp->info;
		temp->info=temp->next->info;
		temp->next->info=t;
		temp=temp->next->next;
	}
	
}
	
int main()
{
	/*
	objective:reverse the linklist in pairs
	input parameters:
		ele-(integer value)-element to be inserted into linklist
	return value:none
	approach:-by invoking function reverse_consec()
	*/	
	
	linkedlist l;
	int ele;
	char ch;
		
	do
	{
		cout<<"\n\tENTER ELEMENT:";
		cin>>ele;
		l.add_to_tail(ele);
		cout<<"\n\twant to enter more(enter y or Y)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	cout<<"\n\tLINKLIST IS:";
	l.display();
	l.reverse_consec();
	cout<<"\n\tAFTER REVERSING CONSECUTIVE ELEMENTS:";
	cout<<"\n\tLINKLIST IS:";
	l.display();
	getch();
}
