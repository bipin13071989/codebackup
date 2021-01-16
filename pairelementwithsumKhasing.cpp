#include<iostream>
using namespace std;
int main()
{
	int arr[]={5,1,7,2,9};
	
	
	
	int h[16]={0};  // it will contain the size of k not the maximum value  of array element// 
	
	int k=16;
	cout<<"Enter the k value: "<<endl;
	cin>>k;
	
	for(int i=0;i<5;i++)
	{
		if(k-arr[i]>0)
		{
			if(h[k-arr[i]]!=0)
		    {
			   cout<<"{"<<arr[i]<<","<<k-arr[i]<<"}"<<endl;
			   
		    }
		    h[arr[i]]++;
		}
		
		
	}
}
