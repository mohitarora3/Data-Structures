#include<iostream>
#include<conio.h>
using namespace std;
class node
{
	int info;
	node *right;
	node *left;
	friend class binary;
	public:
		node()
		{
			right=0;
			left=0;
		}
		node(int ele,node *p=0,node *t=0)
		{
			info=ele;
			left=p;
			right=t;
		}
	
};

class binary
{
	
	node *root;
	int count;
	
	public:
	binary()
	{
		root=0;
		count=0;
	}
	void insert(int,node *);
	void display();
	node *ret_root(){
		return root;
	}
	
};
void binary::insert(int ele,node *r)
{
	if(r==0)
		{
			r=new node(ele);
			++count;	
		}
	else if(ele>r->info)
			insert(ele,r->right);
	else if(ele<r->info)
			insert(ele,r->left);
	
}
void binary::display()
{
	if(root)
	{
	int i=0;
	node *a=new node[count];
	node *temp=root;
	a[i]=temp;
	while(i<count)
	{
		temp=a[i];
		cout<<a[i]->info<<" ";
		if(temp->left)
			a[++i]=temp->left;
			
		if(temp->right)
			a[++i]=temp->right;
	}
	
}
int main()
{
	binary b;
	int n;
	cout<<"\n\tEENTER SIZE:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		coin>>ele;
		b.insert(ele,b.ret_root());
	}
	b.display();
	getch();	
}
