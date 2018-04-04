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
    	char A[20];
    	int r,b,m,e,x;
    	for (int i = 0; i < 4; i++)
    	{
    		cin>>A;
    		cin>>x;
    		if(strlen(A)==9)
    			b=x;
    		else if(strlen(A)==6)
    			m=x;
    		else if(strlen(A)==10)
    			r=x;
    		else if(strlen(A)==5)
    			e=x;
    	}
    	//cout<<r<<b<<m<<r<<endl;
    	if(r>=m)
    		cout<<"RealMadrid"<<endl;
    	else
    	{
    		if(b>e)
    			cout<<"Barcelona"<<endl;
    		else
    			cout<<"RealMadrid"<<endl;
    	}
    }
    return 0;
}
    	