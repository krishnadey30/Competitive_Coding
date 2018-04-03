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

class UnionFind
{
	private:
		vll Parent,rank;
	public:
		UnionFind(int N)
		{
			rank.assign(N,0);
			Parent.assign(N,0);
			for (int i = 0; i < N; i++)
			{
				Parent[i]=i;
			}
		}
		ll findSet(ll i)
		{
			return (Parent[i] == i) ? i :(findSet(Parent[i]));
		}
		bool isSameSet(ll i, ll j)
		{
			return findSet(i) == findSet(j);
		}
		void unionSet(ll i, ll j)
		{
			if (!isSameSet(i,j))
			{
				ll x=findSet(i);
				ll y=findSet(j);
				if(rank[x] > rank[y])
				{
					Parent[y]=x;
				}
				else
				{
					Parent[x]=y;
					if(rank[x] == rank[y])
						rank[y]++;
				}
			}
		}
};

bool compare(pair <ll,pll> a, pair <ll,pll> b)
{
	if(a.first != b.first)
	{
		return a.first < b.first;
	}
	return (a.second.first + a.second.second)<(b.second.first + b.second.second);
}

int main()
{
	ll V,E,u,v,w;
	fastscan(V);
	fastscan(E);
	vector < pair <ll,pll> > EdgeList;
	for (ll i = 0; i < E; i++)
	{
		fastscan(u);
		fastscan(v);
		fastscan(w);
		EdgeList.push_back(make_pair(w,pll(u,v)));
	}
	sort(EdgeList.begin(),EdgeList.end(),compare);
	ll mst_cost = 0;
	UnionFind UF(V);
	for (ll i = 0; i < E; i++)
	{
		pair <ll,pll>  front =EdgeList[i];
		if(!UF.isSameSet(front.second.first, front.second.second))
		{
			mst_cost += front.first;
			UF.unionSet(front.second.first,front.second.second);
		}
	}
	cout<<mst_cost<<endl;
	return 0;
}
