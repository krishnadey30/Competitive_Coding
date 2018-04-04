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
    	char S[100000];
    	cin>>S;
    	//cout<<S<<endl;
    	int n=strlen(S);
    	int one=0,zero=0,flag=0;
    	for (int i = 0; i < n; i++)
    	{
    		if(S[i]=='1' && one==0)
    			one=1;
    		if(one==1 && S[i]=='0')
    		{
    			zero=1;
    		}
    		if(zero==1 && S[i]=='1')
    		{
    			flag=1;
    			break;
    		}
    	}
    	if(flag==1 || one ==0 )
    		cout<<"NO"<<endl;
    	else
    		cout<<"YES"<<endl;
    }
    return 0;
}