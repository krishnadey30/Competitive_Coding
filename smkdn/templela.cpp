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
    	int l;
    	cin>>l;
    	int A[101];
    	for (int i = 0; i < l; i++)
    	{
    		cin>>A[i];
    	}
    	if(l%2==0)
    		cout<<"no"<<endl;
    	else
    	{
    		int flag=0;
    		for (int i = 0; i < l/2; i++)
    		{
    			if(A[i]!=A[l-1-i] || A[i]!=i+1)
    			{
    				flag=1;
    				break;
    			}
    		}
    		if(A[(l/2)]!=(l/2)+1)
    		{
    			flag=1;
    		}
    		if(flag)
    			cout<<"no"<<endl;
    		else
    			cout<<"yes"<<endl;
    	}
    }
    return 0;
}