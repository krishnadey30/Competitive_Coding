#include <stdio.h>
// altering or altering  of two matrix
void altering(long long int A[128][128],long long int B[128][128],long long int Z[128][128],int m,int add)
{
	int i,j;
	int n = m/2;
	if(add==0)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				Z[i][j]=A[i][j]-B[i][j];
			}
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				Z[i][j]=A[i][j]+B[i][j];
			}
		}
	}
}
// putting every part of matrix together
void Final(long long int A[128][128],long long int B[128][128],int m,int i1,int b)
{
	int i,j,j1;
	int n = m/2;
	for(i=0;i<n;i++,i1++)
	{
		j1=b;
		for(j=0;j<n;j++,j1++)
		{
			B[i1][j1]=A[i][j];
			
		}
		
	}
}
// partition of big matrix into small
void Partion(long long int A[128][128], long long int Z[128][128], int m, int i1 , int b )
{
	int i,j,j1;
	int n = m/2;
	for (i=0;i<n;i++,i1++)
	{
		j1=b;
		for(j=0;j<n;j++,j1++)
		{
			Z[i][j] = A[i1][j1];
			//printf("%lld ",Z[i][j] );
			
		}
		//printf("\n");
	}
	//printf("\n");
	
}
// Dostrassen multiplication
void DoStrassen(long long int A[128][128], long long int B[128][128] , int m , long long int C[128][128] )
{
	//printf("%d\n",m );
	if(m!=2)
	{

		long long int A11[128][128],A12[128][128],A21[128][128],A22[128][128];
		long long int B11[128][128],B12[128][128],B21[128][128],B22[128][128];
		long long int P1[128][128],P2[128][128],P3[128][128],P4[128][128];
		long long int P5[128][128],P6[128][128],P7[128][128];
		long long int C11[128][128],C12[128][128],C21[128][128],C22[128][128];
		long long int X[128][128],Y[128][128];
		//--------------------------------------------------------------------//
		Partion(A,A11,m,0,0);
		Partion(A,A12,m,0,m/2);
		Partion(A,A21,m,m/2,0);
		Partion(A,A22,m,m/2,m/2);
		Partion(B,B11,m,0,0);
		Partion(B,B12,m,0,m/2);
		Partion(B,B21,m,m/2,0);
		Partion(B,B22,m,m/2,m/2);
		//--------------------------------------------------------------------//
		altering(B12,B22,X,m,0);
		DoStrassen(A11,X,m/2,P1);
		altering(A11, A12,X,m,1);
		DoStrassen(X, B22,m/2,P2);
		altering(A21, A22,X,m,1);
		DoStrassen(X, B11,m/2,P3);
		altering(B21, B11,X,m,0);
		DoStrassen(A22, X,m/2,P4);
		altering(A11, A22,X,m,1);
		altering(B11, B22,Y,m,1);
		DoStrassen(X, Y,m/2,P5);
		altering(A12, A22,X,m,0);
		altering(B21, B22,Y,m,1);
		DoStrassen(X, Y,m/2,P6);
		altering(A11, A21,X,m,0);
		altering(B11, B12,Y,m,1);
		DoStrassen(X, Y,m/2,P7);
		altering(P5,P4,X,m,1);
		altering(X,P6,Y,m,1);
		altering(Y,P2,C11,m,0);
		altering(P2,P1,C12,m,1);
		altering(P3,P4,C21,m,1);
		altering(P1,P5,X,m,1);
		altering(X,P3,Y,m,0);
		altering(Y,P7,C22,m,0);
		//------------------------------------------------------------------------//
		Final(C11,C,m,0,0);
		Final(C12,C,m,0,m/2);
		Final(C21,C,m,m/2,0);
		Final(C22,C,m,m/2,m/2);
		//------------------------------------------------------------------------//
	}	
	else
	{
		// multiply 2*2 matrix method 
		C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];
		C[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1];
		C[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];
		C[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1];
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int A[128][128],C[128][128];
		int i,j,m;
		scanf("%d",&m); //  enter order.
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%lld",&A[i][j]); // scaning A.
			}
		}	
		DoStrassen(A,A,m,C); // send it into function.
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%lld ",C[i][j]); // printing elements from A to B.
			}
			printf("\n");
		}
	}
	return 0;
}