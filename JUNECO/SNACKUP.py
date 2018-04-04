test=int(input())
for t in range(0,test):
	n=int(input())
	l=[]
	for i in range(1,n):
		l.append((i,i+1))
	l.append((n,1))
	print(n)
	for i in range(0,n):
		print(n)
		for j in range(0,n):
			print(j+1,end=" ")
			for x in l[j]:
				print(x,end=" ")
			print()
		l.append(l[0])
		l.remove(l[0])