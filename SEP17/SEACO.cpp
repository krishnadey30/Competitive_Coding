/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor
*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll maxvalue=1000000007 ;
ll mod(ll n1,ll n2)
{
    //printf("%lld\n",n2);
    return n1>=0 ? n1%n2 :(n2+n1)%n2;
}
void fastscan(ll &no)
{
    register int x=gc();
    ll neg=0;
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
void add(ll arr[], ll N, ll lo, ll hi, ll val)
{
    arr[lo] = (arr[lo]+val);
    arr[lo]=mod(arr[lo],maxvalue);
    if (hi != N - 1)
    {
       arr[hi + 1] =(arr[hi + 1]- val);
       arr[hi + 1]=mod(arr[hi + 1],maxvalue);
    }

}
void updateArray(ll arr[], ll N)
{
    for (ll i = 1; i < N; i++)
    {
        arr[i] = (arr[i] +arr[i - 1]);
        arr[i]=mod(arr[i],maxvalue);
    }
}
void printArr(ll arr[], ll N)
{
    updateArray(arr, N);
    for (ll i = 0; i < N; i++)
        cout << mod(arr[i],maxvalue) << " ";
    cout << endl;
}
void updatefenwick(ll Fentree[], ll n, ll index, ll val)
{
    index = index + 1;
    while (index <= n)
    {
        Fentree[index] += val;
        Fentree[index]=mod(Fentree[index],maxvalue);
        index += index & (-index);
    }
}

ll *construct_tree(ll n)
{
    ll *Fentree = new ll[n+1];
    for (ll i=1; i<=n; i++)
        Fentree[i] = 0;
    return Fentree;
}
ll getSum(ll Fentree[], ll index)
{
    ll sum = 0; // Iniialize result
    index = index + 1;
    while (index>0)
    {
        sum += Fentree[index];
        index -= index & (-index);
    }
    return sum;
}
void update(ll Fentree[], ll l, ll r, ll n, ll val)
{
    updatefenwick(Fentree, n, l, val);
    updatefenwick(Fentree, n, r+1, -val);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    fastscan(t);
    while(t--)
    {
        ll n,m,j;
        fastscan(n);
        fastscan(m);
        ll C[m+1][3];
        ll Val[n],value;
        //memset(Ex,0,sizeof(Ex));
        memset(Val,0,sizeof(Val));
        for (ll i = 0; i < m; i++) {
            fastscan(C[i][0]);
            fastscan(C[i][1]);
            fastscan(C[i][2]);
            ///cout<<Ex[i]<<" ";
        }
        ll *Ex=construct_tree(m);
        //cout<<m<<mod(6,m)<<endl;
        for(ll i=m-1;i>=0;i--)
        {
            if(C[i][0]==2)
            {
                //value=
                update(Ex,C[i][1]-1 , C[i][2]-1, m, getSum(Ex,i)+1);
                
                //cout<<C[i][1]-1<<"="<<Ex[C[i][1]-1]<<" "<<C[i][2]<<"="<<Ex[C[i][2]]<<endl;
               //cout<<endl;
            }
        }
        //cout<<Ex[0]<<" ";
        //Ex[0]=Ex[0]+1;
        //cout<<endl;
        for (ll i = 0; i < m; i++) {
            if(C[i][0]==1)
            {
                add(Val, n,C[i][1]-1, C[i][2]-1,getSum(Ex,i)+1);
            }
        }
        printArr(Val,n);
    }
    return 0;
}   