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
    	int n,u=0,l=0,c=0;
    	cin>>n;
    	char R1[n+1],R2[n+1];
    	cin>>R1>>R2;
    	for (int i = 0; i < n; i++)
    	{
    		if(R1[i]=='*')
    			u++;
    		if(R2[i]=='*')
    			l++;
    	}
    	if(u>0 && l>0)
    		c++;
    	int prev1=0,prev2=0,flag=0;
    	for (int i = 0; i < n; i++)
    	{
    		flag=0;
    		if(prev1==1 && R1[i]=='*')
    		{
    			prev1=0;
    			prev2=0;
    			c++;
    		}
    		else if(prev2==1 && R2[i]=='*')
    		{
    			prev1=0;
    			prev2=0;
    			c++;
    		}
    		if(R1[i]=='*')
    		{
    			if(R1[i+1]=='*' && i!=n-1)
    			{
    				c++;
    				prev2=0;
    				flag=1;
    			}
    			else
    			{
    				prev1=1;
    			}
    		}
    		if(R2[i]=='*')
    		{
    			if(R2[i+1]=='*' && flag!=1 && i!=n-1)
    			{
    				c++;
    				prev1=0;
    			}
    			else if(flag!=1)
    				prev2=1;
    		}
    	}
    	cout<<c<<endl;
    }
    return 0;
}