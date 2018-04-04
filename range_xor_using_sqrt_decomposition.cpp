#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
	ll n,i,j,s,ans,q,a,b,c,value;
	cin>>n;
	ll A[n],B[(int)sqrt(n)+2];
	for (i = 0; i < n; i++)
	{
		cin>>A[i];
	}
	ll k=sqrt(n);
	j=s=ans=0;
	for(i=0;i<n;i++)
	{
		if(j==k)
		{
			j=0;
			B[s++]=ans;
			i--;
			ans=0;
		}
		else
		{
			ans^=A[i];
			j++;
		}
	}
	B[s++]=ans;
	cin>>q;
	for(i = 0; i < q; i++)
	{
		cin>>ans;
		value=0;
		if(ans==1)
		{
			cin>>ans>>j;
			a=ans/k;
			b=j/k;
			value=0;
			if(a!=b)
			{
				if(a*k!=ans)
					for(c=ans;c<(a*k)+k;c++)
						value^=A[c];
				else
					value^=B[a];
				for(c=a+1;c<b;c++)
				{
					value^=B[c];
				}
				if((b*k)+k-1!=j)
					for(c=b*k;c<=j;c++)
						value^=A[c];
				else
				{
					value^=B[b];
				}
			}
			else
			{
				if(a*k==ans && (a*k)+k-1==j)
					value^=B[a];
				else
					for(c=ans;c<=j;c++)
					{
						value^=A[c];
					}
					
			}
			cout<<value<<endl;
		}
		else
		{
			cin>>j>>value;
			A[j]=value;
			a=j/k;
			value=0;
			for(c=a*k;c<(a*k)+k;c++)
				value^=A[c];
			B[a]=value;
		}
	}
	return 0;
}