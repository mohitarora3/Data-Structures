#include<iostream.h>
#include<conio.h>
#include<process.h>

class node
{
	int info;
	node *next;
	node *prev;
	friend class linklist;
	public:
	node(int x,node *ptr1=0,node *ptr2=0)
	{

		info=x;
		next=ptr1;
		prev=ptr2;
	}
};
class linklist
{
	node *head;
	node *tail;
	public:
	linklist()
	{
	head=0;
	tail=0;
	}
	void addtohead(int ele);
	void addtotail(int ele);
	int deletefromhead();
	int deletefromtail();
	void deleteanode(int ele);
	void rev();
	void display();

}l1;

void linklist::addtohead(int ele)
{
	head=new node(ele,head,0);
	if(tail!=0)
	 head->next->prev=head;
	
	else  //tail will be head otherwise
	 tail=head;
	
}
int linklist::deletefromhead()
{
	if(head!=0)
	{
		node *p=head;
		int x=p->info;
		if(head==tail)
		{
			head=0;
			tail=0;
		}
		else
		{
			p->next->prev=0;
			head=head->next;
		}
		delete p;
		return x;
	}
	else
	return -1;
}

int linklist::deletefromtail()
{
if(tail!=0)
 {
	node *p=tail;
	int x=tail->info;

	if(head==tail)
	{
		head=0;
		tail=0;
	}

	else
	{
		tail=tail->prev;
		tail->next=0;
	}

	delete p;
	return x;

 }
 else
 {
 return -1;
 }
}

void linklist::addtotail(int ele)
{
	tail=new node(ele,0,tail);
	
	if(head!=0)
	{
		tail->prev->next=tail;
	}
	else
	head=tail;
}

void linklist::deleteanode(int ele)
{
	if(head!=0)
	{
		node *tmp=head;
		if(head==tail&&head->info==ele)
		{
			head=0;
			tail=0;
			delete  tmp;
		}
		else
		{
			for( ;(tmp!=0&&tmp->info!=ele);tmp=tmp->next);

			 if(tmp==0)
				cout<<"\n\n\tNOT FOUND";

			 else
			 {
			  if(tmp!=0&&tmp==head)
			  {
				tmp->next->prev=0;
				head=head->next;
				delete tmp;

			  }

			  else if(tmp!=0&&tmp==tail)
			  {
				tmp->prev->next=0;
				tail=tail->prev;
				delete tmp;
			  }

			  else if(tmp->info==ele)
			  {
				tmp->prev->next=tmp->next;
				tmp->next->prev=tmp->prev;
				delete tmp;

			  }
			  cout<<"\n\n\tELEMENT DELETED";

			 }



		 }

		}
	else
	{cout<<"\n\n\tELEMENT NOT FOUND";
	}

}
void linklist::display()
{
	node *tmp;
	tmp=head;
	cout<<"\n\n\tCONTENTS ARE : ";
	while(tmp!=0)
	{
		cout<<tmp->info<<"\t";
		tmp=tmp->next;
	}
}

void linklist::rev()
{
	node *temp,*t;
	temp=head;
	while(temp!=0)
	{
		t=temp->next;
		temp->next=temp->prev;
		temp->prev=t;
		temp=temp->prev;
	}
	t=head;
	head=tail;
	tail=t;

}
void main()
{

	clrscr();
	int choice,x,ele;
	char ch;
	do
	{
		clrscr();
		cout<<"\n\n\tD.O.U.B.L.Y. L.I.N.K. L.I.S.T";
		cout<<"\n\n\t-----------------------------";
		cout<<"\n\n\t1.ADD TO HEAD";
		cout<<"\n\n\t2.ADD TO TAIL";
		cout<<"\n\n\t3.DELETE FROM HEAD";
		cout<<"\n\n\t4.DELETE FROM TAIL";
		cout<<"\n\n\t5.DELETE A NODE";
		cout<<"\n\n\t6.REVERSE THE LIST";
		cout<<"\n\n\t7.EXIT";
		cout<<"\n\n\tENTER YOUR CHOICE";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"\n\n\tENTER THE ELEMENT : ";
			       cin>>x;
			       l1.addtohead(x);
			       l1.display();
			       break;
				
			case 2:cout<<"\n\n\tENTER THE ELEMENT : ";
			       cin>>x;
			       l1.addtotail(x);
			       l1.display();
			       break;
				
			case 3:cout<<"\n\n\tDELETED ITEM IS : ";
			       cout<<"\t"<<l1.deletefromhead();
			       cout<<"\n\n\tAFTER DELETING\n\n\t_______________________";
			       l1.display();
			       break;
				
			case 4:cout<<"\n\n\tDELETED ITEM IS : ";
			       cout<<"\t"<<l1.deletefromtail();
			       cout<<"\n\n\tAFTER DELETING\n\n\t_______________________";
			       l1.display();
			       break;
				
			case 5:cout<<"\n\n\tENTER ELEMENT TO BE DELETED : ";
			       cin>>ele;
			       l1.deleteanode(ele);
			       l1.display();
			       break;
				
			case 6:l1.rev();
			       l1.display();
			       break;
				
			case 7:exit(0);
			       break;
		}
		cout<<"\n\n\tDO U WANT TO CONTINUE?";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	getch();
}
