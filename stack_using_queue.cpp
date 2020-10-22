#include<iostream>
#include<conio.h>
#define max_size 10
using namespace std;
class queue
{
	int *a;
	int n;
	int front;
	int rear;
	int curr_size;
	public:
		queue()
		{
			curr_size=0;
			front=-1;
			rear=-1;
			n=max_size;
			a=new int[n];
		}
		void enque(int);
		int deque();
		bool isempty();
		int size()
		{
			return curr_size;
		}
};
class stack
{
	queue q1,q2;
	int curr_size;
	public:
		stack()
		{
			curr_size=0;
		}
		void push(int ele);
		int pop();
};

void stack::push(int ele)
{
	q1.enque(ele);
	++curr_size;
}

int stack::pop()
{
	int a;
	while(!q1.isempty()&&q1.size()!=1)
	{
		a=q1.deque();
		q2.enque(a);
		
	}
	--curr_size;
	int x=q1.deque();
	queue q;
	q=q1;
	q1=q2;
	q2=q;
	return x;
}
void queue::enque(int ele)
{
	if(rear==n-1)
		cout<<"\n\tOVERFLOW!";
	else
		{
		if(front==-1)
		{
			front=0;
		}
		a[++rear]=ele;
		++curr_size;
		}
}

int queue::deque()
{
	if(front==-1)
	{
		cout<<"\n\tUNDERFLOW!";
		return -1;
	}
	else
	{
		int x=a[front];
		--curr_size;		
		if(front==rear)
		{
			front=rear=-1;
		}	
		else
			++front;
		return x;

	}
}
bool queue::isempty()
{
	return (front==-1);
}

int main()
{
	int x,ele,ch;
	char c;
	
    stack s;
	do{
	cout<<"\n\tSTACK OPERATIONS USING QUEUE";
	cout<<"\n\t1.PUSH";
	cout<<"\n\t2.POP";
	cout<<"\n\tENTER YOUR CHOICE";
	cin>>ch;
	switch(ch)
	{
		case 1:cout<<"\n\tENTER ELEMENT";
				cin>>ele;
				s.push(ele);
				break;
		case 2:x=s.pop();
				if(x!=-1)
					cout<<"\n\tPOPPED ELEMENT IS:"<<x;
				break;

		default:cout<<"\n\tWRONG CHOICE!";
				break;
	}
	cout<<"\n\twant to continue(enter y or Y)";
	cin>>c;
}while(c=='y'||c=='Y');

getch();
}
