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
    ll A[t+1];
    for(ll k=0;k<t;k++)
    {
        ll sum=0,j;
        for (ll i = 0; i < 5; ++i)
        {
        	fastscan(j);
        	sum+=j;
        }
        A[k]=sum;
    }
    for (ll i = 0; i < t; ++i)
    {
    	if(A[i]==0)
    		cout<<"Beginner"<<endl;
    	else if(A[i]==1)
    		cout<<"Junior Developer"<<endl;
    	else if(A[i]==2)
    		cout<<"Middle Developer"<<endl;
    	else if(A[i]==3)
    		cout<<"Senior Developer"<<endl;
    	else if(A[i]==4)
    		cout<<"Hacker"<<endl;
    	else
    		cout<<"Jeff Dean"<<endl;
    }
    return 0;
}