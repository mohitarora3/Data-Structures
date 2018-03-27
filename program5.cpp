#include<iostream>
#include<conio.h>
using namespace std;
class node
{
	int info;
	node *next;
	friend class circular;
	
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

class circular
{
	node *head;
	
	public:
		circular()
		{
			head=0;
		}
	void add(int);
	void display();
	int eliminate(int);
};


int circular::eliminate(int m)
{
	/*
	objective:to select a leader among n persons sitting in a circle by eliminating mth element again and again
	input parameters:
				m-(integer value)-it represents person number to be eliminated
	return value:-(integer value)-person number who is elected as a leader
	approach:while there is not a single element in the circular linklist
				1.select previous node of mth node
				2.insert mth next into previous next
				3.delete mth node
	*/
	if(head->next==head)
	{
		return head->info;
	}
	node *temp,*prev=head;
	temp=head->next;
	while(temp->next!=temp)
	{
	
		for(int i=0;i<m-1;i++)
		{	
			prev=temp;
			temp=temp->next;
		}
		prev->next=temp->next;
		delete temp;
		temp=prev->next;
	}
	return temp->info;
}
void circular::add(int ele)
{
	if(head==0)
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
	node *temp=head;

	while(temp&&temp->next!=head)
	{
		cout<<temp->info;
		temp=temp->next;
	}
	cout<<temp->info;	
}
int main()
{
	/*
	objective:to select a leader among n persons sitting in a circle by eliminating mth element again and again
	input parameters:
			n-(integer value)-number of persons among whom leader is to be chosen
			m-(integer value)-it represents person number to be eliminated
	return value:none
	approach:by invoking function eliminate
	*/
	circular c;
	int n,m,ele;
	cout<<"\n\tENTER SIZE(number of persons):";
	cin>>n;
	for(int i=1;i<=n;i++)
		c.add(i);
	cout<<"\n\tELEMENTS OF CIRCULAR LINKLIST:";
	c.display();
	cout<<"\n\tENTER M:";
	cin>>m;
	cout<<"\n\tLEADER IS:"<<c.eliminate(m)<<"th person (i.e the last person remaining)";
	getch();
}
