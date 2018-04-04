#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char T[100000];
		cin>>T;
		int l=strlen(T);
		int c1=0,c=l+1;
		int e1=0,e=l+2;
		int s1=0,s=l+3;
		int flag=1;
		for (int i = 0; i < l; i++)
		{
			if(T[i]=='C')
			{
				c1++;
				c=i;
			}
			else if(T[i]=='E')
			{
				e1++;
				e=i;
			}
			else
			{
				s1++;
				s=i;
			}
			if(c1>0)
			{
				if(s1>0 && c>s)
				{
					flag=0;
					break;
				}
				if(e1>0 && c>e)
				{
					flag=0;
					break;
				}
			}
			if(e1>0)
			{
				if(s1>0 && e>s)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}