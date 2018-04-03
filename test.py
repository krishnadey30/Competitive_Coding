from random import randint
print(100)
for _ in range(100):
	n=randint(1,10)
	m=randint(1,100)
	x=randint(1,12)
	k=randint(1,100)
	print(n,m,x,k)
	for i in range(k):
		a=randint(1,10)
		if(a%2==0):
			print('E',end='')
		else:
			print('O',end='')
	print()
