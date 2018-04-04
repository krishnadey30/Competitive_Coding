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
    	int n,m;
    	cin>>n>>m;
    	int A[n],B[m];
    	for (int i = 0; i < n; i++)
    	{
    		cin>>A[i];
    	}
    	sort(A,A+n);
    	for (int i = 0; i < m; i++)
    	{
    		cin>>B[i];
    	}
    	sort(B,B+m);
    	int c=0;
    	if(n>m)
    	{
    		for (int i = 0; i < m; i++)
    		{
    			if(binary_search(A,A+n,B[i]))
    				c++;
    		}
    	}
    	else
    	{
    		for (int i = 0; i < n; i++)
    		{
    			if(binary_search(B,B+m,A[i]))
    				c++;
    		}
    	}
    	cout<<c<<endl;
    }
    return 0;
}

    }