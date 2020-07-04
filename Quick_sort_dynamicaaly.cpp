#include<iostream>
using namespace std;
inline int Partition(int arr[],int s,int e)
{
    int pivot=arr[e];
    int pIndex=s;
    for(int i=s;i<e;i++)
    {
        if(arr[i]<pivot)
        {
            int temp=arr[i];
            arr[i]=arr[pIndex];
            arr[pIndex]=temp;
            pIndex++;
        }
    }
    int temp=arr[e];
    arr[e]=arr[pIndex];
    arr[pIndex]=temp;
    return pIndex;
}
inline void QuickSort(int arr[],int s,int e)
{
    if(s<e)
    {
        int p=Partition(arr,s,e);
        QuickSort(arr,s,(p-1));
        QuickSort(arr,(p+1),e);
    }
}
int main()
{
    int arr[5];
    cout<<"enter the 5 elements: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    cout<<"before sorting::"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    QuickSort(arr,0,4);
    cout<<endl;
    cout<<"after sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }

}
