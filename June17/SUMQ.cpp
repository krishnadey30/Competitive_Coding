#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	long long p,q,r,a,b;
    	cin>>p>>q>>r;
    	long long A[p],B[q],C[r],M[p],N[r];
    	for (int i = 0; i < p; i++)
    	{
    		cin>>A[i];
    	}
    	for (int i = 0; i < q; i++)
    	{
    		cin>>B[i];
    	}
    	for (int i = 0; i < r; i++)
    	{
    		cin>>C[i];
    	}
    	sort(A,A+p);
    	sort(B,B+q);
    	sort(C,C+r);
    	M[0]=A[0];
    	for (int i = 1; i < p; i++)
    	{
    		M[i]=M[i-1]+A[i];
    	}
    	N[0]=C[0];
    	for (int i = 1; i < r; i++)
    	{
    		N[i]=N[i-1]+C[i];
    	}
    	long long sum=0,m=1000000007;   	
    	for (int i = 0; i < q; i++)
    	{
    		a=upper_bound(A,A+p,B[i])-A;
    		b=upper_bound(C,C+r,B[i])-C;
            //cout<<a<<" "<<b<<endl;
    		a--;
    		b--;
            if(a>=0 && b>=0)
    		  sum=(sum%m+((N[b]%m+(B[i]*(b+1))%m)%m*(M[a]%m+((a+1)*B[i])%m)%m)%m)%m;

    	}
    	cout<<sum<<endl;
    }
    return 0;
}