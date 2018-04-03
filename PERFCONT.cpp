/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor,SriCity
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
        int N,P,c,h,c1=0,h1=0,x;
        fastscan(N);
        fastscan(P);
        c=P/2;
        h=P/10;
        for (int i = 0; i < N; i++)
        {
        	fastscan(x);
        	if(x>=c)
        		c1++;
        	else if(x<=h)
        		h1++;
        }
        if(c1==1 &&h1==2 )
        	cout<<"yes"<<endl;
        else
        	cout<<"no"<<endl;
    }
    return 0;
}