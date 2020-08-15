#include<iostream>
using namespace std;
int main()
{
	int n;
	int c=0;
	int a[c];
	cout<<"enter the number to find prime factorization: "<<endl;
	cin>>n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				c++;
				cout<<i<<" ";
				n=n/i;
			}
				
		}
	}
	if(n!=1)
	{
		cout<<n;
	}
}
