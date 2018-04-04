#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int A[2*n];
		int B[2*n];
		int C[n];
		for (int i = 0; i < 2*n; i++)
		{
			cin>>A[i];
		}
		sort(A,A+(2*n));
		int j=0;
		for (int i = n; i < 2*n; i++)
		{
			C[j]=A[i];
			j++;
		}
		int a=n
		j=0;
		for (int i = 0; i < n; i++)
		{
			B[j]=A[i];
			B[j+1]=A[a];
			j=j+2;
			a++;
		}
		cout<<C[(n)/2]<<endl;
		for (int i = 0; i < 2*n; i++)
		{
			cout<<B[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}