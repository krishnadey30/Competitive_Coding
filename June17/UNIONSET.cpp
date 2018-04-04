#include <bits/stdc++.h>
using namespace std;
bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    return v1.size() < v2.size();
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	int n,k,b,c,d;
    	cin>>n>>k;
    	vector<vector<int>>A;
    	int B[n];
    	for (int i = 0; i < n; i++)
    	{
    		cin>>B[i];
    		vector<int>C;
    		for(int j=0;j<B[i];j++)
    		{
    			cin>>b;
    			C.push_back(b);
    		}
    		sort(C.begin(),C.end());
    		A.push_back(C);
    	}
    	sort(A.begin(),A.end(),cmp);
    	sort(B,B+n);
    	c=0;
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = n-1; j >i; j--)
    		{
    			if(B[j]+B[i]<k)
    				break;
    			else
    			{
    				b=0,d=0;
    				for (int o = 0; o < B[i]; o++)
    				{
    					if(A[i][o]==A[j][b])
    					{
    						d++;
    						b++;
    					}
    					else if(A[i][o]>A[j][b])
    					{
    						b++;
    						o--;
    					}
    					if(b==B[j])
    						break;
    				}
    				if(B[j]+B[i]-d==k)
    					c++;
    			}
    		}
    	}
    	cout<<c<<endl;
    }
    return 0;
}