#include<iostream>
using namespace std;
void Merge(int arr[],int l,int m,int r,int n)
{
    int i=l;
    int j=m+1;
    int k=l;

    int temp[n];
    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int s=l;s<=r;s++)
    {
        arr[s]=temp[s];
    }

}
void mergeSort(int arr[],int l,int r,int n)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(arr,l,m,n);
        mergeSort(arr,m+1,r,n);
        Merge(arr,l,m,r,n);
    }

}
int main()
{
    int n;
    cout<<"enter the size: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<"elements "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"unsorted array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" " ;
    }
    cout<<endl;
    mergeSort(arr,0,n-1,n);
    cout<<"sorted array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" " ;
    }
}
