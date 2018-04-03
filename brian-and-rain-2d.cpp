/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor ,SriCity
*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
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
ll findWater(vector<ll>arr, ll n)
{
    ll left[n];
    ll right[n];
    ll water = 0;
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
       left[i] = max(left[i-1], arr[i]);
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
       right[i] = max(right[i+1], arr[i]);
    for (int i = 0; i < n; i++)
       water += min(left[i],right[i]) - arr[i];

    return water;
}
int main()
{
    int t;
    fastscan(t);
    while(t--)
    {
        ll n,x;
        fastscan(n);
        vector<ll> B,C;
        for (int i = 0; i < n; i++)
        {
        	fastscan(x);
        	B.push_back(x);
        }
        cout<<findWater(B,n)<<endl;
    }
    return 0;
}