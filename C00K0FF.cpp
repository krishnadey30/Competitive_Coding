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
    	int N,flag=1;
        fastscan(N);
        char A[100000],b;
        int B[5];
        memset(B,0,sizeof(B));
        for (int i = 0; i < N; i++)
	     {
	     	scanf("%s",A);
	     	if(strcmp(A,"cakewalk")==0)
	     		B[0]++;
	     	else if (strcmp(A,"simple")==0)
	     		B[1]++;
	     	else if(strcmp(A,"easy")==0)
	     		B[2]++;
	     	else if(strcmp(A,"easy-medium")==0 || strcmp(A, "medium")==0)
	     		B[3]++;
	     	else
	     		B[4]++;
	     } 
	     for (int i = 0; i < 5; ++i)
	     {
	     	if(B[i]==0)
	     	{
	     		printf("No\n");
	     		flag=0;
	     		break;
	     	}
	     }
	     if(flag)
	     	printf("Yes\n");
    }
    return 0;
}