from random import randint
print(100)
for _ in range(100):
	n=randint(5,100)
	print(n)
	for i in range(n):
		x=randint(1,100000)
		print(x,end=' ')
	print()
	print(randint(2,100),randint(1,100),randint(1,50))