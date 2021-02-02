#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
	
}*top=NULL;
void push()
{
	int d;
	struct Node *p;
	p=new Node;
	cout<<"Enter the data : "<<endl;
	cin>>d;
	if(p==NULL)
	{
		cout<<"Stack overflow: "<<endl;
		
	}
	else{
		p->data=d;
	    p->next=top;
	    top=p;
	}
	
}
int pop(struct Node *p)
{
	int x=-1;
	if(top!=NULL)
	{
		x=p->data;
		top=top->next;
		delete p;
		return x;
	}
}
void Display()
{
	struct Node *p=top;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int Count()
{
	struct Node *p=top;
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
void Change(struct Node *p)
{
	int pos;
	int d;
	cout<<"Enter the pos and data: "<<endl;
	cin>>pos>>d;
	for(int i=0;i<pos-1;i++)
	{
		p=p->next;
	}
	p->data=d;
}
bool isEmpty()
{
	if(top==NULL)
	{
		return true;
	}
	else
	  return false;
}
bool isFull()
{
	struct Node *t;
	
	if(t==NULL)
	{
		return true;
	}
	else
	   return false;
}
int main()
{
	top=new Node;
	top->data=10;
	top->next=NULL;
	int option;	
	
	do{
		cout<<"1. Check stack is empty or not: "<<endl;
		cout<<"2. Check stack is full or not: "<<endl;
		cout<<"3. Push data inside the stack: "<<endl;
		cout<<"4. Pop data from the stack : "<<endl;
		cout<<"5. Peek from the stack: "<<endl;
		cout<<"6. Clear screen off: "<<endl;
		cout<<"7. Display the stack data: "<<endl;
		cout<<"8. Change the element: "<<endl;
		cout<<"9. count the level: "<<endl;
		cin>>option;
		
		
		switch(option)
		{
			case 1:
				if(isEmpty()==1)
				{
					cout<<"Stack is empty: "<<endl;
					
				}
				else{
					cout<<"Not empty: "<<endl;
				}
				break;
			case 2:
				if(isFull()==1)
				  cout<<"Stack is full: "<<endl;
				else 
				   cout<<"Not full: "<<endl;
				break;
			case 3:
				push();
				break;
			case 4:
				cout<<pop(top)<<endl;
				break;
//			case 5:
//				Peek();
//				break;
			case 6:
				system("cls");
				break;
				
			case 7:
				Display();
				break;
			case 8:
				Change(top);
				break;
			case 9:
				cout<<Count()<<endl;
				break;
			default:
				cout<<"Enter your choice again: "<<endl;		
				
		}
		
	}while(option!=0);
	
}
