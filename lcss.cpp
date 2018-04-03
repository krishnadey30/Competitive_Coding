#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		char A[100000],B[100000];
		getchar();
		scanf("%[^\n]s",A);
		getchar();
		scanf("%[^\n]s",B);
		int n=strlen(A);
		int m=strlen(B);
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
		int length=size[n][m];
		char Str[length+1];
		Str[length]=0;
		i=n;
		j=m;
		while(i>0 && j>0)
		{
			if(A[i-1]==B[j-1])
			{
				Str[--length]=A[i-1];
				i--;j--;
			}
			else if(size[i-1][j]>size[i][j-1])
				i--;
			else
				j--;
		}
		cout<<Str<<endl;
	}
	return 0;
}