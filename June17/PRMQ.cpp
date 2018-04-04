#include <bits/stdc++.h>
using namespace std;
bool prime[1000000];
bool check[1000000];
vector<int> primeno;
void SieveOfEratosthenes(int n)
{   
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
        if (prime[p])
            primeno.push_back(p);

}
bool v[1000000];
int len, sp[1000000];
int MAX=1000000;
void Sieve()
{
    for (int i = 2; i < MAX; i += 2)
        sp[i] = 2;
    for (long long int i = 3; i < MAX; i += 2)
    {
        if (!v[i])
        {
            sp[i] = i;
            for (long long int j = i; (j*i) < MAX; j += 2)
            {
                if (!v[j*i])    v[j*i] = true, sp[j*i] = i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SieveOfEratosthenes(1000000);
    Sieve();
    int n;
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    int Q;
    cin>>Q;
    int B[Q][4];
    for (int i = 0; i < Q; i++)
    {
        cin>>B[i][0]>>B[i][1]>>B[i][2]>>B[i][3];
    }
    int L,R,X,Y,p,a,b,sum,count;
    for (int i = 0; i < Q; i++)
    {
        L=B[i][0];
        R=B[i][1];
        X=B[i][2];
        Y=B[i][3];
        sum=0;
        b=0;
        memset(check, true, sizeof(check));
        std::vector<int> v(A+L-1,A+R);
        sort(v.begin(),v.end());
        for(int j=v.size()-1;j>=0;j--)
        {
            p=v[j];
            count=0;
            a=0;
            if(check[p]==true)
            {
                while(p!=1)
                {
                    if(binary_search (v.begin(), v.end(), p) && check[p]==true)
                    {
                        a++;
                        b++;
                        //cout<<p<<endl;
                        check[p]=false;
                    }
                    if(sp[p]>=X && sp[p]<=Y)
                    {
                        count=a+(count);
                    }
                    if(sp[p]!=0)
                        p=p/sp[p];
                }
                /*if(sp[p]>=X && sp[p]<=Y)
                        count=a+(count);*/
                sum=sum+count;
            }
            if(b==v.size())
                break;
        }
        cout<<sum<<endl;
    }
    return 0;
}