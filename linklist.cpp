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
	bool empty() const; 					// is list empty?
	const string& front() const; 			// get front element
	void addFront(const string& e); 		// add to front of list
	void addBack(const string& e); 			// add to back of list
	void removeFront();			 			// remove from front 
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	private:
	SNode* head; 							// pointer to the head of list
};

SlinkedList::SLinkedList()
{
	head=0;
}

bool SLinkedList::empty()
{
	if(head==0)
 	   return TRUE;
	else 
		 return FALSE; 
}

string SLinkedList::front()
{
	return head;
}

void SLinkedList::addFront(String &e)
{
	if(head==0)
 			   head=new node(e);
    else
    	head=new node(e,head);
    	
}
void SLinkedList::addBack(String &e)
{
	if(head==0)
			   head=new node(e);
    else
    {
    	node *prev,*temp=head;
    	while(temp)
    	{
		    prev=temp;
    		temp=temp->next;
		}
		prev->next=new node(e);
	}
}
void SLinkedList::removeFront()
{
	if(!head)
			 cout<<"\n\tUNDERFLOW";
    else 
    {
    	node *temp=head;
    	if(head->next==0)
				 {
				 	head=0;
				 }
        else
        	head=head->next;
	    delete temp;
    }
}
    	
void SLinkedList::removeBack()
{
    if(!head)
       cout<<"\n\tUNDERFLOW";
    else 
    {
	    node *prev,*temp=head;
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
	node *temp=head;
	while(temp)
	{
		cout<<temp->elem<<" ";
	}
}
