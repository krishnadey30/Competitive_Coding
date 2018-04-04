n=int(input())
for i in range(0,n):
	x=input()
	y=x.split('U')
	z=x.split('D')
	a=len(y)
	b=len(z)
	a=a-y.count('')
	b=b-z.count('')
	if(a>b):
		print(b)
	else:
		print(a)
