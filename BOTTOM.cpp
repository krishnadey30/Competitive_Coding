#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(set< ll > Graph[],ll source,ll visited[],vector< ll > Travel[])
{
	visited[source]=1;
	for(auto it:Graph[source])
	{
		if(!visited[it])
		{
			Travel[source].push_back(it);
			dfs(Graph,it,visited,Travel);
		}
	}
}
int main()
{
	ll n,e;
	cin>>n;
	while(n)
	{
		ll i;
		cin>>e;
		set< ll > Graph1[n+1];
		set< ll > Graph2[n+1];
		while(e--)
		{
			ll a,b;
			cin>>a>>b;
			Graph1[a].insert(b);
			Graph2[b].insert(a);
		}
		vector< ll > Travel[n+1],Travel2[n+1];
		ll visited[n+1];
		for(i=1;i<=n;i++)
		{
			for(ll j=0;j<=n;j++)
			{
				visited[i]=0;
			}
			dfs(Graph1,i,visited,Travel);
			for(ll j=0;j<=n;j++)
			{
				visited[i]=0;
			}
			dfs(Graph2,i,visited,Travel2);
		}
		for(i=1;i<=n;i++)
		{
			ll j;
			bool flag=false;
			for(j=1;j<=n;j++)
			{
				visited[j]=0;
			}
			for(auto it:Travel2[i])
			{
				visited[it]=1;
			}
			for(auto it:Travel[i])
			{
				if(!visited[it])
				{
					flag=true;
					break;
				}
			}
			if(!flag)
				cout<<i<<" ";
		}
		cout<<endl;
		cin>>n;
	}
	return 0;
}