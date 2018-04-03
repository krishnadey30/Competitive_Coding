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
#define INF LLONG_MAX
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
    ll t;
    fastscan(t);
    while(t--)
    {
		ll N,A,u,v,s;
		fastscan(N);
		fastscan(A);
		vll AM[N+1];
		vll dist(N+1,INF);
		for (int i = 0; i < A; i++)
		{
			fastscan(u);
			fastscan(v);
			AM[u].push_back(v);
			AM[v].push_back(u);
		}
		fastscan(s);
		dist[s]=0;
		queue <ll> q;
		q.push(s);
		while(!q.empty())
		{
			u=q.front();q.pop();
			for (int i = 0; i < (ll)AM[u].size(); i++)
			{
				v=AM[u][i];
				if (dist[v] == INF)
				{
					dist[v]=dist[u]+6;
					q.push(v);
				}
			}
		}
		for (int i = 1; i <= N; i++)
		{
			if(i==s)continue;
			else if(dist[i]==INF)cout<<"-1 ";
			else cout<<dist[i]<<" ";
		}
		cout<<endl; 
    }
    return 0;
}