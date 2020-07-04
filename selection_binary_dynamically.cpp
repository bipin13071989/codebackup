
#include<iostream>
using namespace std;
inline void selectionSort(int *p,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(p[j]<p[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=p[min];
            p[min]=p[i];
            p[i]=temp;
        }

    }

}
inline int binarySearch(int *p,int l,int r,int num)
{
    while(l<=r)
    {
        int med=l+(r-1)/2;
        if(p[med]==num)
        {
            return med;

        }
        else if(p[med]<num)
        {
            l=med+1;
        }
        else
        {
            r=med-1;
        }
    }
    return -1;
}
int main()
{
    int *p;
    int n,num;
    p=new int[n];
    cout<<"enter the size to be set: "<<endl;
    cin>>n;
    cout<<"enter the elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }

    cout<<"UNSORTED ELEMENTS: "<<endl;
     for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    selectionSort(p,n);
    cout<<"SORTED ELEMENTS ARE: "<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<p[i]<<" ";

    }
    cout<<"enter the value you want search: "<<endl;
    cin>>num;
    int output=binarySearch(p,0,n-1,num);
     if(output==-1)
    {
        cout<<"not founded: "<<endl;
    }
     else
    {
        cout<<"founded at postition: "<<output;
    }

}
