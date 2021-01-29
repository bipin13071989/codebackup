#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
	
}*head=NULL,*last=NULL;
void create()
{
	head=new Node;
	head->data=10;
	head->next=head;	
}
void InsertFront(struct Node *p)
{
	int i=0;
	struct Node *front=NULL;
	int d;
	cout<<"Enter the fron data: "<<endl;
	cin>>d;
	front=new Node;
	front->data=d;
	while(p->next!=head)
	{
		p=p->next;
	}
	p->next=front;
	front->next=head;
	head=front;
	
} 
void InsertKey(struct Node *p)
{
	struct Node *temp=NULL;
	temp=new Node;
	int d,pos=0;
	cout<<"Enter the data to insert: "<<endl;
	cin>>d;
	cout<<"Enter the position where you want to insert:"<<endl;
	cin>>pos;
	temp->data=d;
	for(int i=0;i<pos-1;i++)
	{
		p=p->next;
	}
	temp->next=p->next;
	p->next=temp;
	
	
}
int Count(struct Node *p)
{
	int c=1;
	while(p->next!=head)
	{
		c++;
		p=p->next;
	}
	return c;
}
void InsertLast(struct Node *last)
{
	struct Node *p=NULL;
	p=head;
	last=new Node;
	int d;
	cout<<"Enter the data to enter inside the last node: "<<endl;
	cin>>d;
	last->data=d;
	if(head->next==head)
	{
		head->next=last;
		
	    last->next=head;	
	}
	else
	{
		while(p->next!=head)
		{
			p=p->next;
		}
		p->next=last;
	    last->next=head;
		
	}
	
}
void Display(struct Node *p)
{
	do
	{
		cout<<p->data<<" ";
		p=p->next;
	}while(p!=head);
	cout<<endl;
}
int DeleteList(struct Node *p)
{
	struct Node *q=NULL;
	int pos;
	cout<<"Enter the position to delete: "<<endl;
	cin>>pos;
	int x=0;
	if(pos==1)
	{
		if(head->next!=NULL)
		{
			delete head;
			head=NULL;
		}
		else
		{
			while(p->next!=head)
		    {
			   p=p->next;
		    }
		    p->next=head->next;
		    x =head->data;
		    delete head;
		    head=p->next;
			
		}
		
	}
	else
	{
		
		
		for(int i=0;i<pos-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		delete p;
		
	}
	return x;
}
int LinearSearch(struct Node *p)
{
	int key;
	cout<<"Enter the searching element: "<<endl;
	cin>>key;
	do{
		if(p->data==key)
		   return true;
		else  
		   p=p->next;
		
	}while(p!=head);
	return false;
}
int main()
{
//	create();
//	Display(head);
//	InsertFront();
//	cout<<endl;
//	Display(head);
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
		cout<<"Enter the option you want to select: "<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
				create();
				break;
			case 2:
				InsertFront(head);
				break;
			case 3:
				Display(head);
				break;
			case 4:
				system("cls");
				break;
			case 5:
				cout<<Count(head)<<endl;
				break;
			case 6:
				InsertKey(head);
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
				if(LinearSearch(head)==0)
				{
					cout<<"Not Found: "<<endl;
				}
				else
				{
					cout<<"Found: "<<endl;
				}
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
			default:
				cout<<"Please select something: "<<endl;
		}
	}while(option!=0);
}
