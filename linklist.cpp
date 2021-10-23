#include<iostream>
#include<conio.h>
using namespace std;


class SNode { 
	/*   			
	objective: Create a class for a Node for Single Linked list
	input parameters: none
	output value: none
	description: SNode class defines the node structure 
	approach: Class defines data item is names element with datatype string 
			and link is named next pf snode type
	*/
	private:
	  string elem; 
	  SNode* next; 
	friend class SLinkedList; // provides SLinkedList access to SNode
	public:
		SNode()
		{
			next=0;
		}
		SNode(string str,SNode *ptr=0)
		{
			elem=str;
			next=ptr;
		}
};



class SLinkedList { 
	/*   			
	objective: Create a Single LInked List class 
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/						
	public:
	SLinkedList();							// empty list constructor
	~SLinkedList();							// destructor
	bool empty() ; 					// is list empty?
	string front() ;			// get front element
	void addFront(string e); 		// add to front of list
	void addBack(const string e); 			// add to back of list
	void removeFront();			 			// remove from front 
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	private:
	SNode* head; 							// pointer to the head of list
};

SLinkedList::SLinkedList()
{
	head=0;
}
SLinkedList::~SLinkedList()
{
	delete head;
}

 bool SLinkedList::empty() 
{
	if(head==0)
 	   return true;
	else 
		 return false; 
}

string SLinkedList::front() 
{
    if(head)
	return head->elem;
	cout<<"\n\tLINKLIST IS EMPTY";
	return "";
}

void SLinkedList::addFront(string e)
{
	if(head==0)
 			   head=new SNode(e);
    else
    	head=new SNode(e,head);
    	
}
void SLinkedList::addBack(string e)
{
	if(head==0)
			   head=new SNode(e);
    else
    {
    	SNode *prev,*temp=head;
    	while(temp)
    	{
		    prev=temp;
    		temp=temp->next;
		}
		prev->next=new SNode(e);
	}
}
void SLinkedList::removeFront()
{
	if(!head)
			 cout<<"\n\tUNDERFLOW";
    else 
    {
    	SNode *temp=head;
    	if(head->next==0)
				 {
				 	head=0;
				 }
        else
        	head=head->next;
	    delete temp;
    }
}
    	
void SLinkedList::removeEnd()
{
    if(!head)
       cout<<"\n\tUNDERFLOW";
    else 
    {
        if(head->next==0)
        {
            delete head;
            head=0;
            return;
        }
        
	    SNode *prev,*temp=head;
    	while(temp->next)
    	{
		    prev=temp;
    		temp=temp->next;
		}
		delete temp;
		prev->next=0;
	}	
   	
}

void SLinkedList::print()
{
	SNode *temp=head;
	while(temp)
	{
		cout<<temp->elem<<" ";
		temp=temp->next;
	}
}

int main()
{
	int choice,i,n;
	string el;
	char ch;
	SLinkedList l;
	do
	{
		clrscr();
		cout<<"\n\n\tS.I.N.G.L.Y. L.I.N.K. L.I.S.T";
		cout<<"\n\n\t-----------------------------";
		cout<<"\n\n\t1.ADD TO HEAD";
		cout<<"\n\n\t2.ADD TO TAIL";
		cout<<"\n\n\t3.DELETE FROM HEAD";
		cout<<"\n\n\t4.DELETE FROM TAIL";
		cout<<"\n\n\t5.FRONT ELEMENT";
		cout<<"\n\n\t6.IS LIST EMPTY";
		cout<<"\n\n\t7.DISPLAY";
		cout<<"\n\n\t13.EXIT";
		cout<<"\n\n\tENTER YOUR CHOICE";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"\n\n\tENTER THE ELEMENT : ";
			       cin>>el;
			       //node n(el,0);
			       l.addFront(el);
			       l.print();
			       break;
			case 2:cout<<"\n\n\tENTER THE ELEMENT : ";
			       cin>>el;
			       l.addBack(el);
			       l.print();
			       break;
			case 3:l.removeFront();
			       l.print();
			       break;
			case 4:l.removeEnd();
			       l.print();
			       break;
			case 5:cout<<"\n\n\tFRONT ELEMENT:";
			       el=l.front();
			       cout<<el;
			       break;
			case 6:if(l.empty())
				 cout<<"\n\tLINKLIST IS EMPTY";
			        else
			        	cout<<"\n\tLINKLIST IS NOT EMPTY";
			       break;
			case 7:l.print();
			       break;

			default:cout<<"\n\tWRONG CHOICE!!";
				break;
		}

		cout<<"\n\n\tDO U WANT TO CONTINUE OR WANT TO EXIT?";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	getch();
}
