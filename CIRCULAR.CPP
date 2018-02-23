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

	node *tail;
	public:
	linklist()
	{
		tail=0;
	}

	void insert(int ele);
	void display();
	void reverse();
	void isinlist(int ele);
	int t_delete();
	void delete_p(int ele);

};



void linklist::insert(int ele)
{

     if(tail==0)
     {
	tail=new node(ele);
	tail->next=tail;
     }

     else
     {
	tail->next=new node(ele,tail->next);
	tail=tail->next;
     }
}

void linklist::display()
{

	node *temp=tail;
	if(temp)
	{
		cout<<"\n\n\tCONTENTS OF CIRCULAR LINKLIST IS AS FOLLOWS";

		while(temp->next!=tail)
		{
			cout<<"  "<<temp->info;
			temp=temp->next;
		}
		cout<<" "<<temp->info;
       }

       else
       {
	cout<<"\n\n\tLINKLIST IS EMPTY";
       }
}

void linklist::isinlist(int ele)
{

	node *temp=tail;
	for(temp;temp->next!=tail&&temp->info!=ele;temp=temp->next);
	{
		 if(temp->info==ele)
		 {
			cout<<"\n\n\tFOUND";
		 }

		 else
		 {
			cout<<"\n\n\tNOT FOUND";
		 }
	}
}

void linklist::reverse()
{
	if(tail)
	{
		if(tail==tail->next)
		{
			return;
		}

		else
		{
			node *temp,*ptr,*prev,*p;
			prev=tail;
			temp=tail->next;
			p=tail->next;
			while(temp!=tail)
			{
			    ptr=temp->next;
			    temp->next=prev;
			    prev=temp;
			    temp=ptr;
			 }


			    ptr=temp->next;
			    temp->next=prev;
			    prev=temp;
			    temp=ptr;

			    tail=p;

		}

       }
}


void linklist::delete_p(int ele)
{

	if(tail)
	{

		if(tail==tail->next&&tail->info==ele)
		{
			tail=0;
			return;
		}

		else
		{

		node *temp=tail;

		for(temp;temp->next!=tail&&temp->info!=ele;temp=temp->next);

		if(temp->info==ele)
		{


					if(temp==tail)
					{
						tail=tail->next;
					}

					else
					{       node *ptr;
						for(ptr=tail;ptr->next!=temp;ptr=ptr->next);
						ptr->next=temp->next;

					}

				delete temp;


		}

		else
		{
			cout<<"\n\n\tELEMENT NOT FOUND IN THE LIST";
		}
	     }
	  }
}

int linklist::t_delete()
{
     if(tail)
     {
	node *ptr,*temp;
	ptr=tail;
	int x=ptr->info;

	if(tail==tail->next)
		tail=0;

	else
	{
		for(temp=tail;temp->next!=tail;temp=temp->next);
		temp->next=tail->next;
		tail=tail->next;
	}

	delete ptr;
	return x;
     }
     else return -1;
}

void main()
{
	int choice,ele;
	char ch;
	linklist l1;
	do
	{
		clrscr();
		cout<<"\n\n\tC.I.R.C.U.L.A.R.. L.I.N.K. L.I.S.T";
		cout<<"\n\n\t-----------------------------";
		cout<<"\n\n\tPRESS 1 TO ADD TO TAIL";
		cout<<"\n\n\tPRESS 2 TO SEARCH ANY ELEMENT";
		cout<<"\n\n\tPRESS 3 TO DELETE TAIL";
		cout<<"\n\n\tPRESS 4 TO REVERSE";
		cout<<"\n\n\tPRESS 5 TO DELETE A PARTUICULAR ELEMENT";
		cout<<"\n\n\tENTER YOUR CHOICE";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"\n\n\tENTER THE ELEMENT : ";
			       cin>>ele;
			       l1.insert(ele);
			       l1.display();
			       break;

			case 2:cout<<"\n\n\tENTER THE ELEMENT WANT TO SEARCH FOR : ";
			       cin>>ele;
			       l1.isinlist(ele);
			       l1.display();
			       break;

			case 3:cout<<"\n\n\tDELETED ELEMENT IS "<<l1.t_delete();
			       break;

			case 4:l1.reverse();
			       cout<<"\n\n\tAFTER REVERSING \n";
			       l1.display();
			       break;

		       case 5:cout<<"\n\n\tENTER ELEMENT DO YO WANT TO DELETE";
			      cin>>ele;
			      l1.delete_p(ele);
			      l1.display();
			      break;

			default:exit(0);

		}

		cout<<"\n\n\tDO U WANT TO CONTINUE?";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	getch();
}

