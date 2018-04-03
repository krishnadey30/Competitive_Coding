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
ll D[10000001];
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
        ll N,A,B;
        fastscan(N);
        fastscan(A);
        fastscan(B);
        D[1]=A;
        for (int i = 2; i < N+1; ++i)
        {
        	if(i%2==0)
        	{
        		D[i]=min(D[i-1]+A,D[i/2]+B);
        	}
        	else
        		D[i]=min(D[i-1]+A,D[(i+1)/2]+B+A);
        }
        cout<<D[N]<<endl;
    }
    return 0;
}