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
	node *tail;
	
	public:
		circular()
		{
			tail=0;
		}
	void add(int);
	void display();
	int eliminate(int);
};


int circular::eliminate(int m)
{
	node *temp,*prev=0;
	temp=tail;
	while(temp->next!=temp)
	{
	
		for(int i=0;i<m;i++)
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
	if(tail==0)
		{
		tail=new node(ele);
		tail->next=tail;
	}
	else
		{
			
				tail->next=new node(ele,tail->next);
			//	tail->next->next=tail;
				tail=tail->next;

		}
}
void circular::display()
{
	node *temp=tail;

	while(temp&&temp->next!=tail)
	{
		cout<<temp->info;
		temp=temp->next;
	}
	cout<<temp->info;	
}
int main()
{
	circular c;
	int m,n,ele;
	cout<<"\n\tEnter size of circular linklist";
	cin>>n;
	cout<<"\n\tENTER ELEMENT";
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		c.add(ele);
	}
	cout<<endl;
	c.display();
	cout<<"\n\tENTER M";
	cin>>m;
	cout<<"\n\tELEMENT OF RANK 1 IS:"<<c.eliminate(m);
	getch();
}
