#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node() {}
	Node(int x)
	{
		data=x;
		next=NULL;
	}
};

Node* head=NULL;
void push(int x)
{
	Node* temp=new Node(x);
	temp->next=head;
	head=temp;
}

int pop()
{
	if(head==NULL) return -1;
	int res=head->data;
	Node* temp=new Node();
	head=head->next;
	delete(temp);
	return(res);
}

void display()
{
	Node* iter=head;
	cout<<"Printing Stack from top to bottom-\n";
	while(iter)
	{
		cout<<iter->data<<" ";
		iter=iter->next;
	}
	cout<<"\n";
}

int main()
{
	int ele;
	push(10);
	push(30);
	push(20);
	display();
	ele=pop();
	if(ele==-1) cout<<"Stack underflow\n";
	else cout<<ele<<" popped !\n";
	display();
}