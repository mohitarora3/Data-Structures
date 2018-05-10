#include <iostream>
#include<conio.h>
#include <cstdlib>


#define SIZE 10



using namespace std;



class queue 
	/*   			

	objective: Create a class to implement Queue(circular) using dynamically created array 

	input parameters: none

	output value: none

	description:  Class definition

	approach: Class definition provides data member and member functions for the Queue class

	*/


{

	int *arr;			// array to store queue elements

	int capacity;			// maximum capacity of the Q

	int front;			// front points to front element in the Q

	int rear;			// rear points to last element in the Q

	int count;			// current size of the Q



public:

	queue(int size = SIZE)			// constructor
	{
		arr=new int[size];
		capacity=size;
		front=-1;
		rear=-1;
		count=0;
	}
	~queue()
	{
		delete []arr;	
	}	

	int dequeue();

	void enqueue(int);

	int peek();  				// returns front element

	int size();				// returns current size of Q

	bool isEmpty();

	bool isFull();

};

void queue::enqueue(int ele)
{
	if((front==0&&rear==capacity-1)||front==rear+1)
		{
			cout<<"OVERFLOW";
			return;
			
		}
		else if(rear==-1)
		{
		    rear=front=0;
		    arr[rear]=ele;
		    ++count;
		}
		else {
		
			rear=(rear+1)%capacity;
			arr[rear]=ele;
			++count;
		}
}


int queue::dequeue()
{
	int x;
	if(front==-1&&rear==-1)
		{
			return -1;
		}
		else
		{
			--count;
			x=arr[front];
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else front=(front+1)%capacity;
			return x;
		}
}

int queue::peek()
{
	if(count==0)
	{
		return -1;
	}
	return arr[front];
}


int queue::size()
{
	return count;
}

bool queue::isEmpty()
{
	return(count==0);
}

bool queue::isFull()
{
	return (count==capacity);
}

int main()
{
	/*
	objective:to implement queue operations
	*/
	int ch,n,ele,x;
	bool ans;
	char c;
	cout<<"Enter size";
	cin>>n;
	queue q(n);
	do
	{
	cout<<"STACK IMPLEMENTATION::";
	cout<<"\n1.ENQUE";
	cout<<"\n2.DEQUE";
	cout<<"\n3.TOPMOST ELEMENT";
	cout<<"\n4.CURRENT SIZE";
	cout<<"\n5.IS QUEUE EMPTY?";
	cout<<"\n6.IS QUEUE FULL?";
	cout<<"\n\tenter your choice";
	cin>>ch;
	
	switch(ch)
	{
		
		case 1:cout<<"\nEnter element";
				cin>>ele;
				q.enqueue(ele);
				break;
				
		case 2:x=q.dequeue();
				if(x==-1)
				{
					cout<<"\nUNDERFLOW!";
					
				}	
				else			
				cout<<"\nPOPPED ELEMENT IS: "<<x;
				break;
		
		case 3:x=q.peek();
				if(x==-1)
				{
					cout<<"\nUNDERFLOW!";
					
				}	
				else
					cout<<"\nPEEKED ELEMENT IS: "<<x;
				break;
		case 4:x=q.size();
				cout<<"\nCURRENT SIZE is: "<<x;
				break;
		case 5:ans=q.isEmpty();
				if(ans)
					cout<<"\nSTACK IS EMPTY";
				else
					cout<<"\nSTACK IS NOT EMPTY";
				break;
		case 6:ans=q.isFull();
				if(ans)
					cout<<"\nSTACK IS FULL";
				else
					cout<<"\nSTACK IS NOT FULL";
				break;
		default:cout<<"\nWRONG CHOICE!!";
				exit(0);
				
	}
	cout<<"\nwant to continue (enter Y or Y) ";
	cin>>c;	
	}while(c=='y'||c=='Y');
	
	

getch();
	
}
