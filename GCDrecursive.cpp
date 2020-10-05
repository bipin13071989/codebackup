#include<iostream>
using namespace std;
int Gcd(int a,int b)
{
	if(a==0)
	   return b;
	else if(b==0)
	    return a;
	else
	    return Gcd(b,a%b);
}
int main()
{
	int a,b,result;
	cin>>a>>b;
	result=Gcd(a,b);
	cout<<result;
}
