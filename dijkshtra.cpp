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
		ll N,A,u,v,s,w;
    	fastscan(N);
      	fastscan(A);
      	vpll AL[N+1];
      	vll dist(N+1,INF);
		for (int i = 0; i < A; i++)
		{
			fastscan(u);
			fastscan(v);
			fastscan(w);
			AL[u].push_back(pll(v,w));
			AL[v].push_back(pll(u,w));
		}
		fastscan(s);
		dist[s]=0;
		priority_queue< pll, vpll ,greater<pll> >pq;
		pq.push(pll(0,s));
		while(!pq.empty())
		{
			pll front=pq.top();pq.pop();
			ll d=front.first, u=front.second;
			if(d>dist[u])continue;
			for (int i = 0; i < (ll)AL[u].size(); i++)
			{
				pll V= AL[u][i];
				if(dist[u]+V.second < dist[V.first])
				{
					dist[V.first]=dist[u]+V.second;
					pq.push(pll(dist[V.first],V.first));
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