#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;

	for(int z=1;z<t+1;z++)
	{
		int n,m;
		cin>>n>>m;
		char A[100000],B[100000];
		//getchar();
		scanf(" %s",A);
		//getchar();
		scanf(" %s",B);
		
		int size[n+1][m+1],j,i;
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= m; j++)
			{
				if(i==0 || j==0)
					size[i][j]=0;
				else if(A[i-1]==B[j-1])
					size[i][j]=1+size[i-1][j-1];
				else
					size[i][j]=max(size[i-1][j],size[i][j-1]);
			}
		}
		cout<<"Case "<<z<<": "<<m+n-size[n][m]<<endl;
	}
	return 0;
}