#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A[1000],c=2,B[5000],d=1,e;
    A[0]=1;
    A[1]=2;
    B[0]=3;
    for (int i = 3; c!=100; i++)
    {
    	e=find(B,B+d,i)-B;
    	if(e==d)
    	{
    		A[c++]=i;
    		for (int j = 0; j < c-1; j++)
    		{
    			B[d++]=i+A[j];
    		}
    	}

    }
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	for (int i = 0; i < n; i++)
    	{
    		cout<<A[i]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}