#include<iostream>
using namespace std;
inline void insertionSort(int *p,int n)
{
    int j=0;
    int key=0;
    for(int i=1;i<n;i++)
    {
        key=p[i];
        j=i-1;
        while(j>=0 && p[j]>key)
        {
            p[j+1]=p[j];
            j=j-1;
        }
        p[j+1]=key;
    }

}
inline int binarySearch(int *p,int l,int r,int num)
{
    while(l<=r)
    {
        int med=l+(r-l)/2;
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
    cout<<"enter the all intergers: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<"UNsorted lists: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    insertionSort(p,n);
    cout<<"SORTED LISTS: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"enter the element to be searched: "<<endl;
    cin>>num;
    int output=binarySearch(p,0,n-1,num);
    if(output==-1)
    {
        cout<<"not found: "<<endl;
    }
    else
    {
        cout<<"founded at: "<<output<<endl;
    }


}
