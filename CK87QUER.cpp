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
	vector<ll> A;
	A.push_back(0);
	for (ll i = 1; i < 100000; i++)
	{
		A.push_back(i*i);
	}
    int t;
    fastscan(t);
    while(t--)
    {
        ll Y,c=0,x;
        fastscan(Y);
        for (ll i = 1; i < 701; i++)
        {
        	if(Y-i>0)
        	{
        		x=lower_bound(A.begin(),A.end(),Y-i)-A.begin();
        		if(A[x]==Y-i)
        			c+=x;
        		else
        			c+=x-1;
        	}
        	else
        		break;
        }
        cout<<c<<endl;
    }
    return 0;
}