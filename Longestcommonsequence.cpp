#include<bits/stdc++.h>
using namespace std;
int longestCS(char *A,char *B,int m,int n)
{
	int C[m+1][n+1];
	
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				C[i][j]=0;
			}
			else if(A[i-1]==B[j-1])
			{
				C[i][j]=1+C[i-1][j-1];
			}
			else
			{
				C[i][j]=max(C[i-1][j], C[i][j-1]);
			}
		}
	}
	return C[m][n];
	
}
int max(int a,int b)
{
	if(a>b)
	   return a;
	else
	   return b;
}
int main()
{
	char A[]="AGGTAB";
	char B[]="GXTXAYB";
	int m=strlen(A);
	int n=strlen(B);
	
	cout<<"Longest common subsequence is: "<<longestCS(A ,B ,m ,n);
	return 0;
	
}
