
#include<iostream.h>
#include<conio.h>
#include<process.h>
class node
{
	private:
	int info;
	node *next;
	node *prev;
	friend class doubly;
	public:
	node(int ele,node *p=0 ,node *ptr=0)
	{
		info=ele;
		prev=p;
		next=ptr;
	}
};

class doubly
{


	node *tail;

	public:
	doubly()
	{

		tail=0;
	}

	void addtotail(int ele);
	void display();

};

void doubly::display()
{
	 node *temp=tail;
	 cout<<temp->info;
	 temp=temp->next;
	 while(temp!=tail)
	 {
		cout<<"  "<<temp->info;
		temp=temp->next;
	 }
}


void doubly::addtotail(int ele)
{
	if(tail==0) //if no tail
	{
		tail=new node(ele);
		tail->next=tail;
		tail->prev=tail;
	}

	else
	{
		tail->next=new node(ele,tail,tail->next);
		tail=tail->next;
	}

}




void main()
{
	clrscr();
	int ch,ele;
	char c;
	doubly l1;
	do
	{
		clrscr();
		cout<<"\n\n\tC.I.R.C.U.L.A.R.. L.I.N.K. L.I.S.T";
		cout<<"\n\n\t-----------------------------";
		cout<<"\n\n\tPRESS 1 TO ADD TO TAIL";
		cout<<"\n\n\tPRESS 2 TO SEARCH ANY ELEMENT";
		cout<<"\n\n\tENTER YOUR CHOICE";
		cin>>ch;

		switch(ch)
		{

		case 1:cout<<"\n\n\tENTER ELEMENT U WANT TO INSERT";
		       cin>>ele;
		       l1.addtotail(ele);
		       l1.display();
		       break;

                default:exit(0);

		}

		cout<<"\n\n\tDO U WANT TO CONTINUE OR WANT TO EXIT?";
		cin>>c;
	}while(c=='Y'||c=='y');
	getch();
}

