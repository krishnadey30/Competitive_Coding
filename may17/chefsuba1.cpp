#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K,P;
    cin>>N>>K>>P;
    int A[N],B[N];
    for (int i = 0; i < N; i++)
    {
    	cin>>A[i];
    	B[i]=0;
    }
    char Q[P];
   	cin>>Q;
    for (int i = 0; i < N-K+1; i++)
    {
    	for(int j=0;j<K;j++)
    	{
    		B[i]+=A[i+j];
    	}
    	//cout<<B[i]<<endl;
    }
    std::queue<int> S;
    priority_queue<int> pq;
    int a,b=0,c,d;
    for (int i = N-K; i >=0 ; i--)
   	{
   		S.push(B[i]);
   		pq.push(B[i]);
   	}
   	d=K-1;
    for (int i = 0; i < P; i++)
   	{
   		if(Q[i]=='!')
   		{
   			c=S.front();
   			if(c==pq.top())
   			{
   				pq.pop();
   			}
   			S.pop();
   			a=S.back();
   			//cout<<a<<" ,"<<endl;
   			if(a==K)
   			{
   				if(A[N-b-1]==1)
   				{
   					S.push(K);
   					pq.push(K);
   				}
   				else
   				{
   					S.push(K-1);
   					pq.push(K-1);
   				}
   			}
   			else
   			{
   				if(A[N-b-1]==1)
   				{
   					if(A[d]==1)
   					{
	   					pq.push(a);
	   					S.push(a);
	   				}
	   				else
	   				{
						pq.push(a+1);
	   					S.push(a+1);
	   				}
   				}
   				else
   				{
   					if(A[d]==1)
   					{
   						pq.push(a-1);
   						S.push(a-1);
   					}
   					else
   					{
   						pq.push(a);
   						S.push(a);
   					}
   				}
   			}
   			b++;
   			d--;
   			if(N-b-1<0)
   				b=0;
   			if(d<0)
   				d=N-1;
   		}
   		else
   		{
   			cout<<pq.top()<<endl;
   		}
   	}
   	return 0;
}