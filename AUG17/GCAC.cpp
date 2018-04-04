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
void fastscanl(ll &no)
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
        int n,m,j;
        fastscan(n);
        fastscan(m);
        ll minsal[n],offsal[m],maxjob[m],finalsal[n],index,max,count=0;
        bool jobsoff[m];
        memset(jobsoff,false,sizeof(jobsoff));
        ll final=0;
        char qual[n][m];
        for (int i = 0; i < n; i++) {
            fastscanl(minsal[i]);
        }
        for (int i = 0; i < m; i++) {
            fastscanl(offsal[i]);
            fastscanl(maxjob[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s",qual[i]);
        }
        for (int i = 0; i < n; i++) 
        {
            index=-1;
            max=0;
            for(j = 0; j < m; j++)
            {
                if(qual[i][j]=='1')
                {
                    if(maxjob[j]>0 && offsal[j]>=minsal[i] && offsal[j]>max)
                    {
                        max=offsal[j];
                        index=j;
                    }
                }
            }
            if(index!=-1)
            {
                maxjob[index]--;
                jobsoff[index]=true;
            }
            finalsal[i]=max;
            final+=max;
            if(max!=0)
                count++;
        }
        int jobless=0;
        for (int i = 0; i < m; i++) 
        {
            if(jobsoff[i]==false)
                jobless++;
        }
        printf("%d %lld %d\n",count,final,jobless);
    }
    return 0;
}