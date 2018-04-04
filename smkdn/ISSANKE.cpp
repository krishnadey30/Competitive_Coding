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
    	int n,c=0,flag=0;
    	cin>>n;
    	char S[2][n];
    	int D[2][4]={
    					{0,0,0,0},
    					{0,0,0,0}
    				};
    	int a,b,c0=0;
    	cin>>S[0]>>S[1];
    	for (int i = 0; i < n; i++)
    	{
    		if(S[0][i]=='#')
    		{
    			if(i==0)
    			{
    				a=(S[0][1]=='.')?0:1;
    				b=(S[1][0]=='.')?0:1;
    				D[0][a+b]++;
    				c++;
    			}
    			else if(i==n-1)
    			{
    				a=(S[0][n-2]=='.')?0:1;
    				b=(S[1][n-1]=='.' )?0:1;
    				D[0][a+b]++;
    				c++;
    			}
    			else
    			{
    				a=(S[0][i-1]=='.')?0:1;
    				b=(S[0][i+1]=='.')?0:1;
    				c0=(S[1][i]=='.')?0:1;
    				D[0][a+b+c0]++;
    				c++;
    			}
    			//cout<<a<<b<<c0<<endl;
    		}
    		if(S[1][i]=='#')
    		{
    			if(i==0)
    			{
    				a=(S[1][1]=='.')?0:1;
    				b=(S[0][0]=='.')?0:1;
    				D[1][a+b]++;
    				c++;
    			}
    			else if(i==n-1)
    			{
    				a=(S[1][n-2]=='.')?0:1;
    				b=(S[0][n-1]=='.' )?0:1;
    				D[1][a+b]++;
    				c++;
    			}
    			else
    			{
    				a=(S[1][i-1]=='.')?0:1;
    				b=(S[1][i+1]=='.')?0:1;
    				c0=(S[0][i]=='.')?0:1;
    				D[1][a+b+c0]++;
    				c++;
    			}
    			//cout<<a<<b<<c0<<endl;
    		}
    		
    		if(c>1 &&(D[0][0]+D[1][0])>0)
    		{
    			flag=1;
    			//cout<<1<<endl;
    			break;
    		}
    		if(c>1 &&(D[0][1]+D[1][1])>2)
    		{
    			flag=1;
    			//cout<<2<<endl;
    			break;
    		}
    	}
    	if(!flag)
    	{
    		a=(D[0][3]>D[1][3])?D[0][3]:D[1][3];
    		b=(D[0][3]<=D[1][3])?D[0][3]:D[1][3];
    		if(b==0)
    		{
    			cout<<"yes"<<endl;
    		}
    		else if(a!=b)
    		{
    			if(a%2!=0 || b%2!=0)
    			{
    				cout<<"no"<<endl;
    			}
    			else
    			{
    				cout<<"yes"<<endl;
    			}
    		}
    		else
    		{
    			cout<<"yes"<<endl;
    		}
    	}
    	else
    	{
    		cout<<"no"<<endl;
    	}
    }
    return 0;
} 