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
        ll N;
        fastscan(N);
        ll F[N+1],G[N+1],front=1,back=1;
        for (ll i = 0; i < N; i++)
        {
        	fastscan(F[i]);
        }
        for (ll i = 0; i < N; i++)
        {
        	fastscan(G[i]);
        }
        for (ll i = 0; i < N; i++)
        {
        	if(F[i]>G[i])
        	{
        		front=0;
        	}
        	if(F[i]>G[N-i-1])
        	{
        		back=0;
        	}
        	if(!front && !back)
        		break;
        }
        if(front && back)
        	cout<<"both"<<endl;
        else if(front)
        	cout<<"front"<<endl;
        else if(back)
        	cout<<"back"<<endl;
        else
        	cout<<"none"<<endl;
    }
    return 0;
}