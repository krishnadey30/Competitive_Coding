/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor ,SriCity
*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define max 2000000
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
        int N,K,x,c,M[max+2],z;
        memset(M,0,sizeof(M));
        fastscan(N);
        fastscan(K);
        vi A;
        for (int i = 0; i < N; i++)
        {
        	fastscan(x);
        	A.push_back(x);
        	M[x]++;
        }
        c=0;
        for (int i = 0; i < N; i++)
        {
            z=K-A[i];
            x=M[A[i]];
            if(z>0 && x>0)
            {
                if(z==A[i])
                {
                    c=c+((x*(x-1))/2);
                }
                else
                {
                    c=c+(x*M[z]);
                }
                M[A[i]]=0;
                M[z]=0;
            }
        }
        cout<<c<<endl;
        //cout<<c/2<<endl;
    }
    return 0;
}