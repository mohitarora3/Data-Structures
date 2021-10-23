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
	 string front(); 			// get front element
	void addFront(string e); 		// add to front of list
	void addBack(string e); 			// add to back of list
	void removeFront();			 			// remove from front 
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	private:
	SNode* head; 							// pointer to the head of list
};

class stack
{
	SLinkedList l;
	public:
		void push(string);
		string top();
		void pop();
};
void stack::push(string ele)
{
	l.addFront(ele);	
}
string stack::top()
{
	return l.front();
}
void stack::pop()
{
	l.removeFront();
}
SLinkedList::SLinkedList()
{
	head=0;
}
SLinkedList::~SLinkedList()
{
	head=0;
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
		prev = temp;
    		temp = temp->next;
		}
		prev->next = new SNode(e);
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
	    SNode *prev,*temp=head;
    	while(temp)
    	{
		    prev=temp;
    		temp=temp->next;
		}
		prev->next=0;
	}	
   	
}

void SLinkedList::print()
{
	SNode *temp=head;
	while(temp)
	{
		cout<<temp->elem<<" ";
	}
}

int main()
{
	int choice,i,n;
	string el;
	char ch;
	stack s;
	do
	{
		cout<<"\n\n\tIMPLEMENTATION OF STACK USING S.I.N.G.L.Y. L.I.N.K. L.I.S.T";
		cout<<"\n\n\t-----------------------------";
		cout<<"\n\n\t1.PUSH";
		cout<<"\n\n\t2.TOP ELEMENT";
		cout<<"\n\n\t3.POP";
		cout<<"\n\n\tENTER YOUR CHOICE";
		cin>>choice;
		
		switch(choice)
		{
			case 1:cout<<"\n\n\tENTER THE ELEMENT : ";
			       cin>>el;
			       //node n(el,0);
			       s.push(el);
			       break;
			case 2:cout<<"\n\n\tTOP ELEMENT : ";
			       cout<<s.top();
			       break;
			case 3:s.pop();
			       break;
			
			default:cout<<"\n\tWRONG CHOICE!!";
				break;
		}

		cout<<"\n\n\tDO U WANT TO CONTINUE?";
		cin>>ch;
		
	} while(ch=='Y'||ch=='y');
	getch();
}
