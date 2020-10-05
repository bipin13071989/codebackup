#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	int wt;
	double ratio;
	
};
bool compare(Node p,Node q)
{
	return p.ratio>q.ratio;
}
int main()
{
	cout<<"enter the no of turns: "<<endl;
	int t;
	cin>>t;
	while(t-->0)
	{
		cout<<"enter the size: "<<endl;
		int n;
		cin>>n;
		int bag_wt;
		cout<<"enter max capacity of knapsack: "<<endl;
		cin>>bag_wt;
		Node items[n];
		for(int i=0;i<n;i++)
		{
			cout<<"enter the values of: "<<i+1<<endl;
			cin>>items[i].val;
			cout<<"enter the weight of: "<<i+1<<endl;
			cin>>items[i].wt;
		}
		for(int i=0;i<n;i++)
		items[i].ratio=((double)items[i].val/items[i].wt);
		sort(items,items+n,compare);
		double max_profit=0;
		int i=0;
		while(i<n && bag_wt!=0)
		{
			if(items[i].wt<=bag_wt)
			{
				max_profit+=items[i].val;
				bag_wt-=items[i].wt;
			}
			else
			{
				max_profit+=items[i].val*((double)bag_wt/items[i].wt);
				break;
			}
			i++;
		}
		cout<<fixed<<setprecision(4)<<max_profit<<endl;
	}
}
