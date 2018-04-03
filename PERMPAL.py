for _ in range(int(input())):
	s=input()
	n=len(s)
	pos=dict((k, []) for k in s)
	for i in range(n):
		pos[s[i]].append(i)
	odd=0
	oddkey=''
	for key in pos:
		if(len(pos[key])%2!=0):
			odd+=1
			oddkey=key
	if(odd>1):
		print(-1)
	else:
		i=0
		j=n-1
		final=[0]*n
		if(odd==1):
			final[n//2]=pos[oddkey][len(pos[oddkey])-1]+1
			pos[oddkey].pop()
		for key in pos:
			for k in range(0,len(pos[key]),2):
				final[i]=pos[key][k]+1
				if(k+1<len(pos[key])):
					final[j]=pos[key][k+1]+1
					j-=1
				i+=1
		print(*final)
