for _ in range(int(input())):
	n=int(input())
	x=set(map(int,input().split()))
	print(n-len(x))