#include<iostream>
using namespace std;
void seive(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		arr[i]=1;
	}
	arr[0]=arr[1]=0;
	for(int i=2;i*i<=n;i++)
	{
		if(arr[i]==1)
		{
			for(int j=2;i*j<=n;j++)
			{
				arr[i*j]=0;
			}
		}
	}
	for(int i=2;i<n;i++)
	{
		if(arr[i]==1)
		   cout<<i<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	seive(arr,n);
}
