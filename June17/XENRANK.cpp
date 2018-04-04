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
    	long long U,V;
    	cin>>U>>V;
    	long long n=U+V;
    	long long rank=(n*(n+1)/2)+1+U;
    	cout<<rank<<endl;
    }
    return 0;
}