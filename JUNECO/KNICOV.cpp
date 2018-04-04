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
    	bool A[n][m];
    	for (int i = 0; i < n; i++)
    	{
    		for(int j=0; j < m; j++)
    			A[i][j]=false;
    	}
    	int c=0,tc=0;
    	for (int j = (m-1)/2; j <m; j++)
    	{
    		for(int i=0;i< n;i++)
    		{
    			if(!A[i][j])
    			{
    				c++;
    				A[i][j]=true;
    				if(i==0)
    				{
    					if(n==2 )
    					{
    						if(!A[i+1][j+2]&& j<m-2)
    							A[i+1][j+2]=true;
    						if(!A[i+1][j-2]&& j-2>=0)
    							A[i+1][j-2]=true;
    					}
    					else if(n==3)
    					{
    						if(!A[i+1][j+2] && j<m-2)
    							A[i+1][j+2]=true;
    						if(!A[i+2][j+1] && j<m-1)
    							A[i+2][j+1]=true;
    						if(!A[i+1][j-2] && j-2>=0)
    							A[i+1][j-2]=true;
    						if(!A[i+2][j-1] && j-1>=0)
    							A[i+2][j-1]=true;
    					}
    				}
    				else if(i==1)
    				{
    					if(n==2 )
    					{
    						if(!A[i-1][j+2]&& j<m-2)
    							A[i-1][j+2]=true;
    						if(!A[i-1][j-2]&& j-2>=0)
    							A[i-1][j-2]=true;
    					}
    					else if(n==3)
    					{
    						if(!A[i+1][j+2] && j<m-2)
    							A[i+1][j+2]=true;
    						if(!A[i-1][j+2] && j<m-2)
    							A[i-1][j+2]=true;
    						if(!A[i+1][j-2] && j-2>=0)
    							A[i+1][j-2]=true;
    						if(!A[i-1][j-2] && j-2>=0)
    							A[i-1][j-2]=true;
    					}
    				}
    				else
    				{
    					if(!A[i-1][j+2] && j<m-2)
    							A[i-1][j+2]=true;
    					if(!A[i-2][j+1] && j<m-1)
    							A[i-2][j+1]=true;
    					if(!A[i-1][j-2] && j-2>=0)
    						A[i-1][j-2]=true;
    					if(!A[i-2][j-1] && j-1>=0)
    						A[i-2][j-1]=true;
    				}
    			}
    		}
    	}
    	cout<<c<<"\n";
    	for (int j = (m-1)/2; j >=0; j--)
    	{
    		for(int i=0;i< n;i++)
    		{
    			if(!A[i][j])
    			{
    				c++;
    				A[i][j]=true;
    				if(i==0)
    				{
    					if(n==2 )
    					{
    						if(!A[i+1][j+2]&& j<m-2)
    							A[i+1][j+2]=true;
    						if(!A[i+1][j-2]&& j-2>=0)
    							A[i+1][j-2]=true;
    					}
    					else if(n==3)
    					{
    						if(!A[i+1][j+2] && j<m-2)
    							A[i+1][j+2]=true;
    						if(!A[i+2][j+1] && j<m-1)
    							A[i+2][j+1]=true;
    						if(!A[i+1][j-2] && j-2>=0)
    							A[i+1][j-2]=true;
    						if(!A[i+2][j-1] && j-1>=0)
    							A[i+2][j-1]=true;
    					}
    				}
    				else if(i==1)
    				{
    					if(n==2 )
    					{
    						if(!A[i-1][j+2]&& j<m-2)
    							A[i-1][j+2]=true;
    						if(!A[i-1][j-2]&& j-2>=0)
    							A[i-1][j-2]=true;
    					}
    					else if(n==3)
    					{
    						if(!A[i+1][j+2] && j<m-2)
    							A[i+1][j+2]=true;
    						if(!A[i-1][j+2] && j<m-2)
    							A[i-1][j+2]=true;
    						if(!A[i+1][j-2] && j-2>=0)
    							A[i+1][j-2]=true;
    						if(!A[i-1][j-2] && j-2>=0)
    							A[i-1][j-2]=true;
    					}
    				}
    				else
    				{
    					if(!A[i-1][j+2] && j<m-2)
    							A[i-1][j+2]=true;
    					if(!A[i-2][j+1] && j<m-1)
    							A[i-2][j+1]=true;
    					if(!A[i-1][j-2] && j-2>=0)
    						A[i-1][j-2]=true;
    					if(!A[i-2][j-1] && j-1>=0)
    						A[i-2][j-1]=true;
    				}
    			}
    		}
    	}
    	cout<<c<<"\n";
    }
    return 0;
}
