#include<iostream>
using namespace std;
int max1,min1;
void minMax(int arr[],int l,int r,int &max,int &min)
{
	if(l==r)
	{
		max=arr[l];
		min=arr[l];
		return;
	}
	else if(l==r-1)
	{
		if(arr[l]<arr[r])
		{
			max=arr[r];
			min=arr[l];
		}
		if(arr[r]<arr[l])
		{
			max=arr[l];
			min=arr[r];
		}
		return;
	}
	else
	{
		int m=(l+r)/2;
		minMax(arr,l,m,max,min);
		minMax(arr,m+1,r,max1,min1);
		if(max1>max)
		{
			max=max1;
		}
		else if(min1<min)
		{
			min=min1;
			
		}
	}
}
int main()
{
	int n;
	int max=0,min=0;
	cin>>n;
	int arr[n];
	cout<<"enter the elements into the arrays: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Lists: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	minMax(arr,0,n-1,max,min);
	cout<<"max= "<<max<<" "<<"min= "<<min<<endl;
}
