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
    int N;
    cin>>N;
    long long int A[N],x;
    for (int i = 0; i < N; i++) {
        cin>>A[i];
    }
    sort(A,A+N);
    long long int max=0;
    for (int i = 0; i < N; i++) {
        x=A[i]*(N-i);
        if(x>max)
            max=x;
    }
    cout<<max<<"\n";
    return 0;
}
