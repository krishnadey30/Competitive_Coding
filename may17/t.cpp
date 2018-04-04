#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  char c,A[100][100],B[100][100];
  int i=0,j=0;
  while(t--)
  {
  	cin>>c;
  	if(c=='+')
  		cin>>A[i++];
  	else
  		cin>>B[j++];
  }
  for (int i1 = 0; i1 <i ; i1++)
  {
  	cout<<A[i1]<<endl;
  }
  cout<<endl;
  for (int i = 0; i < j; i++)
  {
  	cout<<B[i]<<endl;
  }
  return 0;
}