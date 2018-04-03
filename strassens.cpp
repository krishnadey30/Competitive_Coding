#include <bits/stdc++.h>
using namespace std;

void assign(long long int A[128][128],long long int B[128][128],int a,int b,int n)
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
void merge(long long int A[128][128],long long int B[128][128],int a,int b,int n)
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
void add(long long int A[128][128],long long int B[128][128],int n,long long int F[128][128])
{
	int i,j;
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n/2;j++)
		{
			F[i][j]=A[i][j]+B[i][j];
		}
	}
}
void sub(long long int A[128][128],long long int B[128][128],int n,long long int F[128][128])
{
	int i,j;
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n/2;j++)
		{
			F[i][j]=A[i][j]-B[i][j];
		}
	}
}
void strassens(long long int A[128][128],long long int B[128][128],int n,long long int F[128][128])
{
	
	if(n==2)
	{
		F[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];
		F[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1];
		F[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];
		F[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1];
	}
	else
	{
		long long int A11[128][128],A12[128][128],A21[128][128],A22[128][128];
		long long int B11[128][128],B12[128][128],B21[128][128],B22[128][128];
		assign(A,A11,0,0,n);
		assign(A,A12,0,n/2,n);
		assign(A,A21,n/2,0,n);
		assign(A,A22,n/2,n/2,n);
		assign(B,B11,0,0,n);
		assign(B,B12,0,n/2,n);
		assign(B,B21,n/2,0,n);
		assign(B,B22,n/2,n/2,n);
		long long int P1[128][128],P2[128][128],P3[128][128],P4[128][128],P5[128][128],P6[128][128],P7[128][128];
		long long int C11[128][128],C12[128][128],C21[128][128],C22[128][128],X[128][128],Y[128][128];
		sub(B12,B22,n,X);
		strassens(A11,X,n/2,P1);
		add(A11, A12,n,X);
		strassens(X, B22,n/2,P2);
		add(A21, A22,n,X);
		strassens(X, B11,n/2,P3);
		sub(B21, B11,n,X);
		strassens(A22, X,n/2,P4);
		add(A11, A22,n,X);
		add(B11, B22,n,Y);
		strassens(X, Y,n/2,P5);
		sub(A12, A22,n,X);
		add(B21, B22,n,Y);
		strassens(X, Y,n/2,P6);
		sub(A11, A21,n,X);
		add(B11, B12,n,Y);
		strassens(X, Y,n/2,P7);
		add(P5,P4,n,X);
		add(X,P6,n,Y);
		sub(Y,P2,n,C11);
		add(P2,P1,n,C12);
		add(P3,P4,n,C21);
		add(P1,P5,n,X);
		sub(X,P3,n,Y);
		sub(Y,P7,n,C22);
		merge(C11,F,0,0,n);
		merge(C12,F,0,n/2,n);
		merge(C21,F,n/2,0,n);
		merge(C22,F,n/2,n/2,n);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j;
		cin>>n;
		long long int A[128][128],B[128][128];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cin>>A[i][j];
		}
		strassens(A,A,n,B);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%lld ",B[i][j]);
			printf("\n");
		}
	}
	return 0;
}