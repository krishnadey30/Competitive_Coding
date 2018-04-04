#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, int graph[1004][5], int path[],int index[], int pos,int n)
{
    if (graph [ index[path[pos-1]]][ v ] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == graph [ index[path[pos-1]] ][ v ])
            return false;
 
    return true;
}

bool hamCycleUtil(int graph[1004][5], int path[],int index[], int pos,int c,int n)
{
    /* base case: If all vertices are included in Hamiltonian Cycle */
    if (pos == c)
    {
        return true;
    }
 
    // Try different vertices as a next candidate in Hamiltonian Cycle.
    // We don't try for 4 as we included 1005 as starting point in in hamCycle()
    if(path[pos-1]!=1005)
    {
	    for (int v = 0; v < 3; v++)
	    {
	        /* Check if this vertex can be added to Hamiltonian Cycle */
	        if (isSafe(v, graph, path,index,pos,n))
	        {
	            path[pos] = graph[index[path[pos-1]]][v];
	 
	            /* recur to construct rest of the path */
	            if (hamCycleUtil (graph, path,index, pos+1,c,n) == true)
	                return true;
	 
	            /* If adding vertex v doesn't lead to a solution,
	               then remove it */
	            path[pos] = -1;
	        }
	    }
	 
	    /* If no vertex can be added to Hamiltonian Cycle constructed so far,
	       then return false */
	    return false;
	}
	else
	{
		for(int v=0;v<c;v++)
		{
			path[pos]=graph[v][4];
			if (hamCycleUtil (graph, path,index, pos+1,c,n) == true)
		        return true;
		 
		    /* If adding vertex v doesn't lead to a solution,
		       then remove it */
		    path[pos] = -1;
	      	
	    }
	 
	    /* If no vertex can be added to Hamiltonian Cycle constructed so far,
	       then return false */
	    return false;
	}
}


bool hamCycle(int graph[1004][5],int c,int n,int index[])
{
    int *path = new int[c];
    for (int i = 0; i < c; i++)
    {
        path[i] = -1;
    }
    path[0] = 1005;
    if ( hamCycleUtil(graph, path,index, 1,c,n) == false )
    {
        cout<<"no"<<endl;
        return false;
    }
 	cout<<"yes"<<endl;
    //printSolution(path);
    return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	int n,c=0;
    	cin>>n;
    	int V[1004][5]={{0}},index[2*n+2]={-1};
    	char S1[n+1],S2[n+1];
    	cin>>S1>>S2;
    	for (int i = 0; i < n; i++)
    	{
    		if(S1[i]=='#')
    		{
    			if(i==0)
    			{
    				if(S1[1]=='#')
    				{
    					V[c][0]=2;
    				}
    				if(S2[0]=='#')
    				{
    					V[c][1]=n+1;
    				}
    				V[c][3]=1005;
    			}
    			else if(i==n-1)
    			{
    				if(S1[n-2]=='#')
    				{
    					V[c][0]=n-1;
    				}
    				if(S2[n-1]=='#')
    				{
    					V[c][1]=2*n;
    				}
    				V[c][3]=1005;
    			}
    			else
    			{
    				if(S1[i-1]=='#')
    				{
    					V[c][0]=i;
    				}
    				if(S1[i+1]=='#')
    				{
    					V[c][1]=i+2;
    				}
    				if(S2[i]=='#')
    				{
    					V[c][2]=i+n+1;
    				}
    				V[c][3]=1005;
    			}
    			V[c][4]=i+1;
    			index[i+1]=c;
    			c++;
    		}
    		if(S2[i]=='#')
    		{
    			if(i==0)
    			{
    				if(S2[1]=='#')
    				{
    					V[c][0]=n+2;
    				}
    				if(S1[0]=='#')
    				{
    					V[c][1]=1;
    				}
    				V[c][3]=1005;
    			}
    			else if(i==n-1)
    			{
    				if(S2[n-2]=='#')
    				{
    					V[c][0]=2*n-1;
    				}
    				if(S1[n-1]=='#')
    				{
    					V[c][1]=n;
    				}
    				V[c][3]=1005;
    			}
    			else
    			{
    				if(S2[i-1]=='#')
    				{
    					V[c][0]=i+n;
    				}
    				if(S2[i+1]=='#')
    				{
    					V[c][1]=i+n+2;
    				}
    				if(S1[i]=='#')
    				{
    					V[c][2]=i+1;
    				}
    				V[c][3]=1005;
    			}
    			V[c][4]=n+i+1;
    			index[n+i+1]=c;
    			c++;
    		}
    	}
    	/*for (int i = 0; i < c; i++)
    	{
    		for(int j=0;j<5;j++)
    		{
    			cout<<V[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    	cout<<c+1<<endl;*/
    	hamCycle(V,c+1,n,index);
    }
    return 0;
}
