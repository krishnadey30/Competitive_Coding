/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor,Sri City
*/
#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define min LLONG_MIN
typedef long long ll;
int main()
{
    int t;
   	cin>>t;
    while(t--)
    {
        int n,m,a,b,w;
        cin>>n>>m;
        vector<vector<ll> >Mat(n,vector<ll>(n,min));
        for (int i = 0; i < m; i++)
        {
        	cin>>a>>b>>w;
        	Mat[a-1][b-1]=w;
        }
      	vector<ll> Dis(n,INF);
		Dis[0]=0;
		for (int i = 1; i < n; i++)
		{
			for(int j=0;j<i;j++)
			{
				if(Mat[j][i]!=min && Dis[i]>Dis[j]+Mat[j][i])
					Dis[i]=Dis[j]+Mat[j][i];
			}
		}
		cout<<Dis[n-1]<<endl;
    }
    return 0;
}