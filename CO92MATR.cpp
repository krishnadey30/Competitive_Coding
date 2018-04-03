/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor ,SriCity
*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
template <typename T>
void fastscan(T &no)
{
	register int x=gc();
	int neg=0;
	no=0;
	while((x<48|| x>57)&& x!='-' )
		x=gc();
	if(x=='-')
	{
		neg=1;
		x=gc();
	}
	for(;x>47 && x<58;x=gc())
	{
		no=(no<<1)+(no<<3)+x-48;
	}
	if(neg)
		no=-no;
}
int main()
{
    ll t;
    fastscan(t);
    while(t--)
    {
        ll n,m,temp;
        fastscan(n);
        fastscan(m);
        ll A[n+1][m+1];
        for(ll i = 0; i < n ; i++)
        {
        	for(ll j =0 ; j < m ; j++)
        	{
        		fastscan(A[i][j]);
        	}
        }
        for(ll i = 0; i < n ; i++)
        {
        	for(ll j =0 ; j < m ; j++)
        	{
        		if(A[i][j]==-1)
        		{
        			if(j==0)
        			{
        				if(i==0)
        				{
        					A[i][j]=1;
        				}
        				else
        				{
        					A[i][j]=A[i-1][j];
        				}
        			}
        			else if(j==m-1)
        			{
        				if(i==0)
        					A[i][j]=A[i][j-1];
        				else
        					A[i][j]=max(A[i][j-1],A[i-1][j]);
        			}
        			else
        			{
        				if(i==0)
        				{
        					A[i][j]=A[i][j-1];
        				}
        				else
        				{
        					A[i][j]=max(A[i][j-1],A[i-1][j]);
        				}
        			}
        		}
        	}
        }
        ll flag=1;
        for(ll i = 0; i < n ; i++)
        {
        	for(ll j =0 ; j < m ; j++)
        	{
        		if(A[i][j]<A[i][j-1] && j!=0)
        		{
        			flag=0;
        			break;
        		}
        		if(A[i][j]<A[i-1][j]&& i!=0)
        		{
        			flag=0;
        			break;
        		}
        	}
        	if(!flag)
        		break;
        }
        if(!flag)
        {
        	cout<<-1<<endl;
        	// for(ll i = 0; i < n ; i++)
	        // {
	        // 	for(ll j =0 ; j < m ; j++)
	        // 	{
	        // 		cout<<A[i][j]<<" ";
	        // 	}
	        // 	cout<<endl;
	        // }
        }
        else
        {
        	for(ll i = 0; i < n ; i++)
	        {
	        	for(ll j =0 ; j < m ; j++)
	        	{
	        		cout<<A[i][j]<<" ";
	        	}
	        	cout<<endl;
	        }
        }

    }
    return 0;
}