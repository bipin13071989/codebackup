#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	
}*head=NULL,*last=NULL;
//.... create function completed...///
void create()
{
	struct Node *second;
	second=NULL;
	head=new Node;
	second=new Node;
	head->data=10;
	head->next=second;
	second->data=20;
	second->next=NULL;
	
	
}

//...Count function completed...///
int Count(struct Node *n)
{
	int count=0;
	while(n!=NULL)
	{
		count++;
		n=n->next;
	}
	return count;
}
//...Display function completed...///
void Display(struct Node *n)
{
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}
//... Insertfront completed....//
void InsertFront()
{
	int d;
	cout<<"Enter the fron DAta: "<<endl;
	cin>>d;
	struct Node *temp=NULL;
	temp=new Node;
	temp->data=d;
	temp->next=head;
	head=temp;
	
}
//.. Insertkey completed ...///
void InsertKey()
{
	struct Node *prevptr=NULL;
	struct Node *temp=NULL;
	temp=new Node;
	int i,pos,d1;
	cout<<"Enter the new data: "<<endl;
	cin>>d1;
	temp->data=d1;
	cout<<"Enter the position: "<<endl;
	cin>>pos;
	prevptr=head;
	if(pos<=Count(head))
	{
		for(i=1;i<pos&& head!=NULL;i++)
		{
			prevptr=prevptr->next;
		}
		temp->next=prevptr->next;
		prevptr->next=temp;
		
	}
	else
	{
		cout<<"Enter the value less the no of nodes: "<<endl;
	}
}
//... Insert at last is working...///
void InsertLast(struct Node *n)
{
	struct Node *temp=NULL;
	temp=new Node;
	int d2;
	cout<<"Enter the data:"<<endl;
	cin>>d2;
	temp->data=d2;
	temp->next=NULL;
	while(n->next!=NULL)
	{
		n=n->next;
	}
	n->next=temp;
}

//...sorted function completed..//
void SortList()
{
	int t;
	struct Node *later=NULL;struct Node *current=NULL;
	current=head;
	later=head->next;
	int i,j;
	for(i=0;i<Count(head);i++)
	{
		for(j=0;j<Count(head)-i-1;j++)
		{
			if(current->data > later->data)
			{
				t=current->data;
				current->data=later->data;
				later->data=t;
			}
			current=later;
			later=later->next;
			
		}
		current=head;
	    later=head->next;
		
	}
	
}
//... Linear search function completed...///
int LinearSearch(struct Node *temp)
{
	int element;
	cout<<"Enter the element to search: "<<endl;
	cin>>element;
	for(int i=0;i<Count(head);i++)
	{
		if(temp->data==element)
		{
			return temp->data;
		}
		else
		{
			temp=temp->next;
			
		}
	}
	return -1;
	
}

//... Deletelist function completed...///
int DeleteList(struct Node *p)
{
	int pos,x=-1;
	int i;
	cout<<"Enter the position to delete the node: "<<endl;
	cin >>pos;
	struct Node *q=NULL;
	if(pos==1)
	{
		p=head;
		x=p->data;
		
		head=head->next;
		delete p;
		return x;
		
	}
	else
	{
		
		q=NULL;
		for(i=0;i<pos-1 &&p!=NULL;i++)
		{
			q=p;
			p=p->next;
			
		}
		
			q->next=p->next;
		    x=p->data;
		    delete p;
		    return x;
	}
	
}
///.... working ..///
//second method for finding whether LInked lists is sorted or not//
int checkSortedornot()
{
	int i;
	struct Node *p,*q;
	p=head;
	q=head->next;
	while(q!=NULL)
	{
		if(p->data<q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			return 0;
		}
	}
	return 1;
	
}
//... It is working ..//
int Testcase(struct Node *p)
{
	int i,x=INT_MIN;
	
	for(i=0;i<=Count(head) &&p!=NULL;i++)
	{
		if(p->data>x)
		{
			x=p->data;
			p=p->next;
			
		}
		else
		{
			return 0;
		}
	}
	return 1;
	
}

//... Duplicate LIst is working...///
int DuplicateList(struct Node *p)
{
	int x=-1;
	struct Node *q=NULL;
	q=head->next;
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			p->next=q->next;
			x=q->data;
			delete q;
			q=p->next;
			cout<<"Duplicate  Number is: "<<x<<endl;
		}
	}
	
	
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
				cout<<Count(head)<<endl;
				break;
			case 6:
				InsertKey();
				break;
			case 7:
				InsertLast(head);
				break;
			case 8:
				SortList();
				break;
			case 9:
				cout<<"Deleted Node data is: "<<DeleteList(head)<<endl;
				break;
			case 10:
				cout<<LinearSearch(head)<<endl;
				break;
			case 11:
				if(Testcase(head)==0)
				{
					cout<<"Not sorted"<<endl;
				}
				else
				{
					cout<<"Sorted lists"<<endl;
				}
				break;
			case 12:
				cout<<checkSortedornot()<<endl;
				break;
			case 13:
				DuplicateList(head);
				break;
			default:
				cout<<"Please select something: "<<endl;
		}
	}while(option!=0);
}
