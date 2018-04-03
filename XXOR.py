#use py py 

n,q=list(map(int,input().split()))
x=list(map(int,input().split()))
y=[]
for i in x:
	a=[0]*31
	temp=str("{0:b}".format(i))
	length=len(temp)
	for j in range(length):
		a[31-length+j]=int(temp[j])
	y.append(a)
 
z=[]
for i in range(31):
	a=[]
	a.append(y[0][i])
	for j in range(1,n):
		a.append(a[j-1]+y[j][i])
	z.append(a)
for i in range(q):
	a,b=list(map(int,input().split()))
	temp=[]
	for j in range(31):
		if(a-2>=0):
			var=z[j][b-1]-z[j][a-2]
		else:
			var=z[j][b-1]
		if((b-a+1)-var>var):
			temp.append('1')
		else:
			temp.append('0')
	print(int("".join(temp),2))