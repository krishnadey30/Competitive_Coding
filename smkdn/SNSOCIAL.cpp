#include <bits/stdc++.h>
using namespace std;

int A[1000000],B[1000000],C[1000000],D[1000000],dis[1000000];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	int n,m;
    	cin>>n>>m;
    	int H[501][501],c=0,d=0,max=0;
    	
    	for (int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < m; j++)
    		{
    			cin>>H[i][j];
    			if(H[i][j]>max)
    				max=H[i][j];
    		}
    	}
    	for (int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < m; j++)
    		{
    			if(H[i][j]==max)
    			{
    				A[c]=i;
    				B[c]=j;
    				c++;
    			}
    			else
    			{
    				C[d]=i;
    				D[d]=j;
    				dis[d]=1000000;
    				d++;
    			}
    		}
    	}
    	int row,col,a,b,time=0;
    	for (int i = 0; i < d; i++)
    	{
    		row=lower_bound(A,A+c,C[i])-A;
    		col=lower_bound(B+row,B+c,D[i])-B;
    		cout<<row<<" "<<col<<endl;
    		a=(abs(C[i]-A[row])>abs(D[i]-B[col]))?abs(C[i]-A[row]):abs(D[i]-B[col]);
    		col=lower_bound(B,B+c,D[i])-B;
    		row=lower_bound(A+col,A+c,C[i])-A;
    		cout<<row<<" "<<col<<endl;
    		b=(abs(C[i]-A[row])>abs(D[i]-B[col]))?abs(C[i]-A[row]):abs(D[i]-B[col]);
    		dis[i]=(a>b)?b:a;
    		if(time<dis[i])
    			time=dis[i];
    	}
    	cout<<time<<endl;

    }
    return 0;
}