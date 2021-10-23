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
		node()
		{
			left=NULL;
			right=NULL;
		}
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
		void preorder(node *);
		void postorder(node *);
		void find_delete(int);
		void delete_by_copy(node *&);
		node *ret_root()
		{
			return root;
		}
};

void bst::insert(int ele)
{
	if(root==NULL)
    {
	  root=new node(ele);
	  return;
	}
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


void bst::find_delete(int ele)
{
	node *ptr,*prev=NULL;
	ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->info==ele)
			break;
		
		else if(ele>ptr->info)
			{
				prev=ptr;
				ptr=ptr->right;
			}
		else if(ele<ptr->info)
		{
			prev=ptr;
			ptr=ptr->left;
		}
	}
	if(ptr&&ptr->info==ele)
	{
	
	if(ptr==root)
		delete_by_copy(root);
	else if(ptr==prev->right)
		delete_by_copy(prev->right);
	else if(ptr==prev->left)
		delete_by_copy(prev->left);
	}
	else if(root)
		cout<<"\n\tELEMENT NOT FOUND";
	else
		cout<<"\n\tEMPTY TREE";
}

void bst::delete_by_copy(node *&ptr)
{
	node *temp=ptr;
	if(ptr)
	{
		if(ptr->left==NULL)
			ptr=ptr->right;
		else if(ptr->right==NULL)
			ptr=ptr->left;
		else
		{
			node *prev=ptr;
			temp=ptr->left;
			while(temp->right!=NULL)
			{
				prev=temp;
				temp=temp->right;
			}
			ptr->info=temp->info;
			if(prev==ptr)
				prev->left=temp->left;
			else
				prev->right=temp->left;
		

		}
	delete temp;
}
}
void bst::inorder(node *r)
{
	if(r!=NULL)
	{
	inorder(r->left);
	cout<<r->info;
	inorder(r->right);
	}
	else
		return;
}

void bst::preorder(node *root)
{
	if(root)
	{
		cout<<root->info;
		preorder(root->left);
		preorder(root->right);
	}
	else
		return;
}
void bst::postorder(node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->info;
		
	}
	else
		return;
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
		cout<<"\n\t3.DISPLAY(preorder)";
		cout<<"\n\t4.DISPLAY(postorder)";
		cout<<"\n\t5.SEARCH";
		cout<<"\n\t6.DELETE";
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
	  		case 3:b.preorder(b.ret_root());
	 		 	  break;
	 		case 4:b.postorder(b.ret_root());
	 		 	  break;
	 	    case 5:cout<<"\n\tENTER ELEMENT";
			 	 cin>>ele;
				 if(b.search(b.ret_root(),ele))
				 			 cout<<"\n\tELEMENT FOUND";
				 else
				 	 cout<<"\n\tELEMENT NOT FOUND";
		 	 	break;
		 	case 6:cout<<"\n\tENTER ELEMENT";
					 cin>>ele;
					 b.find_delete(ele);
					 break;
					
		 	 default:cout<<"\n\tWRONG CHOICE";
		 	 
		}
		
		cout<<"\n\twant to continue (enter y or Y)";
		cin>>c;
	}while(c=='y'||c=='Y');
	
	getch();
}

