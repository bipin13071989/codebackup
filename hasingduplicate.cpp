#include<iostream>
using namespace std;
int main()
{
	char arr[]="bipin";
	cout<<arr;
	int h[26]={0};
	
	for(int i=0;arr[i]!='\0';i++)
	{
		h[arr[i]-97]+=1;
	}
	
	for(int i=0;i<26;i++)
	{
		cout<<h[i]<<" ";
	}
	for(int i=0;i<26;i++)
	{
		if(h[i]<=1)
		{
//			cout<<"Nothing found: "<<endl;
		}
		else if(h[i]>=2)
		{
			cout<<"found: "<<i+97;
		}
	}
}
