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
        int n;
        fastscan(n);
        int A[n];
        if(n%2==0)
        {
            for (int i = 0; i < n; i++) {
                A[i]=i+2;
                A[i+1]=i+1;
                i++;
            }
        }
        else
        {
            for (int i = 0; i < n-1; i++) {
                A[i]=i+2;
                A[i+1]=i+1;
                i++;
            }
            A[n-1]=A[n-2];
            A[n-2]=A[n-1]+2;
        }
        for (int i = 0; i < n; i++) {
            printf("%d ",A[i]);
        }
        printf("\n");
    }
    return 0;
}