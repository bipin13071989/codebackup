#include<iostream>
using namespace std;
int main()
{
	char arr[]="deified";
//	cout<<arr;
	char temp;
	int i,j;
	
	for(j=0;arr[j]!='\0';j++)
	{
		
	}
	j=j-1;
	for(i=0;i<=j;i++,j--)
	{
			if(arr[i]==arr[j])
			{
				if(i ==j)
				{
					cout<<"palindome:"<<i<<" "<<j<<endl;
				}
			}
	}
	
	printf("%s",arr);
	return 0;
}
