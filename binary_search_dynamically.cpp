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

