#include<iostream.h>
#include<conio.h>
#include<process.h>
class node
{
	private:
	int info;
	node *next;
	friend class linklist;
	public:
	node(int el,node *p=0);
};
node::node(int el,node *p)
{
	info=el;
	next=p;
}

class linklist
{
	node *head;
	node *tail;
	public:
	linklist();
	void addtohead(int ele);
	void addtotail(int ele);
	int deletefromhead();
	int deletefromtail();
	void display();
	void rev();
	void deletenode(int ele);
	void isinlist(int x);
	void deleteeven();
	linklist operator + (linklist &l);
	void add(node *ptr,int ele);
	node *rethead();
	void merge(linklist &l1,linklist &l2);
	int count();
	void sort(int);
};

int linklist::count()
{
node *temp=head;
int c=0;
while(temp!=0)
{
++c;
temp=temp->next;
}
return c;
}
node *linklist::rethead()
{

	return head;
}

void linklist::add(node *ptr,int ele)
{
	if(ptr==0)
	{
	head=new node(ele);
	head->next=0;
	return;
	}
	else if(ptr->next)
	{
		add(ptr->next,ele);
	}
	else
	{
		ptr->next=new node(ele);
		ptr->next->next=0;
	}
}
void linklist::display()
{
	node *i;
	i=head;
	cout<<"\n\n\tCONTENTS OF LINKED LIST : \n\n\t";
	while(i!=0)
	{
		cout<<i->info<<"\t";
		i=i->next;
	}
}
void linklist::merge(linklist &l1,linklist &l2)
{

	node *temp=l1.head;
	node *temp1=l2.head;
	while(temp&&temp1)
	{
		if(temp->info<temp1->info)
		{
			addtotail(temp->info);
			temp=temp->next;


		}
		else if(temp1->info<temp->info)
		{
			addtotail(temp1->info);
			temp1=temp1->next;

		}

	}

	if(temp1)
	{
		while(temp1)
		{
			addtotail(temp1->info);
			temp1=temp1->next;
		}
	}
	else
	{
		while(temp)
		{
			addtotail(temp->info);
			temp=temp->next;
		}
	}

}

linklist::linklist()
{
	head=0;
	tail=0;
}
linklist linklist::operator + (linklist &l)
{
	linklist ll;
	if(head==0 && l.head==0)
	{
		cout<<"\n\n\tLINK LIST IS EMPTY";
		cout<< "\n\n\tIMPOSSIBLE TO C0NCATINATE";

	}


	else if(head==0)
	{
		ll.head=l.head;
		ll.tail=l.tail;


	}
	else if(l.head==0)
	{
		ll.head=head;
		ll.tail=tail;
	}
	else
	{

		ll.head=head;
		tail->next=l.head;
		ll.tail=l.tail;

	}
	return ll;
}

void linklist::sort(int c)
{
int t;
node *temp;
      for(int i=0;i<c-1;i++)
     { for(temp=head;temp!=tail;temp=temp->next)
       if(temp->next->info<temp->info)
	     {
	       t=temp->info;
	       temp->info=temp->next->info;
	       temp->next->info=t;


	     }

	     cout<<"\n\n\tAFTER "<<i+1<<"PASS ";
	     display();
       }
}
void linklist::addtohead(int ele)
{

		 if(head!=0)
		 {
		     head=new node(ele,head);
		 }
		 else
		 {
			head=new node(ele);
			tail=head;
		 }
}
void linklist::addtotail(int ele)
{
	if(tail!=0)
	{
		tail->next=new node(ele);
		tail=tail->next;
	}
	else
	{
		head=new node(ele);
		tail=head;
	}
}
int linklist::deletefromhead()
{    if(head !=0)
  {
     node *temp;
     temp=head;
     int x=temp->info;

     if(head==tail)
     {
     head=0;
     tail=0;
     }
     else
     {
     head=head->next;
     }

     delete temp;
     return x;

  }
     else
     return -1;
}
int linklist::deletefromtail()
{
	if(head!=0)
	{	int x=tail->info;
		if(head==tail)
		{
			delete head;
			head=0;
			tail=0;
		}
		else
		{
			node *temp;
			for(temp=head;temp->next!=tail;temp=temp->next);
			delete tail;
			tail=temp;

		}
		tail->next=0;
		return x;
	}
	else
	return -1;
}

void linklist::deletenode(int ele)
{
	if(head)
	{
		node *temp=head;
		for(temp;temp!=0&&temp->info!=ele;temp=temp->next);
		if(temp->info==ele)
		{
			if(head==tail)
			{
			head=0;
			tail=0;
			}

			else if(temp==head)
			head=head->next;
			else

			{
			    node *ptr=head;
			    for(ptr;ptr->next!=temp;ptr=ptr->next);
			    if(temp==tail)
			    {
			    tail=ptr;
			    tail->next=0;
			    }

			    else
			    {
			    ptr->next=temp->next;
			    }
			}

			delete temp;
		}

	   else
	  {
	  cout<<"\n\n\tELEMENT NOT FOUND SO CANT BE DELETED";
	  }
	}
}

void linklist::deleteeven()
{       int c=0;
	node *temp,*prev,*t;
	temp=head;
	while(temp)
	 {
		++c;
		if(c%2==0)
		{
			for(prev=head;prev->next!=temp;prev=prev->next);
			if(temp!=tail)
			{
				prev->next=temp->next;
				delete temp;
				temp=prev->next;
			}
			else
			{
				delete tail;
				tail=prev;
				tail->next=0;
			}
		}
		else
		{
			temp=temp->next;
		}

	  }
}


void linklist::isinlist(int x)
{
	node *temp;
	for(temp=head;temp!=0&&temp->info!=x;temp=temp->next);
	  if(temp==0)
		cout<<"\n\n\tnot FOUND";
	else
	cout<<"\n\n\tFOUND";
	//if(temp->info==x)


}
void linklist::rev()
{
	if(head==0)
	{
		cout<<"\n\n\tLIST IS EMPTY (CAN'T BE REVERSED)";
		return;
	}
	else if(head==tail)
	{
		return;
	}

	else
	{

	node *prev,*temp, *ptr;
	temp=head;
	prev=0;
	while(temp)
	{

		ptr=temp->next;
		temp->next=prev;
		prev=temp;
		temp=ptr;

	 }
	 temp=head;
	 head=tail;
	 tail=temp;
	}
}
void main()
{
	int choice,el,i,n;
	char ch;
	linklist l1,l2,l3;
	do
	{
		clrscr();
		cout<<"\n\n\tS.I.N.G.L.Y. L.I.N.K. L.I.S.T";
		cout<<"\n\n\t-----------------------------";
		cout<<"\n\n\t1.ADD TO HEAD";
		cout<<"\n\n\t2.ADD TO TAIL";
		cout<<"\n\n\t3.DELETE FROM HEAD";
		cout<<"\n\n\t4.DELETE FROM TAIL";
		cout<<"\n\n\t5.ELEMENT TO BE SEARCHED";
		cout<<"\n\n\t6.DELETE A NODE";
		cout<<"\n\n\t7.REVERSE THE LIST";
		cout<<"\n\n\t8.DELETE NODES PRESENT AT EVEN POSITIONS";
		cout<<"\n\n\t9.CONCAT TWO LISTS";
		cout<<"\n\n\t10.MERGE TWO LINK LISTS";
		cout<<"\n\n\t11.ADD TO TAIL RECURSIVELY ASSUMING TAIL POINTER IS NOT AVAILABLE";
		cout<<"\n\n\t12.COUNT NO OF NODES";
		cout<<"\n\n\t13.SORT THE LINKLIST";
		cout<<"\n\n\t13.EXIT";
		cout<<"\n\n\tENTER YOUR CHOICE";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"\n\n\tENTER THE ELEMENT : ";
			       cin>>el;
			       //node n(el,0);
			       l1.addtohead(el);
			       l1.display();
			       break;
			case 2:cout<<"\n\n\tENTER THE ELEMENT : ";
			       cin>>el;
			       l1.addtotail(el);
			       l1.display();
			       break;
			case 3:cout<<"\t"<<l1.deletefromhead();
			       l1.display();
			       break;
			case 4:cout<<"\t"<<l1.deletefromtail();
			       l1.display();
			       break;
			case 5:cout<<"\n\n\tENTER THE ELEMENT TO BE SEARCHED : ";
			       cin>>el;
			       l1.isinlist(el);
			       l1.display();
			       break;
			case 6:cout<<"\n\n\tENTER THE ELEMENT TO BE DELETED";
			       cin>>el;
			       l1.deletenode(el);
			       l1.display();
			       break;
			case 7:l1.rev();
			       l1.display();
			       break;
			case 8:l1.deleteeven();
			       cout<<"\n\n\tAFTER DELETING NEW LIST IS : \n\n\t";
			       l1.display();
			       break;

			case 9:cout<<"\n\n\tENTER THE SECOND LIST TO CONCAT";

			       cout<<"\n\n\tHOW MANY ELEMENTS YOU WANT?";
			       cin>>n;
			       for(i=0;i<n;i++)
			       {
					cout<<"\n\n\tENTER ";
					cin>>el;
					l2.addtohead(el);
			       }

			       l1=l1+l2;
			       l1.display();
			       break;

			case 10:
				clrscr();
				cout<<"\n\n\tENTER THE SECOND LIST TO MERGE";
			       cout<<"\n\n\tHOW MANY ELEMENTS YOU WANT?";
			       cin>>n;
			       for(i=0;i<n;i++)
			       {

					cout<<"\n\n\tENTER ";
					cin>>el;
					l2.addtotail(el);
					l2.display();
			       }

			       l3.merge(l1,l2);
			       l3.display();
			       break;

			case 11:cout<<"\n\n\tENTER THE ELEMENT : ";
			       cin>>el;
			       l1.add(l1.rethead(),el);
			       l1.display();
			       break;

			case 12:cout<<"\n\n\tNO OF NODES ARE "<<l1.count();
				break;

			case 13:cout<<"\n\n\tAFTER SORTING";
				l1.sort(l1.count());
				break;

			default:cout<<"\n\n\tEXITING";exit(0);
			       break;
		}

		cout<<"\n\n\tDO U WANT TO CONTINUE?";
		cin>>ch;
		
	}while(ch=='Y'||ch=='y');
	getch();
}


