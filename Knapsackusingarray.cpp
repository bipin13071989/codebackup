#include <iostream>
#include <climits>
using namespace std;
int knapSack(int v[], int w[], int n, int W)
{
	if (W < 0)
		return INT_MIN;

	// base case: no items left or capacity becomes 0
	if (n < 0 || W == 0)
		return 0;

	// Case 1. include current item n in knapSack (v[n]) and recur for
	// remaining items (n - 1) with decreased capacity (W - w[n])
	int include = v[n] + knapSack(v, w, n - 1, W - w[n]);

	// Case 2. exclude current item n from knapSack and recur for
	// remaining items (n - 1)
	int exclude = knapSack(v, w, n - 1, W);

	// return maximum value we get by including or excluding current item
	return max (include, exclude);
}

// 0-1 Knapsack problem
int main()
{
	int size;
	cout<<"enter array size: "<<endl;
	cin>>size;
	int v[size];
	int w[size];
	for(int i=0;i<size;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<size;i++)
	{
		cin>>w[i];
	}
	cout<<"enter the Highest capacity of knapsack: "<<endl;
	int W;
	cin>>W;
	int n = sizeof(v) / sizeof(v[0]);
	cout << "Knapsack value is " << knapSack(v, w, n - 1, W);
	return 0;
}
