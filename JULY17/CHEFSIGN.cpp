/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor
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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    fastscan(t);
    while(t--)
    {
    	char S[100000];
    	scanf("%s",S);
    	int n=strlen(S);
    	int a,b,max=0;
    	for (int i = 0; i < n; i++)
    	{
    		if(S[i]=='<')
    		{
    			a=0;
    			for(;i<n;i++)
    				if(S[i]=='<')
    					a++;
    				else if(S[i]=='>')
    				{
    					i--;
    					break;
    				}
    			if(a>max)
    				max=a;
    		}
    		else if(S[i]=='>')
    		{
    			a=0;
    			for(;i<n;i++)
    				if(S[i]=='>')
    					a++;
    				else if(S[i]=='<')
    				{
    					i--;
    					break;
    				}
    			if(a>max)
    				max=a;
    		}
    	}
    	printf("%d\n",max+1);
    }
	return 0;
}