#include <bits/stdc++.h>
using namespace std;
char final[1000][1000];
int flag=1;
void check(char blocked[],char unblocked[],char filter[],int index,int bindex,int m)
{
	if(index<strlen(blocked) && index == strlen(unblocked))
	{
		filter[index]=blocked[index];
		filter[index+1]=0;
		if(m)
		{
			if(strlen(final[bindex])<strlen(filter))
				strcpy(final[bindex],filter);
		}
		else
			strcpy(final[bindex],filter);
		return;
	}
	else if(index==strlen(blocked))
	{
		flag=0;
		return;
	}
	else if( blocked[index]!=unblocked[index])
	{
		//cout<<1<<endl;
		filter[index]=blocked[index];
		filter[index+1]=0;
		if(m)
		{
			if(strlen(final[bindex])<strlen(filter))
				strcpy(final[bindex],filter);
		}
		else
			strcpy(final[bindex],filter);
		return;
	}
	else
	{
		filter[index]=blocked[index];
		check(blocked,unblocked,filter,index+1,bindex,m);
		return;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,b=0,u=0,m;
    cin>>t;
    char B[t][100],U[t][100],c,filter[100];
    
    while(t--)
    {
    	cin>>c;
    	if(c=='-')
    		cin>>B[b++];
    	else if (c=='+')
    		cin>>U[u++];
    }
    qsort(B, b, 100, (int (*)(const void *, const void *))strcmp);
    qsort(U, u, 100, (int (*)(const void *, const void *))strcmp);
    /*for (int i = 0; i < b; i++)
    {
    	cout<<B[i]<<endl;
    }
    cout<<endl;
    for (int i = 0; i < u;i++)
    {
    	cout<<U[i]<<endl;
    }*/
    for (int i = 0; i < b; i++)
    {
    	m=0;
    	for (int j = 0; j <u ; j++)
    	{
    		if(flag)
    		{
    			if(B[i][0]==U[j][0])
    			{
    				//printf("%s\n",U[j]);
	    			check(B[i],U[j],filter,0,i,m);
	    			m=1;
    			}
    			else if(B[i][0]<U[j][0])
    			{
	    			if(m==0)
	    			{
	    				final[i][0]=B[i][0];
	    				final[i][1]=0;
	    				m=1;
	    				break;
	    			}
	    			else
	    				break;
    			}
    		}
    		else
    			break;
    	}
    	if(m==0)
    	{
    		final[i][0]=B[i][0];
    		final[i][1]=0;
	    }
    	if(flag==0)
    		break;
    }
    if(flag==0)
    	cout<<-1<<endl;
    else
    {
    	//cout<<"yes"<<endl;
    	std::set<string> filtered(final,final+b);
  		std::set<string>::iterator fil;
    	cout<<filtered.size()<<endl;
    	for (fil = filtered.begin(); fil != filtered.end(); fil++)
    	{
    		cout<<*fil<<endl;
    	}
    }

    
    return 0;
}