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
#define max UINT_MAX
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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    fastscan(t);
    while(t--)
    {
        int N;
        fastscan(N);
        ll x=max/N;
        ll A[N];
        //cout<<x<<endl;
        ll y=max-N*x;
        ll z=N/y;
        z++;
        //cout<<z<<endl;
        //cout<<y<<endl;
       	for (int i = 0; i < N; ++i)
       	{
       		A[i]=x;
       		if(y-z>0)
       		{
       			A[i]+=z;
       			y=y-z;
       		}
       		else
       		{
       			A[i]+=y;
       			y=0;
       		}
       	}
       	A[N/2+N/4]+=A[N/2]-3;
       	A[N/2]=1;
       	//ll sum=0;
       	for (int i = 0; i < N; i++)
       	{
       		//sum+=A[i];
       		cout<<A[i]<<" ";
       	}
        cout<<endl;
    }
    return 0;
}