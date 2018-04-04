#include <bits/stdc++.h>
using namespace std;
int binary(int L[],int val,int l,int r)
{
	if(r>l)
	{
		int mid=(l+r)/2;
		if(L[mid]==val)
			return mid-1;
		if(L[mid]>val)
			return binary(L,val,l,mid-1);
		else if(L[mid]<val)
			return binary(L,val,mid+1,r);
	}
	if(r==l)
	{
		if(L[r]>val)
		{
			return r-1;
		}
		else if (L[r]<val)
		{
			return r;
		}
		else
			return r-1;
	}
	//return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	int N,Q;
    	cin>>N>>Q;
    	int L[N+1],K[Q+1];
    	for (int i = 0; i < N; i++)
    	{
    		cin>>L[i];
    	}
    	for (int i = 0; i < Q; i++)
    	{
    		cin>>K[i];
    	}
    	sort(L,L+N);
    	/*for (int i = 0; i < N; i++)
    	{
    		cout<<L[i]<<endl;
    	}*/
    	int index;
    	for (int i = 0; i < Q; i++)
    	{
    		index=binary(L,K[i],0,N-1);
    		int q=N-index-1;
    		if(q<0)
    			q=0;
    		int o=index+1;
    		//cout<<o<<endl;
    		int a;
    		for(int j=index;j>=0;j--)
    		{
    			a=K[i]-L[j];
    			if(a<=o-1)
    			{
    				q++;
    				o=o-a;
    			}
    			else
    				break;
    		}
    		cout<<q<<endl;
    	}
    }
    return 0;
}