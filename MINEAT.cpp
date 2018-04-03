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
bool value(ll i,ll N,ll *B,ll H)
{
    ll sumh,sumb;
    sumh=sumb=i+1;
    for(ll j = i+1 ;j < N ; j++)
    {
        sumh+=ceil((float)B[j]/B[i]);
        sumb++;
        if(sumh>H)
            break;
    }
    if(sumh<=H && sumb==N)
    {
        return true;
    }
    return false;
}
ll lowerBound(ll H, ll N, ll *B,ll i)
{
    ll low = i, high = N - 1, mid, ans;
    while(low <= high){
        mid = (low+high)/2;
        if(value(mid,N,B,H)){
            ans=mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return ans;
 
}
bool value1(ll ans,ll N,ll *B,ll H)
{
    ll sumh=0;
    for(ll j=0;j<N ;j++)
    {
        sumh+=ceil((float)B[j]/ans);
        if(sumh>H)
            break;
    }
    if(sumh>H)
    {
        return false;
    }
    else
       return true;
}
ll lowerBound1(ll low,ll high,ll H,ll N,ll *B)
{
    ll mid,ans;
    while(low <= high){
        mid = (low+high)/2;
        if(value1(mid,N,B,H)){
            ans=mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
	ll t;
	fastscan(t);
	while(t--)
	{
		ll N,H;
		fastscan(N);
		fastscan(H);
		ll B[N+1],ans,h,l;
		for (ll i = 0; i < N; i++)
		{
			fastscan(B[i]);
		}
		sort(B,B+N);
        ans=lowerBound(H,N,B,0);
        if(ans-1>=0)
        {
            l=B[ans-1]+1;
        }
        else
        {
            l=1;
        }
        h=B[ans];
        ans=lowerBound1(h,l,H,N,B);
        cout<<ans<<endl;
	}
	return 0;
}
