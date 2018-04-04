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
bool sortcol( const vector<int>& v1,const vector<int>& v2 ) 
{
 	return v1[2] > v2[2];
}
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
    	int n,d,a,j;
    	fastscan(n);
    	fastscan(d);
    	vector<vi>A;
    	for (int i = 0; i < n; i++)
    	{
    		vi X;
    		fastscan(a);
    		X.push_back(a);
    		fastscan(a);
    		X.push_back(a);
    		fastscan(a);
    		X.push_back(a);
    		A.push_back(X);
    	}
    	sort(A.begin(),A.end(),sortcol);
    	set<int> S;
    	set<int>:: iterator it;
    	for (int i = 0; i < d; i++)
    	{
    		S.insert(i+1);
    	}
    	ll sadness=0;

    	for (int i = 0; i < n; i++)
    	{
    		j=A[i][0];
    		while(A[i][1]>0 && S.size()>0)
    		{
    			it=S.lower_bound(j);
    			if(*it>=j)
    			{
    				S.erase(*it);
    				A[i][1]--;
    				j++;
    			}
    			else
    				break;
    		}
    		sadness=sadness+(ll)A[i][1]*A[i][2];
    		/*for (it = S.begin(); it != S.end(); it++)
    		{
    			cout<<*it<<" ";
    		}
    		cout<<endl<<sadness<<endl;*/
    	}
    	printf("%lld\n",sadness );
    }
	return 0;
}