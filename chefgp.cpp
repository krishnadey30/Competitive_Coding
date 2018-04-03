/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor ,SriCity
*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
void fastscan(int &no)
{
	register int x=gc();
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
int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    fastscan(t);
    while(t--)
    {
        char S[100000];
        int x,y,A,B,n;
        cin>>S;
        fastscan(x);
        fastscan(y);
        A=B=0;
        n=strlen(S);
        for (int i = 0; i < n; i++)
        {
        	if(S[i]=='a')
        		A++;
        	else
        		B++;
        }
        string F="";
	    if(A>B)
	    {
	    	while(A>B && A>0 && B>0)
	    	{
	    		for (int i = 0; i < x && A>B && A>0 && B>0; i++)
	    		{
	    			if(A>B)
	    			{
	    				F.push_back('a');
	    				A--;
	    			}
	    		}
	    		if(B>0 && A>B)
	    		{
	    			F.push_back('b');
	    			B--;
	    		}
	    	}
	    }
	    else if(A<B)
	    {
	    	while(B>A && A>0 && B>0)
	    	{
	    		for (int i = 0; i < y && B>A && A>0 && B>0; i++)
	    		{
	    			if(B>A)
	    			{
	    				F.push_back('b');
	    				B--;
	    			}
	    		}
	    		if(A>0 && B>A)
	    		{
	    			F.push_back('a');
	    			A--;
	    		}
	    	}
	    }
	    //cout<<A<<" "<<B<<" cond1"<<endl;
	    if(A==B && A>0)
	    {
	    	while(A>0 && B>0)
	    	{
	    		if(*(F.rbegin())=='a')
	    		{
	    			F.push_back('b');
	    			F.push_back('a');
	    			A--;
	    			B--;
	    		}
	    		else
	    		{
	    			F.push_back('a');
	    			F.push_back('b');
	    			A--;
	    			B--;
	    		}
	    	}
	    }
	    //cout<<A<<" "<<B<<" cond2"<<endl;
	    if(A>0)
	    {
	    	while(A>0)
			{
	    		if(*(F.rbegin())=='a')
	    		{
	    			for (int i = 1; i < x && A>0; i++)
		    		{
		    			F.push_back('a');
		    			A--;
		    		}
		    		
	    		}
	    		else
	    		{
	    			for (int i = 0; i < x && A>0; i++)
		    		{
		    			F.push_back('a');
		    			A--;
		    		}
	    		}
	    		
	    		if(A>0)
	    			F.push_back('*');
	    	}
	    }
	    //cout<<A<<" "<<B<<" codn 3"<<endl;
	    if(B>0)
	    {
	    	while(B>0)
			{
	    		if(*(F.rbegin())=='b')
	    		{
	    			for (int i = 1; i < y && B>0; i++)
		    		{
		    			F.push_back('b');
		    			B--;
		    		}
		    		
	    		}
	    		else
	    		{
	    			for (int i = 0; i < y && B>0; i++)
		    		{
		    			F.push_back('b');
		    			B--;
		    		}
	    		}
	    		if(B>0)
	    			F.push_back('*');
	    	}
	    }
	    //cout<<A<<" "<<B<<" codn 4"<<endl;
	    cout<<F<<endl;
    }
    return 0;
}