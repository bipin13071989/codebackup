#include<iostream>
using namespace std;
void circularArray(int arr[],int n,int index)
{
    int b[2*n];
	for(int i=0;i<n;i++)
	{
	    b[i]=b[n+i]=arr[i];
	}
	cout<<"cicular arrays is: "<<endl;
	for(int i=index;i<n+index;i++)
	{
		cout<<b[i]<<" ";
	}
}
int main()
{
	int n,index;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter the index from where you want to intiate: "<<endl;
	cin>>index;
	circularArray(arr,n,index);
}
