for _ in range(int(input())):
	n=int(input())
	A=list(map(int,input().split()))
	B=list(map(int,input().split()))
	x=sum(A)
	y=sum(B)
	x=x-max(A)
	y=y-max(B)
	if(x>y):
		print("Bob")
	elif(y>x):
		print("Alice")
	else:
		print("Draw")