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
        double x,y,z,sum=0,ad;
        for (ll i = 0; i < N; i++)
        {
        	cin>>x>>y>>z;
        	ad=(x*(100+z))/100;
        	ad=(ad*(100-z))/100;
        	if(ad<x)
        		sum+=(y*(x-ad));
        }
        cout<<setprecision(13)<<sum<<endl;
    }
    return 0;
}