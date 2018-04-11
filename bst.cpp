#include<iostream>
#include<conio.h>
using namespace std;
class node
{
	int info;
	node *left;
	node *right;
	
	public:
		friend class bst;
		node(int ele,node *ptr=NULL,node *ptr1=NULL)
		{
			info=ele;
			left=ptr;
			right=ptr1;
		}
};

class bst
{
	node *root;
	
	public:
		bst()
		{
			root=NULL;
		}
		void insert(int);
		node *search(node *,int);
		void inorder(node *);
		node *ret_root()
		{
			return root;
		}
};

void bst::insert(int ele)
{
	if(root==NULL)
     			  root=new node(ele);
    node *ptr=root,*prev=root;
    while(ptr)
    {
    	if(ele>ptr->info)
    	{
    		prev=ptr;
    		ptr=ptr->right;
		}
		else
		{
			prev=ptr;
			ptr=ptr->left;
		}
	}
	if(ele>prev->info)
    				  prev->right=new node(ele);
    else
    	prev->left=new node(ele);
    	
}

node *bst::search(node *r,int ele)
{
	if(r==NULL)
				  return NULL;
     else if(r->info==ele)
     	  return root;
     else if(ele>r->info) 
	 	  return search(r->right,ele);
	 else
	 	 return search(r->left,ele);
		   	  	  
}

void bst::inorder(node *r)
{
	if(r)
	{
	inorder(r->left);
	cout<<r->info;
	inorder(r->right);
	}
}
int main()
{
	bst b;
	int ele,ch;
	char c;
	do
	{
		cout<<"\n\tBINARY SEARCH TREE";
		cout<<"\n\t1.INSERT";
		cout<<"\n\t2.DISPLAY(inorder)";
		cout<<"\n\t3.SEARCH";
		cout<<"\n\tENTER YOUR CHOICE";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"\n\tENTER ELEMENT";
				 cin>>ele;
				 b.insert(ele);
				 break;
	 		 case 2:b.inorder(b.ret_root());
	 		 	  break;
	 	     case 3:cout<<"\n\tENTER ELEMENT";
				 cin>>ele;
				 if(b.search(b.ret_root(),ele))
				 			 cout<<"\n\tELEMENT FOUND";
				 else
				 	 cout<<"\n\tELEMENT NOT FOUND";
		 	 break;
		 	 default:cout<<"\n\tWRONG CHOICE";
		 	 
		}
		cout<<"\n\twant to continue (enter y or Y)";
		cin>>c;
	}while(c=='y'||c=='Y');
	
	getch();
}
