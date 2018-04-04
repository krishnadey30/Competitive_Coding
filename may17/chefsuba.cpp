#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K,P;
    cin>>N>>K>>P;
    int A[N],B[N];
    std::queue<int> S;
    for (int i = 0; i < N; i++)
    {
    	cin>>A[i];
    }
   	for (int i = N-1; i >=0 ; i--)
   	{
   		S.push(A[i]);
   	}
   	char Q[P];
   	cin>>Q;
   	int a,b,max;
   	for (int i = 0; i < P; i++)
   	{
   		b=0;
   		max=0;
   		if(Q[i]=='!')
   		{
   			a=S.front();
   			S.pop();
   			S.push(a);
   		}
   		else
   		{
   			for (int j = 0; j<N; j++,S.pop())
   			{
   				B[j]=S.front();
   				S.push(B[j]);
   				//cout<<B[j]<<" ";
   				if(B[j]==1)
   					b++;
   				else
   				{
   					if(max<b)
   					{
   						max=b;
   						b=0;
   					}
   				}
   			}
   			if(b>max)
   				max=b;
   			cout<<max<<endl;

   		}

   	}
    return 0;
}