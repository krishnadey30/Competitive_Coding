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
		int l;
		cin>>l;
		int T[100000];
		int c=0;
		for (int i = 0; i < l; ++i)
		{
			cin>>T[i];
		}
		for (int i = 1; i < l; ++i)
		{
			if(i-T[i]>c)
				c=c+1;
			else
				c=i-T[i];
		}
		cout<<c+1<<endl;
	}
	return 0;
}