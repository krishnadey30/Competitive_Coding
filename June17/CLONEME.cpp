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
    	int n,q,a;
    	cin>>n>>q;
    	vector<int>A;
    	int B[q][5];
    	for (int i = 0; i < n; i++)
    	{
    		cin>>a;
    		A.push_back(a);
    	}
    	for (int i = 0; i < q; i++)
    	{
    		cin>>B[i][0]>>B[i][1]>>B[i][2]>>B[i][3];
    	}
    	int b,c,d,e;
    	for (int i = 0; i < q; i++)
    	{
    		a=B[i][0];
    		b=B[i][1];
    		c=B[i][2];
    		d=B[i][3];
    		e=0;
    		std::vector<int> newvector(&A[a-1],&A[b]);
    		sort(newvector.begin(),newvector.end());
    		std::vector<int> newvector1(&A[c-1],&A[d]);
    		sort(newvector1.begin(),newvector1.end());
    		for(int j=0;j<newvector.size();j++)
    		{
    			if(newvector[j]!=newvector1[j])
    			{
    				e++;
    			}
    			if(e>1)
    				break;
    		}
    		if(e>1)
    			cout<<"NO"<<endl;
    		else
    			cout<<"YES"<<endl;
    	}
    }
    return 0;
}