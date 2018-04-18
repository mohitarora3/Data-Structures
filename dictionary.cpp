#include<iostream>
#include<conio.h>
#define NUMBER_OF_ALPHABETS 26
using namespace std;
struct trie_node
{
	struct  trie_node *children[NUMBER_OF_ALPHABETS];
	string info;
	bool end_point=false;

};

struct trie_node *get_node()
{
	struct trie_node *node1=new trie_node;
	node1->info="";
	for(int i=0;i<NUMBER_OF_ALPHABETS;i++)
	{
		node1->children[i]=NULL;
	}
	return node1;
}

void insert(trie_node *root,string word,string meaning)
{
	trie_node *r=root;
	int index;
	for(int i=0;i<word.length();i++)
	{
		index=word[i]-'a';
		if(r->children[index]==NULL)
			r->children[index]=get_node();

		r=r->children[index];
	}
	r->info=meaning;
	r->end_point=true;
	 
}
void perm(trie_node *root,string word)
{
		string str;
		int index,i;
	    for(index=0;index<NUMBER_OF_ALPHABETS;index++)
	    	if(root->children[index]&&root->children[index]->end_point)
	    		{
					cout<<"\""<<word<<char('a'+index)<<"\", ";
				}
	    
	    for(i=0;i<NUMBER_OF_ALPHABETS;i++)
	    	if(root->children[i]&&!(root->children[i]->end_point))
	    	{
	    	str='a'+i;
			perm(root->children[i],word.append(str));   
		//	return;
			}
			
	
}
void search(trie_node *root,string word)
{
	trie_node *r=root;
	int i,index;
	for(i=0;i<word.length();i++)
	{
		index=word[i]-'a';
		if(r->children[index]==NULL)
		{
			break;
		}
		r=r->children[index];
	}
	if(r->end_point)
	cout<<"\n\tthe word \""<<word<<"\" was found with meaning \""<<r->info<<"\"";
	else
	{
	cout<<"\n\tthe word \""<<word<<"\" was not found";
	cout<<"\n\tDid you mean ";
	perm(r,word.substr(0,i));
	}	
	
	
}

int main()
{/*
	string words[]={"prodigious","potent","sway","corrosive","propaganda","drag","cart","card","carrot","carrom"};
	string meaning[]={"very large in size","very strong in chemical or medicinal way","control","having the ability to wear down or destroy","information","pass slowly and tediously","a strong open vehicle with two or four wheels, typically used for carrying loads and pulled by a horse","a piece of thick, stiff paper or thin pasteboard, in particular one used for writing or printing on","a tapering orange-coloured root eaten as a vegetable","any strike and rebound, as a ball striking a wall and glancing off"};
	*/string words[]={"corrosive","cart","card","carrot","carrom"};
	string meaning[]={"having the ability to wear down or destroy","a strong open vehicle with two or four wheels, typically used for carrying loads and pulled by a horse","a piece of thick, stiff paper or thin pasteboard, in particular one used for writing or printing on","a tapering orange-coloured root eaten as a vegetable","any strike and rebound, as a ball striking a wall and glancing off"};
	
	struct trie_node *root=get_node();
	string word;
	char c;
	for(int i=0;i<5;i++)
	{
		insert(root,words[i],meaning[i]);
	}
	do
	{
		cout<<"\n\tENTER WORD: ";
		cin>>word;
		search(root,word);
		cout<<"\n\twant to continue (enter 'y' or 'Y') ";
		cin>>c;
	}while(c=='y'||c=='Y');
	getch();
	return 0;
}
	
