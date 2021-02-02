#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
}*head=NULL;
void create()
{
	head=new Node;
	head->data=10;
	head->prev=NULL;
	head->next=NULL;
}
void InsertFront()
{
	int d;
	struct Node *front=NULL;
	front=new Node;
	cout<<"Enter the front data: "<<endl;
	cin>>d;
	front->data=d;
	front->next=head;
	front->prev=NULL;
	head->prev=front;
	head=front;
	
}
void InsertLast(struct Node *p)
{
	int d;
	struct Node *l=NULL;
	l=new Node;
	cout<<"Enter the data: "<<endl;
	cin>>d;
	l->data=d;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=l;
	l->prev=p;
	l->next=NULL;
}
void InsertKey()
{
	struct Node *p=NULL;
	p=head;
	struct Node *t=NULL;
	t=new Node;
	int pos,d;
	cout<<"Enter the position: "<<endl;
	cin>>pos;
	cout<<"Enter the data: "<<endl;
	cin>>d;
	t->data=d;
	for(int i=0;i<pos-1;i++)
	{
		p=p->next;
	}
	t->next=p->next;
	p->next->prev=t;
	p->next=t;
	t->prev=p;
	
}
int Count(struct Node *p)
{
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
void Display(struct Node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int DeleteList(struct Node *p)
{
	int pos,x=0;
	struct Node *q=NULL;
	q=p->next;
	cout<<"Enter the position to delete: "<<endl;
	cin>>pos;
	
	if(pos==1)
	{
		if(p->next==NULL)
		{
			x=p->data;
			delete p;
			head=NULL;
		}
		else{
		
		head=head->next;
		head->prev=NULL;
		x=p->data;
		delete p;
		}
	}
	else{
		for(int i=0;i<pos-1;i++)
		{
			p=p->next;
		}
		p->prev->next=p->next;
		if(p->next!=NULL)
		{
			p->next->prev=p->prev;
		}
		x=p->data;
		delete p;
	}
	return x;
}

void Reverse(struct Node *p)
{
	struct Node *temp=NULL;
	while(p!=NULL)
	{
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		p=p->prev;
		if(p!=NULL &&p->next==NULL)
		{
			head=p;
		}
	}
	
}
int LinearSearch(struct Node *p)
{
	int element;
	cout<<"Enter the element to search: "<<endl;
	cin>>element;
	while(p!=NULL)
	{
		if(p->data==element)
		{
			return p->data;
		}
		else
		{
			p=p->next;
		}
	}
	return -1;
	
}
int main()
{

	int option;
	do{
		cout<<"1. Create Linked list: "<<endl;
		cout<<"2. Insert at front: "<<endl;
		cout<<"3. Display the data inside the LInked lists: "<<endl;
		cout<<"4. Clear the screen: "<<endl;
		cout<<"5. Count the no of nodes: "<<endl;
		cout<<"6. Insert at key: "<<endl;
		cout<<"7. Insert at Last: "<<endl;
		cout<<"8. Sort the Linked Lists: "<<endl;
		cout<<"9. Delete the Node: "<<endl;
		cout<<"10. Search the Linked list data: "<<endl;
		cout<<"11. Checking Whether the Linked list is sorted or not"<<endl;
		cout<<"12. Second method for checking sorted lists"<<endl;
		cout<<"13. Duplicate Numbers inside the LInekd Lists: "<<endl;
		cout<<"14. Reversing the linked list: "<<endl;
		cout<<"Enter the option you want to select: "<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
				create();
				break;
			case 2:
				InsertFront();
				break;
			case 3:
				Display(head);
				break;
			case 4:
				system("cls");
				break;
			case 5:
				cout<<"Number of nodes: "<<Count(head)<<endl;
				break;
			case 6:
				InsertKey();
				break;
			case 7:
				InsertLast(head);
				break;
//			case 8:
//				SortList();
//				break;
			case 9:
				cout<<"Deleted Node data is: "<<DeleteList(head)<<endl;
				break;
			case 10:
				cout<<LinearSearch(head)<<endl;
				break;
//			case 11:
//				if(Testcase(head)==0)
//				{
//					cout<<"Not sorted"<<endl;
//				}
//				else
//				{
//					cout<<"Sorted lists"<<endl;
//				}
//				break;
//			case 12:
//				cout<<checkSortedornot()<<endl;
//				break;
//			case 13:
//				DuplicateList(head);
//				break;
            case 14:
            	Reverse(head);
            	break;
			default:
				cout<<"Please select something: "<<endl;
		}
	}while(option!=0);
}
