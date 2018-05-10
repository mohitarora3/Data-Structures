#include<iostream>
#include<stack>
#include<conio.h>
#define max_size 10
using namespace std;
class queue
{
	stack<int> s1,s2;
	int curr_size;
	public:
		void enque(int);
		int deque();
		bool isempty();
		int size()
		{
			return curr_size;
		}
};


void queue::enque(int ele)
{
	s1.push(ele);
}

int queue::deque()
{
	if(s1.size()==0)
		return -1;
	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	stack<int> s;
	int x=s2.top();
	s2.pop();
	s=s1;
	s1=s2;
	s2=s;
	return x;
}
bool queue::isempty()
{
	return (s1.top()=-1);
}

int main()
{
	int x,ele,ch;
	char c;
//	queue q;
	///*
//	q.enque(1);
//	q.enque(2);
//	q.enque(3);
//	cout<<q.deque();
//	cout<<q.deque();
//	cout<<q.deque();
    queue q;
	do{
	cout<<"\n\tQUEUE OPERATIONS USING STACK";
	cout<<"\n\t1.ENQUE";
	cout<<"\n\t2.DEQUE";
	cout<<"\n\tENTER YOUR CHOICE";
	cin>>ch;
	switch(ch)
	{
		case 1:cout<<"\n\tENTER ELEMENT";
				cin>>ele;
				q.enque(ele);
				break;
		case 2:x=q.deque();
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

