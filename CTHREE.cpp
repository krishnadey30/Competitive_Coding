/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor ,SriCity
*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
template <typename T>
void fastscan(T &no)
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
    ll t;
    fastscan(t);
    while(t--)
    {
        ll N,a,b,c,a1,b1,c1,A[4],x,y,z,count=0,x1;
        fastscan(N);
        fastscan(a);
        fastscan(b);
        fastscan(c);
        A[0]=a;
        A[1]=b;
        A[2]=c;
        sort(A,A+3);
        a1=A[0];
        b1=A[1];
        c1=A[2];
        for (ll i = 1; i <= min((ll)sqrt(N),a1); i++)
        {
        	if(N%i==0)
        	{
        		x=i;
        		x1=N/x;
        		for (ll j = 1; j <= min((ll)sqrt(x1),b1); j++)
        		{
        			if(x1%j==0)
        			{
        				y=j;
        				if(x1/y<=c1)
        				{
        					z=x1/y;
        					//cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
        					count++;
        					if(z<=b1 && z>y)
        					{
        						//cout<<"("<<x<<","<<z<<","<<y<<")"<<endl;
        						count++;
        					}

        					if(y>sqrt(N))
        					{
        						if(y<=a1 && y>x)
        						{
        							//cout<<"("<<y<<","<<x<<","<<z<<")"<<endl;
        							count++;
        							if(z<=b1 && z>y)
        							{
        								//cout<<"("<<y<<","<<z<<","<<x<<")"<<endl;
        								count++;
        							}
        						}
        					}
        					if(z>sqrt(N))
        					{
        						if(z<=a1)
        						{
        							count+=1;
        						}
        					}
        				}
        			}
        		}
        	}
        }
        cout<<count<<endl;
    }
    return 0;
}