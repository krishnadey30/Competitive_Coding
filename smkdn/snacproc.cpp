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
	    char A[501];
	    cin>>A;
	    int flag=0,h=0,t=0;
	    for (int i = 0; i < l; i++)
	    {
	    	if(A[i]=='H')
	    	{
	    		if(h)
	    		{
	    			flag=1;
	    			break;
	    		}
	    		else
	    		{
		    		if(t)
		    		{
		    			flag=1;
		    			break;
		    		}
		    		else
		    			h=1;
		    	}
	    	}
	    	else if(A[i]=='T')
	    	{
	    		if(t)
	    		{
	    			flag=1;
	    			break;
	    		}
	    		else
	    		{
		    		if(h)
		    		{
		    			h=0;
		    		}
		    		else
		    		{
		    			flag=1;
		    			break;
		    		}
		    	}
	    	}
	    }
	    if(flag || h)
	    	cout<<"Invalid"<<endl;
	    else
	    	cout<<"Valid"<<endl;
	}	
	return 0;
}