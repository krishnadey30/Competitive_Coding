for _ in range(int(input())):
	n,m,x,k=list(map(int,input().split()))
	string=list(input())
	we=string.count('E')
	wo=string.count('O')
	me=m//2
	mo=m-me
	a=min(me*x,we)
	b=min(mo*x,wo)
	if(a+b>=n):
		print('yes')
	else:
		print('no') 