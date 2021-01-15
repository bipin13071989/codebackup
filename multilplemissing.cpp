#include<iostream>
using namespace std;
void missing(int arr[],int l,int h,int n)
{
	int diff=l-0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]-i!=diff)
		{
			
			while(diff<arr[i]-i)
			{
				cout<<"Found the element at : "<<i+diff<<" ";
				diff++;
			}
		}
	}
	
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,10,12};
	int temp=arr[0]-1;
	missing(arr,1,12,10);
	
	
	
}
