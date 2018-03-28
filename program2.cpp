#include<iostream>
#include<stack>
#include<conio.h>
using namespace std;
void check(stack <int>s)
{
	/*
	objective:given a stack of integers,check whether each successive pair of numbers in the stack is consecutive or not.
	input parameters:
		s-integer object of stack
	return value:none
	approach:-if size of stack is odd
				pop an element from stack
				while stack is not empty
					pop two elements from stach 
						check whether they are consecutive or not
							if elements of atleast one pair is not consecutive
								print FALSE
							otherwise
								print TRUE
	*/	
	
	int a,b,temp=1;
	if(s.size()==0)
		cout<<"ERROR!! (stack is empty)";
	else if(s.size()==1)
		cout<<"ERROR!! (ELEMENTS SHOULD BE ATLEAST 2)";
	
	else
	{
		
	if(s.size()%2!=0)
		s.pop();
	while(!s.empty())
	{
		a=s.top();
		s.pop();
		b=s.top();
		s.pop();
		if(a!=b-1&&a!=b+1)
		{
			temp=0;
			break;
		}
			
	}	
	if(temp)
		cout<<"\tTRUE";
	else
		cout<<"\tFALSE";
	}
}
int main()
{
	/*
	objective:given a stack of integers,check whether each successive pair of numbers in the stack is consecutive or not.
	input parameters:
		n-(integer value)-number of elements to be pushed into stack
		ele-(integer value)-element to be pushed into stack
	return value:none
	approach:-by calling function check
	*/	
	stack <int>s;
	int ele,n;
	cout<<"\n\tENTER SIZE(how much elements do want to insert into stack)";
	cin>>n;
	cout<<"\n\tENTER ELEMENTS:";
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		s.push(ele);
	}
	check(s);
	getch();
}
