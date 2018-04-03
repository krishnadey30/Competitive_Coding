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
    ll n,q,x,y,a;
    fastscan(n);
    ll H[n+1];
    queue < ll > index;
    for (ll i = 0; i < n; i++)
    {
    	fastscan(H[i]);
    	index.push(i);
    }
    fastscan(q);
    for (ll i = 0; i < q; i++)
    {
    	fastscan(x);
    	fastscan(y);
    	a=index.size();
    	for(ll j =0; j < a; j++)
    	{
    		ll v = index.front();
    		//cout<<v<<endl;
    		index.pop();
    		ll k= v &x;
    		if(k == v)
    		{
    			H[v]-=y;
    			//cout<<v << " "<< H[v]<<endl;
    			if(H[v]>0)
    				index.push(v);
    		}
    		else
    			index.push(v);
    	}
    	cout<<index.size()<<endl;
    }
    return 0;
}