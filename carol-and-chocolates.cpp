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
#define INF 1000000007
vector<long long> f(100000 + 1,1);
void fastscan(int &no)
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
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long C(int n, int r, int MOD)
{
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
int main()
{
    int N,K;
    for (int i=2; i<=100000;i++)
        f[i]= (f[i-1]*i) % INF;
    fastscan(N);
    fastscan(K);
    ll sum=0;
    for (int i = K; i < N-1; i++)
    {
        sum=(sum%INF + C(N, i,INF)%INF)%INF;
    }
    sum=(sum%INF + (N+1)%INF)%INF
    cout<<sum<<endl;
    return 0;
}