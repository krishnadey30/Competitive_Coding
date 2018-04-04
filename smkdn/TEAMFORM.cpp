#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	int n,m;
    	cin>>n>>m;
    	int A[m][2];
    	for (int i = 0; i < m; i++)
    	{
    		cin>>A[i][0]>>A[i][1];
    	}
    	if((n-(2*m))%2!=0)
    		cout<<"no"<<endl;
    	else
    		cout<<"yes"<<endl;
    }
    return 0;
}