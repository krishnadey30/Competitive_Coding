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
ll compress(char A[],ll n, char B[])
{
	B[0]=A[0];
    ll j=1;
    for (ll i = 1; i < n; i++)
	{
		if(B[j-1]!=A[i])
		{
			B[j++]=A[i];
		}
	}
	return j;
}
int main()
{
    ll t;
    fastscan(t);
    while(t--)
    {
        ll n1,n2,i,j;
        fastscan(n1);
        fastscan(n2);
        char A[n1+2],B[n2+2],C[n1+2],D[n2+2];
        cin>>A>>B;
		ll l1,l2;
		l1=compress(A,n1,C);
		l2=compress(B,n2,D);
		ll L[l1+2][l2+2];
        for (i=0; i<=l1; i++)
		{
			for (j=0; j<=l2; j++)
			{
				if (i == 0 || j == 0)
					L[i][j] = 0;

				else if (C[i-1] == D[j-1])
					L[i][j] = L[i-1][j-1] + 1;

				else
					L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
		cout<<l1+l2-L[l1][l2]<<endl;
	    
    }
    return 0;
}