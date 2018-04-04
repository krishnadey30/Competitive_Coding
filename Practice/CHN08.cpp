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
    	long long int a,b,output,c;
    	int n;
    	cin>>a>>b>>n;
    	c=n%6;
    	if(c==1)
    	{
    		output=a%1000000007;
    		if(output<0)
    			output=output+1000000007;
    		cout<<output<<endl;
    	}
    	else if(c==2)
    	{
    		output=b%1000000007;
    		if(output<0)
    			output=output+1000000007;
    		cout<<output<<endl;
    	}
    	else if(c==3)
    	{
    		output=(b-a)%1000000007;
    		if(output<0)
    			output=output+1000000007;
    		cout<<output<<endl;
    	}
    	else if(c==4)
    	{
    		output=(-1*a)%1000000007;
    		if(output<0)
    			output=output+1000000007;
    		cout<<output<<endl;
    	}
    	else if(c==5)
    	{
    		output=(-1*b)%1000000007;
    		if(output<0)
    			output=output+1000000007;
    		cout<<output<<endl;
    	}
    	else
    	{
    		output=(a-b)%1000000007;
    		if(output<0)
    			output=output+1000000007;
    		cout<<output<<endl;
    	}
    	
    }
    return 0;
}