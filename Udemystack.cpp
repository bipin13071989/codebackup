#include<iostream>
using namespace std;
struct Stack{
	int size;
	int *s;
	int top;
}s1;

void Display()
{
	for(int i=s1.top;i>=0;i--)
	{
		cout<<s1.s[i]<<" ";
	}
	cout<<endl;
}
bool isEmpty()
{
	if(s1.top==-1)
	   return true;
	else
	   return false;
}
bool isFull()
{
	if(s1.top==s1.size-1)
	   return true;
	return false;
}
void push(struct Stack *s1)
{
	int data;
	cout<<"Enter the data to be pushed: "<<endl;
	cin>>data;
	if(s1->top==s1->size-1)
	{
		cout<<"Stack overflow: "<<endl;
	}
	else
	{
		s1->top++;
		s1->s[s1->top]=data;
	}
	
}
int pop(struct Stack *s1)
{
	int x=-1;
	if(s1->top==-1)
	{
		cout<<"Stack Underflow: "<<endl;
		return x;
	}
	else{
		x=s1->s[s1->top];
		s1->s[s1->top]=0;
		s1->top--;
		return x;
		
	}
}
void Peek()
{
	int pos;
	cout<<"Enter the position to peek on: "<<endl;
	cin>>pos;
	if(s1.top==-1)
	{
		cout<<"Stack is empty so no need to peek: "<<endl;
	}
	else
	{
		cout<<s1.s[s1.top-pos+1]<<endl;
	}
}
int Count()
{
	return s1.top+1;
}
void Change(struct Stack *s1)
{
	int pos,element;
	cout<<"Enter the position from where to replace the element: "<<endl;
	cin>>pos;
	cout<<"Enter the data: "<<endl;
	cin>>element;
	if(s1->top==-1)
	{
		cout<<"Nothing present to be replaced:"<<endl;
	}
	else{
		s1->s[s1->top-pos+1]=element;
	}
}
int main()
{
	
	s1.top=-1;
	cout<<"Enter the size of the stack: "<<endl;
	cin>>s1.size;
	s1.s=new int[s1.size];
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
				push(&s1);
				break;
			case 4:
				cout<<pop(&s1)<<endl;
				break;
			case 5:
				Peek();
				break;
			case 6:
				system("cls");
				break;
				
			case 7:
				Display();
				break;
			case 8:
				Change(&s1);
				break;
			case 9:
				cout<<Count()<<endl;
				break;
			default:
				cout<<"Enter your choice again: "<<endl;		
				
		}
		
	}while(option!=0);
	
}
