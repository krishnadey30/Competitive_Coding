for _ in range(int(input())):
	n=int(input())
	A=list(map(int,input().split()))
	c,d,s=list(map(int,input().split()))
	X=[]
	X.append(A[0])
	t=2
	for i in range(1,n):
		X.append(X[i-1]+t+A[i])
	Y=[]
	Y.append(X[0]*2)
	for i in range(1,n):
		if(t+Y[i-1]>=X[i]):
			Y.append(Y[i-1]+t+A[i])
		else:
			Y.append(X[i]+A[i])
	ans=(Y[n-1]-X[n-1])*(c-1)
	print(round(ans))