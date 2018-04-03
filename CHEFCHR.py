for _ in range(int(input())):
	x=input()
	count = 0
	for i in range(len(x)-3):
		d={'c':0,'h':0,'e':0,'f':0}
		for j in range(4):
			if(x[i+j] in d):
				d[x[i+j]]+=1
		flag=1
		for key in d:
			if(d[key]!=1):
				flag=0
		if(flag==1):
			count+=1
	if(count==0):
		print("normal")
	else:
		print("lovely",count)
