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
        ll n,j;
        fastscan(n);
        ll X[n+1],S[n+1],V[n+1];
        for (ll i = 0; i < n; i++)
        {
        	fastscan(X[i]);
        }
        S[0]=X[0];
        V[0]=0;
        for (ll i = 1; i < n; i++)
        {
        	S[i]=S[i-1]+X[i];
        	V[i]=0;
        }
        for (ll i = 0; i < n; i++)
        {
        	j=i+2;
        	if(i+1<n)
        		V[i+1]+=1;
        	while(j<n)
        	{
        		if(S[j-1]-S[i]<=X[i])
        		{
        			V[j]+=1;
        			j++;
        		}
        		else
        		{
        			break;
        		}

        	}
        	j=i-2;
        	if(i-1>=0)
        		V[i-1]+=1;
        	while(j>=0)
        	{
        		if(S[i-1]-S[j]<=X[i])
    			{
    				V[j]+=1;
    				j--;
    			}
    			else
    			{
    				break;
    			}
        	}
        }
        for (ll i = 0; i < n; i++)
        {
        	cout<<V[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}