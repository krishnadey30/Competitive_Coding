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
    	int n,count=0,countn=0;
    	cin>>n;
    	long long int F[n],a;
    	long long int m=0,x=0,sum;
    	for (int i = 0; i < n; i++)
    	{
    		cin>>a;
    		if(a>=0)
    		{
    			count++;
    			m+=a;
    		}
    		else
    		{
    			F[countn++]=a;
    		}
    	}
    	sum=m*count;
    	sort(F,F+countn);
    	for (int i = countn-1; i >=0; i--)
    	{
    		x=m+F[i];
    		x=x*(count+1);
    		//cout<<x<<endl;
    		if(x>=sum)
    		{
    			sum=x;
    			m=m+F[i];
    			count++;
    			countn--;
    		}
    		else
    			break;
    	}
    	for (int i = 0; i < countn; i++)
    	{
    		sum+=F[i];
    	}
    	cout<<sum<<endl;
    }
    return 0;
}