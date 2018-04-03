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
int main()
{
    int t;
    fastscan(t);
    while(t--)
    {
        char S[100002];
       	scanf(" %s",S);
       	ll n=strlen(S);
        char V[100002];
        ll A[100001],x=0;
        //memset(A,0,sizeof(A));
        V[x]=S[0];
        A[x]=1;
        for (ll i = 1; i < n; i++)
        {
        	if(V[x]==S[i])
        		A[x]++;
        	else
        	{
        		x++;
        		V[x]=S[i];
        		A[x]=1;
        	}
        }
        ll c=0;
        x++;
        for (ll i = 0; i < x; i++)
        {
        	//cout<<V[i]<<":"<<A[i]<<endl;
        	c+=(A[i]*(A[i]-1))/2;
        	if(i<x-2 && V[i]==V[i+2])
        	{
        		c+=1;
        	}
        }
        cout<<c<<endl;
    }
    return 0;
}