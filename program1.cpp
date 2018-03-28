#include<iostream>
#include<conio.h>
using namespace std;
void check(int *main_local_addr)
{
	/*
	objective:to check whether stack grows upward or downward
	input parameters:
				main_local_addr-it stores address of main local variable 
	return value:none
	approach:-if address of function variable is greater than address of main local variable
				then stack grows upward
				otherwise
					stack grows downward 
	*/
	int func_par;
	if(&func_par>main_local_addr)
		cout<<"\n\tSTACK GROWS UPWARD";
	else
		cout<<"\n\tSTACK GROWS DOWNWARD";
}
int main()
{
	/*
	objective:to check whether stack grows upward or downward
	input parameters:none
	return value:none
	approach:-calling function check
	*/
	int main_local_par;
	check(&main_local_par);
	getch();
}
