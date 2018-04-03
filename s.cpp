    #include <bits/stdc++.h>
    using namespace std;
    long long int ** dynamicallocte(long long int **A,int n)
    {
        A=new long long int*[n/2];
        for (int i = 0; i < n/2; i++)
        {
            A[i]=new long long int[n/2];
        }
        return A;
    }
    void assign(long long int** A,long long int** B,int a,int b,int n)
    {
        int i,j,i1,j1;
        for(i=0,i1=a;i<n/2;i++,i1++)
        {
            for(j=0,j1=b;j<n/2;j++,j1++)
            {
                B[i][j]=A[i1][j1];
            }
        }
    }
    void merge(long long int** A,long long int** B,int a,int b,int n)
    {
        int i,j,i1,j1;
        for(i=0,i1=a;i<n/2;i++,i1++)
        {
            for(j=0,j1=b;j<n/2;j++,j1++)
            {
                B[i1][j1]=A[i][j];
            }
        }
    }
    long long int** add(long long int** A,long long int** B,int n,long long int** F)
    {
        int i,j;
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                F[i][j]=A[i][j]+B[i][j];
            }
        }
        return F;
    }
    long long int** sub(long long int** A,long long int** B,int n,long long int** F)
    {
        int i,j;
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                F[i][j]=A[i][j]-B[i][j];
            }
        }
        return F;
    }
    long long int** strassens(long long int** A,long long int** B,int n,long long int** F)
    {
        
        if(n==1)
        {
            F[0][0]=A[0][0]*B[0][0];
        }
        else
        {
            long long int **A11,**A12,**A21,**A22;
            long long int **B11,**B12,**B21,**B22;
            A11=dynamicallocte(A11,n);
            A12=dynamicallocte(A12,n);
            A21=dynamicallocte(A21,n);
            A22=dynamicallocte(A22,n);
            B11=dynamicallocte(B11,n);
            B12=dynamicallocte(B12,n);
            B21=dynamicallocte(B21,n);
            B22=dynamicallocte(B22,n);
            assign(A,A11,0,0,n);
            assign(A,A12,0,n/2,n);
            assign(A,A21,n/2,0,n);
            assign(A,A22,n/2,n/2,n);
            assign(B,B11,0,0,n);
            assign(B,B12,0,n/2,n);
            assign(B,B21,n/2,0,n);
            assign(B,B22,n/2,n/2,n);
            long long int **P1,**P2,**P3,**P4,**P5,**P6,**P7;
            P1=dynamicallocte(P1,n);
            P2=dynamicallocte(P2,n);
            P3=dynamicallocte(P3,n);
            P4=dynamicallocte(P4,n);
            P5=dynamicallocte(P5,n);
            P6=dynamicallocte(P6,n);
            P7=dynamicallocte(P7,n);
            long long int **C11,**C12,**C21,**C22,**X,**Y;
            C11=dynamicallocte(C11,n);
            C12=dynamicallocte(C12,n);
            C21=dynamicallocte(C21,n);
            C22=dynamicallocte(C22,n);
            X=dynamicallocte(X,n);
            Y=dynamicallocte(Y,n);
            X=sub(B12,B22,n,X);
            P1=strassens(A11,X,n/2,P1);
            X=add(A11, A12,n,X);
            P2=strassens(X, B22,n/2,P2);
            X=add(A21, A22,n,X);
            P3=strassens(X, B11,n/2,P3);
            X=sub(B21, B11,n,X);
            P4=strassens(A22, X,n/2,P4);
            X=add(A11, A22,n,X);
            Y=add(B11, B22,n,Y);
            P5=strassens(X, Y,n/2,P5);
            X=sub(A12, A22,n,X);
            Y=add(B21, B22,n,Y);
            P6=strassens(X, Y,n/2,P6);
            X=sub(A11, A21,n,X);
            Y=add(B11, B12,n,Y);
            P7=strassens(X, Y,n/2,P7);
            X=add(P5,P4,n,X);
            Y=add(X,P6,n,Y);
            C11=sub(Y,P2,n,C11);
            C12=add(P2,P1,n,C12);
            C21=add(P3,P4,n,C21);
            X=add(P1,P5,n,X);
            Y=sub(X,P3,n,Y);
            C22=sub(Y,P7,n,C22);
            merge(C11,F,0,0,n);
            merge(C12,F,0,n/2,n);
            merge(C21,F,n/2,0,n);
            merge(C22,F,n/2,n/2,n);
        }
        return F;
    }
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n,i,j;
            cin>>n;
            long long int **A,**B;
            A=dynamicallocte(A,2*n);
            B=dynamicallocte(B,2*n);
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    cin>>A[i][j];
            }
            B=strassens(A,A,n,B);
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    printf("%lld ",B[i][j]);
                printf("\n");
            }
        }
        return 0;
    }