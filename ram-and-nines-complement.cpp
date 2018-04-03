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
string removeZero(string str)
{
    int i = 0;
    while (str[i] == '0')
       i++;
    str.erase(0, i);
 
    return str;
}
string killrathan(string A, string B)
{
    string F = "";
    int n1 = A.length(), n2 = B.length();
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
 
    int carry = 0;
    for (int i=0; i<n2; i++)
    {
        int sub = ((A[i]-'0')-(B[i]-'0')-carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        F.push_back(sub + '0');
    }
    for (int i=n2; i<n1; i++)
    {
        int sub = ((A[i]-'0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        F.push_back(sub + '0');
    }
    reverse(F.begin(), F.end());
    return F;
}
int main()
{
    int t;
    fastscan(t);
    while(t--)
    {
    	string A,B,X;
    	getline(cin,A);
    	getline(cin,B);
    	string F=killrathan(A,B);
    	F=removeZero(F);
    	if(F.size()==0)
    		F.push_back('0');
    	for (int i = 0; i < F.size(); i++)
    	{
    		X.push_back('9');
    	}
    	F=killrathan(X,F);
    	cout<<F<<endl;
    }
    return 0;
}