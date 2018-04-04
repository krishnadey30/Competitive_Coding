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
       vector<string>D;
       char A[20];
       for (int i = 0; i < 4; i++) {
          cin>>A;
          D.push_back(A);
       }
       sort(D.begin(),D.end());
       int c=0;
       for (int i = 0; i < 4; i++) {
           cin>>A;
           if(binary_search(D.begin(),D.end(),A))
                c++;
       }
       if(c>=2)
            cout<<"similar"<<endl;
       else
            cout<<"dissimilar"<<endl;
    }
    return 0;
}