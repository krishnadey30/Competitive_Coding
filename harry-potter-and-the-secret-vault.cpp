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
int are_all_0s(string S,int n)
{
	for (int i = 1; i < n; i++)
	{
		if(S[i]!='0')
			return 0;
	}
	return 1;
}
void generate_previous_palindrome(string &P,int n)
{
	int mid = n/2;
    bool leftsmaller = false;
    int i = mid - 1,x;
    int j = (n % 2)? mid + 1 : mid;
    while(i >= 0 && P[i] == P[j])
    {
		i--;
		j++;
    }
    if( i >= 0 && P[i] < P[j])
    {
		leftsmaller = true;
    }
    x=i;
    i = mid - 1;
    j = (n % 2)? mid + 1 : mid;
    while (i >= 0)
    {
        P[j] = P[i];
        j++;
        i--;
    }
    if(leftsmaller==false && x>=0)
    {
    	int carry = -1;
        i = mid - 1;
        if (n%2 == 1)
        {
            x=(P[mid]-'0')+carry;
            if(x<0)
            	P[mid]='9',carry=-1;
            else
            	P[mid]=x+'0',carry=0;
            j = mid + 1;
        }
        else
            j = mid;
        while (i >= 0 && carry!=0)
        {
            x=(P[i]-'0')+carry;
            if(x<0)
            	P[i]='9',carry=-1;
            else
            	P[i]=x+'0',carry=0;
            P[j++] = P[i--]; 
        }
    }
}
void generate_palindrome(string &P,int n)
{
	if(are_all_0s(P,n))
	{
		if(P[0]=='1')
		{
			for(int i = 1; i < n; i++ )
            	printf( "9" );
            printf("\n");
		}
		else
		{
			int x=P[0]-'0';
			cout<<x-1;
			for(int i = 1; i < n-1; i++ )
            	cout<<'9';
            cout<<x-1<<endl;
		}
	}
	else
	{
		generate_previous_palindrome(P,n);
		cout<<P<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    fastscan(t);
    while(t--)
    {
        string P;
        int n;
        getline(cin,P);
        n=P.size();
        if(n==1)
        	cout<<P<<endl;
        else
        	generate_palindrome(P,n);
    }
    return 0;
}