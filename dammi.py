for _ in range(int(input())):
	n,r=map(int,input().split())
	se=list(map(int,input().split()))
	s=0
	z=0
	k=0
	zero=-1
	ind=0
	maxi=-100000000000
	for i in se:
		if i>0:
			s=s+i
		if i<0 and abs(i)>=z:
			z=0
			zero=ind
		else:
			z=z+i
		if maxi<s:
			maxi=s
			k=ind
		if maxi<z:
			maxi=z
			k=ind
		#print(i,s,z,maxi)
		if i<0:
			s=0
		ind=ind+1
	print(maxi)
	#print(k,zero)
	if r>=2:
		s=sum(se)
		if zero<k:
			z=sum(se[zero+1:k+1])
			maxi=1
		else:
			z=sum(se[zero+1:]+se[0:k+1])
			maxi=2
		if s+z>z:
			print((r-maxi)*s+z)
		else:
			print(z)
	else:
		print(maxi)