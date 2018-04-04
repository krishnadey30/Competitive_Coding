#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a=0;
    cin>>t;
    while(t--)
    {
        a++;
        int n,c=0,x;
        cin>>n;
        long long int A[n],B[n],C[n];
        for (int i = 0; i < n; i++) {
            cin>>A[i];
        }
        for (int i = 0; i < n; i++) {
            B[i]=A[i]>>16;
            C[i]=A[i]-(B[i]<<16);
           
        }
        cout<<"Case "<<a<<":"<<endl;
        for (int i = 0; i < n; i++) {
            cout<<C[i]<<" ";
        }
        cout<<endl;
        for (int i = 0; i < n; i++) {
            cout<<B[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}