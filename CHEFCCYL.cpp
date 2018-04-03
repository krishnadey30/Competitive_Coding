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
int min_distance(int n1,int n2,int C,vector<vector<int>> S)
{
	int n=S[C].size();
	int x=abs(S[C][n1-1]-S[C][n2-1]);
	return min(x,abs(S[C][n-1]-x));
}
int main()
{
    int t;
    fastscan(t);
    while(t--)
    {
        int N,Q,x,y,w;
        fastscan(N);
        fastscan(Q);
        vector<vector<int>> S,Swt;
        vii F;
        vector<int>size,Wt,Fwt,Min;
        for (int i = 0; i < N; i++)
        {
        	fastscan(x);
        	size.push_back(x);
        	vector<int> A,B;
        	B.push_back(0);
        	for(int j=0;j<size[i];j++)
        	{
        		fastscan(x);
        		A.push_back(x);
        		B.push_back(B[j]+x);
        	}
        	S.push_back(A);
        	Swt.push_back(B);
        }
        Fwt.push_back(0);
        for (int i = 0; i < N; i++)
        {
        	fastscan(x);
        	fastscan(y);
        	fastscan(w);
        	Wt.push_back(w);
        	F.push_back(make_pair(x,y));
        }

        w=min_distance(F[N-1].second,F[0].first,0,Swt);
        Fwt.push_back(w+Wt[0]);
        Min.push_back(w);
        for (int i = 1; i < N; i++)
        {
        	w=min_distance(F[i-1].second,F[i].first,i,Swt);
        	Min.push_back(w);
        	Fwt.push_back(Fwt[i]+w+Wt[i]);
        }
        int v1,c1,v2,c2;
        for (int i = 0; i < Q; i++)
        {
        	fastscan(v1);
        	fastscan(c1);
        	fastscan(v2);
        	fastscan(c2);
        }
        
    }
    return 0;
}