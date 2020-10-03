#include<iostream>
#define SPACE 10
using namespace std;
class Treenode
{
	public:
		int value;
		Treenode* left;
		Treenode* right;
		Treenode()
		{
			value=0;
			left=NULL;
			right=NULL;
		}
		Treenode(int v)
		{
			value=v;
			left=NULL;
			right=NULL;
		}
};
class BTS{
	public:
		Treenode* root;
		BTS()
		{
			root=NULL;
		}
		bool isEmpty()
		{
			if(root==NULL)
			   return true;
			else
			   return false;
		}
		void insertNode(Treenode* newnode)
		{
			if(root==NULL)
			{
				root=newnode;
				cout<<"node inserted when root is empty: "<<endl;
			}
			else
			{
				Treenode* temp=root;
				while(temp!=NULL)
				{
					if(newnode->value == temp->value)
					{
						cout<<"No duplicates allowed: "<<endl;
						return ;
					}
					else if(newnode->value< temp->value && temp->left==NULL)
					{
						temp->left=newnode;
						cout<<"value inserted to the left :"<<endl;
						break;
					}
					else if(newnode->value< temp->value)
					{
						temp=temp->left;
					}
					else if(newnode->value> temp->value && temp->right==NULL)
					{
						temp->right=newnode;
						cout<<"value inserted to the right: "<<endl;
						break;
					}
					else
					{
						temp=temp->right;
					}
					
				}
			}
		}
		void print2D(Treenode* r,int space)
		{
			if(r==NULL)
				return ;
			space+=SPACE;
			print2D(r->right,space);
			cout<<endl;
			for(int i=SPACE;i<space;i++)
			   cout<<" ";
			cout<<r->value<<"\n";
			print2D(r->left,space);
		}
		Treenode* iterativesearch(int v)
		{
			if(root==NULL)
			   return root;
			else
			{
				Treenode* temp;
				temp=root;
				while(temp!=NULL)
				{
					if(temp->value==v)
					   return temp;
					else if(temp->value<v)
					{
						temp=temp->right;
					}
					else
					{
						temp=temp->left;
					}
					
				} 
			}
		}
		Treenode* recursivesearch(Treenode* r, int v)
		{
			if(r==NULL || r->value==v)
			   return r;
			else if(v<r->value)
			{
				recursivesearch(r->left,v);
			}
			else
			{
				recursivesearch(r->right,v);
			}
		}
		int heightTree(Treenode* r)
		{
			if(r==NULL)
			   return -1;
			else
			{
				int lheight=heightTree(r->left);
				int rheight=heightTree(r->right);
				if(lheight>rheight)
				    return (lheight+1);
				else
				    return (rheight+1);
			}
		}
};
int main()
{
	BTS o;
	int opt,val;
	do
	{
		
		cout<<endl;
		cout<<"1. Insert the tree: "<<endl;
		cout<<"2. search the tree: "<<endl;
		cout<<"3. clear screen : "<<endl;
		cout<<"4. Empty or not: "<<endl;
		cout<<"5. Print the screen: "<<endl;
		cout<<"6. IterativeSeacrch particular number in BST: "<<endl;
		cout<<"7. RecursiveSeach particular number in BST: "<<endl;
		cout<<"8. Height of the binary Tree: "<<endl;
		cout<<"enter the option to select :"<<endl;
		cin>>opt;
		Treenode* newnode=new Treenode; 
		switch(opt)
		{
			case 0:
				break;
			case 1:
				cout<<"enter the value: "<<endl;
				cin>>val;
				newnode->value=val;
				o.insertNode(newnode);
				break;
			case 2:
				cout<<"search: "<<endl;
				break;
			case 3:
				system("cls");
				break;
			case 4:
				if(o.isEmpty()==true)
				{
					cout<<"Empty: "<<endl;
				}
				else
				   cout<<"not: "<<endl;
				break;
			case 5:
				cout<<"print"<<endl;
				o.print2D(o.root,5);
				break;
		    case 6:
		    	cout<<"enter the value to be put for searching: "<<endl;
		    	cin>>val;
		    	newnode=o.iterativesearch(val);
		    	if(newnode==NULL)
		    	{
		    		cout<<"not found: "<<endl;
				}
				else
				{
					cout<<"found :"<<endl;
				}
				break;
			case 7:
				cout<<"enter the value to be put for searching: "<<endl;
		    	cin>>val;
		    	newnode=o.recursivesearch(o.root,val);
		    	if(newnode==NULL)
		    	{
		    		cout<<"not found: "<<endl;
				}
				else
				{
					cout<<"found :"<<endl;
				}
				break;
			case 8:
				cout<<"Height of the tree is: "<<o.heightTree(o.root)<<endl;
				
				break;
			default: 
			    break;
		}
		
	}while(opt!=0);
}
