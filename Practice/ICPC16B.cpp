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
    	int n;
    	cin>>n;
    	long long int a;
    	int one=0,onem=0,other=0;
    	for (int i = 0; i < n; i++)
    	{
    		cin>>a;
    		if(a==1)one++;
    		else if(a==-1)onem++;
    		else if(a!=0)other++;
    	}
    	if(other>1)cout<<"no"<<endl;
    	else if(other==1 && onem>0)cout<<"no"<<endl;
    	else if(onem>1 && one==0)cout<<"no"<<endl;
    	else cout<<"yes"<<endl;
    }
    return 0;
}