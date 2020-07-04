
#include<iostream>
using namespace std;
inline int binarySearch(int *p,int l,int r,int num)
{
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(p[m]==num)
        {
            return m;
        }
        else if(p[m]<num)
        {
            l=m+1;
        }
        else
        {
            r=r-1;
        }
    }
    return -1;

}
inline void bubbleSort(int *p,int n)
{
    int Cout=0;
    for(int i=0;i<n;i++)
    {
        Cout++;
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])
            {
                int temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    cout<<"rounds: "<<Cout<<endl;
}
int main()
{
    int *p;
    int n,num,output;
    p=new int[n];
    cout<<"enter the size: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {

        cin>>p[i];
    }
    bubbleSort(p,n);
    cout<<"sorted elements: "<<endl;
    for(int i=0;i<n;i++)
    {

        cout<<p[i]<<" ";
    }

    cout<<"enter the value you want to search: "<<endl;
    cin>>num;
    output=binarySearch(p,0,n-1,num);
    if(output==-1)
    {
        cout<<"not founded: "<<endl;
    }
    else
    {
        cout<<"founded at: "<<output<<endl;
    }
}

