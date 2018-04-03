/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor ,SriCity
*/

/*code taken from geeksforgeeks*/

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
#define level 18
ll N;
template <typename T>
void fastscan(T &no)
{
    register ll x=gc();
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
void dfs(ll cur, ll prev,vector <ll> tree[],ll depth[],ll parent[][level],ll XOR[],ll T[])
{
    if(prev!=0)
        XOR[cur]=XOR[prev]^T[cur];
    else
        XOR[cur]=T[cur];
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (ll i=0; i<tree[cur].size(); i++)
    {
        if (tree[cur][i] != prev)
            dfs(tree[cur][i], cur,tree,depth,parent,XOR,T);
    }
}
void precomputeSparseMatrix(ll n,ll parent[][level])
{
    for (ll i=1; i<level; i++)
    {
        for (ll node = 1; node <= n; node++)
        {
            if (parent[node][i-1] != -1)
                parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }
}
ll lca(ll u, ll v,ll depth[],ll parent[][level])
{
    if (depth[v] < depth[u])
        swap(u, v);
 
    ll diff = depth[v] - depth[u];
    for (ll i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];
    if (u == v)
        return u;
    for (ll i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
 
    return parent[u][0];
}
 
void addEdge(ll u,ll v,vll tree[])
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}
int main()
{
    fastscan(N);
    vll tree[N+1];
    ll depth[N+1],XOR[N+1];
    ll parent[N+1][level];
    ll Q,T[N],a,b,x;
    memset(parent,-1,sizeof(parent));
    fastscan(Q);
    for (ll i = 1; i < N+1; i++)
    {
        fastscan(T[i]);
    }
    for (ll i = 0; i < N-1; i++)
    {
        fastscan(a);
        fastscan(b);
        addEdge(a,b,tree);
    }
    depth[0] = 0;
    dfs(1,0,tree,depth,parent,XOR,T);
    precomputeSparseMatrix(N,parent);
    for (ll i = 0; i < Q; i++)
    {
        fastscan(a);
        fastscan(b);
        x=(XOR[a]^XOR[b])^T[lca(a,b,depth,parent)];
        cout<<x<<endl;
    }
    return 0;
}