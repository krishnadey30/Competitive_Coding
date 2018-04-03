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
void fastscan(ll &no)
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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q,x,y,min;
    fastscan(N);
    fastscan(Q);
    vector<ll> A;
    for (int i = 0; i < N; i++)
    {
    	fastscan(x);
    	A.push_back(x);
    }
    for (int i = 0; i < Q; i++)
    {
    	fastscan(x);
    	fastscan(y);
    	min=-1;
    	for (int j = x; j < N; j++)
    	{
    		if(A[j]<y)
    		{
    			min=j;
    			break;
    		}
    	}
    	cout<<min<<endl;
    }
    return 0;
}