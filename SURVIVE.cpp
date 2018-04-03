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
        ll N,K,S;
        fastscan(N);
        fastscan(K);
        fastscan(S);
        if(S>6)
        {
        	if((N-K)*6>=K)
        	{
        		cout<<ceil((float)(K*S)/N)<<endl;
        	}
        	else
        		cout<<-1<<endl;
        }
        else
        {
        	if(N>=K)
        	{
        		cout<<ceil((float)(K*S)/N)<<endl;
        	}
        	else
        		cout<<-1<<endl;
        }
    }
    return 0;
}