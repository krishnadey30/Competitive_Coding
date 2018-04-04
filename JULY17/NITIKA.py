
n=int(input())
for i in range(0,n):
	name=input()
	name=name.split()
	if(len(name)==3):
		x=name[0][0].upper()+". "+name[1][0].upper()+". "+name[2].title()
	elif(len(name)==2):
		x=name[0][0].upper()+". "+name[1].title()
	else:
		x=name[0].title()
	print(x)