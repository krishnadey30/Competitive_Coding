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
    	char elct[1000];
    	cin>>elct;
    	int n=strlen(elct);
    	int s=0,m=0,l=-2;
        for (int i = 0; i < n; i++)
        {
            if(elct[i]=='s')
                s++;
            else
                m++;
        }
    	for (int i = 0; i < n; i++)
    	{
            if(elct[i]=='m')
            {
                if(i==0)
                {
                    if(elct[i+1]=='s')
                    {
                        s--;
                        l=1;
                    }
                }
                else if(i==n-1)
                {
                    if(elct[i-1]=='s' && l!=i-1)
                    {
                        s--;
                    }
                }
                else
                {
                    if(elct[i-1]=='s' && l!=i-1)
                    {
                        s--;
                        l=i-1;
                    }
                    else if(elct[i+1]=='s' && l!=i+1)
                    {
                        s--;
                        l=i+1;
                    }
                }
            }
        }
        //cout<<m<<" "<<s<<endl;
    	if(m-s<0)
    		cout<<"snakes"<<endl;
    	else if(m-s>0)
    		cout<<"mongooses"<<endl;
    	else
    		cout<<"tie"<<endl;
    }
    return 0;
} 