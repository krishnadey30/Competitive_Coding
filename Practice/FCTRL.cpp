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
        int n;
        cin>>n;
        int c=0,d=1,x;
        while((x=pow(5,d))<=n)
        {
            c=c+n/x;
            d++;
        }
        cout<<c<<endl;
    }
    return 0;
}