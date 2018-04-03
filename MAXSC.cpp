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
ll floorSearch(ll arr[], ll low, ll high, ll x)
{
	if(low>high)
		return -1;
    if (x > arr[high])
        return high;
    int mid = (low+high)/2;
    if (arr[mid] == x)
        return mid;

    if (mid > 0 && arr[mid-1] <= x && x < arr[mid])
        return mid-1;
    if (x < arr[mid])
        return floorSearch(arr, low, mid-1, x);
    return floorSearch(arr, mid+1, high, x);
}
int main()
{
    ll t;
    fastscan(t);
    while(t--)
    {
        ll n;
        fastscan(n);
        ll A[n+1][n+1];
        for (ll i = 0; i < n; i++)
        {
        	for (ll j = 0; j< n; j++)
        	{
        		fastscan(A[i][j]);
        	}
        	sort(A[i],A[i]+n);
        }
        ll sum=0, max,cur_max=A[n-1][n-1],ind,flag=1;
        max=cur_max;
        for (ll i = n-2; i >= 0; i--)
        {
        	ind=floorSearch(A[i],0,n-1,cur_max-1);
        	if(ind !=-1)
        	{
	        	cur_max=A[i][ind];
	        	max+=cur_max;
        	}
        	else
        	{
        		flag=0;
	        	break;
        	}
        }
        if(flag==1)
        	cout<<max<<endl;
    	else
    		cout<<-1<<endl;

    }
    return 0;
}