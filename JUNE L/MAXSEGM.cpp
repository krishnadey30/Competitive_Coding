/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor
*/
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void scanlongint(long int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
long long int sumofsubarray(long int arr[],long int W[], int n)
{
    unordered_set<long int> s;
    int j = 0;
    long long int ans = 0,max=-1;
    for (int i=0; i<n; i++)
    {
        while (j < n && s.find(arr[j]) == s.end())
        {
        	ans+=W[j];
            s.insert(arr[j]);
            j++;
        }
        if(ans>max)
        	max=ans;
        s.erase(arr[i]);
        ans=ans-W[i];
    }
 
    return max;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanint(t);
    while(t--)
    {
    	int N;
    	scanint(N);
    	long int C[N];
    	long int W[N];
    	for (int i = 0; i < N; i++)
    	{
    		scanlongint(C[i]);
    	}
    	for (int i = 0; i < N; i++)
    	{
    		scanlongint(W[i]);
    	}
    	long long int ans=sumofsubarray(C,W,N);
    	cout<<ans<<endl;
    }
    return 0;
}