/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor
*/
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
        long long int A,B,N,x,y;
        cin>>A>>B>>N;
        if(N%2==0)
            x=1;
        else
            x=2;
        if(x*A>=B)
            y=(x*A)/B;
        else
            y=B/(x*A);
        cout<<y<<endl;
    }
    return 0;
}