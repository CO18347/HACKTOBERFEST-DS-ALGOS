#include<iostream> 
#include<string.h> 
using namespace std; 

int main()
{
	char t1,t2; 
	char nt1,nt2;
	char table[10][6][20]={{"s3","s4","error","1","2"},
	{"error","error","ACCEPT","error","error"},
	{"s6","s7","error","error","5"},
	{"s3","s4","error","error","8"},
	{"r3","r3","error","error","error"},
	{"error","error","r1","error","error"},
	{"s6","s7","error","error","error"},
	{"error","error","r3","error","error"},
	{"r2","r2","error","error","error"},
	{"error","error","r2","error","error"}};

	char stack[20],ip[20];

	int i,j,t,k,top=0,irowtotal,col,row,pop,no,len; 
	char terminal[5]={'a','d','$','S','A'};
	char irow[10]={'0','1','2','3','4','5','6','7','8','9'}; t=5;
 
	irowtotal=10;

	char rule[20][20]={{"S->AA"},{"A->aA"},{"A->d"}};

	cout<<"Enter the set of terminals: "; cin>>t1>>t2;
	cout<<"Enter the set of non-terminals: "; cin>>nt1>>nt2;
	cout<<"Enter the set of productions: "; 
	for(i=0;i<3;i++)
	{

		cout<<rule[i]<<"\n";

	}

	cout<<"\nCLR PARSING TABLE:\n";

	for(i=0;i<t;i++)
	{

		cout<<"\t"<<terminal[i]<<"\t";
	}
	for(i=0;i<irowtotal;i++)
	{
		cout<<"\n"<<irow[i]; 
		for(j=0;j<t;j++)
		{
			cout<<"\t"<<table[i][j]<<"\t";

		}
	}

	stack[top]='$'; top++; 
	stack[top]='0';

	cout<<"\n \nSTACK IMPLEMENTATION";
	cout<<"\n \nDirections: The input string must contain $ at the end"; 
	cout<<"\n\nEnter the input string:";
	cin>>ip; i=0;
	cout<<"\n\nSTACK\t\tINPUT STRING\t\tACTION\n"; 
	cout<<"\n$0\t\t"<<ip<<"\t\t\t";
	while(i<=strlen(ip) )
	{
		for(j=0;j<irowtotal;j++)
		{
			if(stack[top]==irow[j]) col=j;
		}
		for(j=0;j<t;j++)
		{
			if(ip[i]==terminal[j])
			{
 				row=j;
			}
		}
		if((stack[top]=='1')&&(ip[i]=='$'))
		{
			cout<<"\nSTRING ACCEPTED\n";
			break;
		}
		else if(table[col][row][0]=='s')
		{
			top++;
			stack[top]=terminal[row]; top++; 
			stack[top]=table[col][row][1]; i++;
			cout<<"Shift "<<terminal[row]<<" "<<table[col][row][1]<<"\n";
		}
		else if(table[col][row][0]=='r')
		{
			no=(int)table[col][row][1]; 
			no=no-49; 
			len=strlen(rule[no]); 
			len=len-3;
 			pop=2*len; 
			 cout<<"POP "<<pop; 
			 for(j=0;j<pop;j++)
			{
				top=top-1;

			}
			top++; 
			stack[top]=rule[no][0]; 
			k=top;
			k=k-1;
			cout<<" Push ["<<rule[no][0]<<","; 
			for(j=0;j<irowtotal;j++)
			{
				if(stack[k]==irow[j])
				{
					col=j;
				}
			} 
			k++;
			for(j=0;j<t;j++)
			{
				if(stack[k]==terminal[j])
				{
				row=j;
				}
			}
			top++; 
			stack[top]=table[col][row][0]; 
			cout<<table[col][row][0]<<"]\n";
		}
		else
		{
			cout<<"\n\nError\n\nSTRING REJECTED"; 
			break;
		}
		for(j=0;j<=top;j++)
		{ 
			cout<<stack[j];
		}
		cout<<"\t\t"; 
		for(j=i;j<strlen(ip);j++)
		{
			cout<<ip[j];
		}
		cout<<"\t\t";
	}
	return 0;
}
