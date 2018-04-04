        /*
            Name: Krishna Kumar Dey
            Institute: Indian Institute Of Information Technology, Chittoor ,SriCity
        */
        #include <bits/stdc++.h>
        using namespace std;
        #define gc getchar_unlocked
        typedef long long ll;
        typedef vector<ll> vll;
        typedef pair<ll,ll> pll;
        typedef vector<pll> vpll;
        template <typename T>
        void fastscan(T &no)
        {
        	register int x=gc();
        	int neg=0;
        	no=0;
        	while((x<48|| x>57)&& x!='-' )
        		x=gc();
        	if(x=='-')
        	{
        		neg=1;
        		x=gc();
        	}
        	for(;x>47 && x<58;x=gc())
        	{
        		no=(no<<1)+(no<<3)+x-48;
        	}
        	if(neg)
        		no=-no;
        }
        ll A[1000005];
        ll create_sum()
        {
        	A[0]=0;
            for (ll i = i; i < 1000002; i++)
            {
                A[i]=A[i-1]+i;
            }
        }
        int main()
        {
            create_sum();
            ll t;
            fastscan(t);
            while(t--)
            {
                ll x,n,i,sum,half;
                fastscan(x);
                fastscan(n);
                ll B[n+1];
                sum=A[n]-x;
                //cout<<sum<<endl;
                if(sum%2!=0 || sum/2<2)
                {
                    cout<<"impossible"<<endl;
                }
                else
                {
                    half=(sum)/2;
                    for (int i = n; i >= 1; i--)
                    {
                        if(i!=x)
                        {
                            if(half!=0)
                            {
                                if(half-i<0 || half-i==x)
                                {
                                    B[i]=1;
                                }
                                else
                                {
                                    half-=i;
                                    B[i]=0;
                                }
                            }
                            else
                            {
                                B[i]=1;
                            }
                        }
                        else
                        {
                            B[x]=2;
                        }
                        //cout<<half<<" " <<i<<endl;
                    }
                    if(half==0)
                    {
                    for (int i = 1; i <= n; i++) {
                        cout<<B[i];
                    }
                    cout<<endl;
                    }
                    else
                    {
                        cout<<"impossible"<<endl;
                    }
                }
        	    
            }
            return 0;
        }  