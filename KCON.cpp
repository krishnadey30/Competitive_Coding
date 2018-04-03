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
ll maxSubArraySum(ll a[], ll size)
{
   ll max_so_far = a[0];
   ll curr_max = a[0];

   for (ll i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
int main()
{
    ll t;
    fastscan(t);
    while(t--)
    {
        ll n,k;
        fastscan(n);
        fastscan(k);
        ll A[n+1],sum=0,front_max,back_max,s;
        for (ll i = 0; i < n; i++)
        {
            fastscan(A[i]);
            sum+=A[i];
        }
        front_max=s=A[0];
        for (int i = 1; i < n; i++)
        {
            s+=A[i];
            if(s>=front_max)
                front_max=s;
        }
        ll max_sum = maxSubArraySum(A, n);
        s=back_max=A[n-1];
        for(ll i = n-2;i >= 0;i--)
        {
            s+=A[i];
            if(s>=back_max)
                back_max=s;
        }
        //cout<<front_max<<" "<<back_max<<" "<<max_sum<<" "<<sum<<endl;
        if(k>1)
        {
            ll finalsum=((k-2)*sum)+front_max+back_max;
            ll fsum=front_max+back_max;
            if(finalsum>max_sum)
                if(finalsum>fsum)
                    cout<<finalsum<<endl;
                else
                    cout<<fsum<<endl;
            else
                if(max_sum>fsum)
                    cout<<max_sum<<endl;
                else
                    cout<<fsum<<endl;
        }
        else
            cout<<max_sum<<endl;
    }
    return 0;
}