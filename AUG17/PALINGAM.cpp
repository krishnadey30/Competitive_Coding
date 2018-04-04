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
    int t;
    fastscan(t);
    while(t--)
    {
        char s[600],t[600];
        scanf("%s",s);
        scanf("%s",t);
        int n=strlen(s);
        int A[26],B[26],check=0,luck=0,repb=0,repa=0;
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        for (int i = 0; i < n; i++) {
            A[s[i]-'a']++;
            B[t[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            //cout<<A[i]<<" "<<B[i]<<endl;
            if(A[i]>1 && B[i]==0)
            {
                check=1;
            }
            if(A[i]>0 && B[i]>0)
            {
                repb=repb+B[i];
                repa+=A[i];
            }
        }
        if(repb==n && repa!=n)
            luck=1;
        if(check || luck)
            printf("A\n");
        else
            printf("B\n");
    }
    return 0;
}