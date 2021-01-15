#include<iostream>
using namespace std;
int main()
{
	int arr[]={10,8,6,2,5};
	
	int h[10]={0};
	
	for(int i=0;i<5;i++)
	{
		h[arr[i]]++;
	}
	
	for(int  i=1;i<=10;i++)
	{
		if(h[i]==0)
		   cout<<i<<" ";
	}
	
}
