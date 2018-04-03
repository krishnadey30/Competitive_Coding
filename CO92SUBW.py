from math import *
for _ in range(int(input())):
	x=int(input())
	y=floor((sqrt(1+(8*x))-1)/2)
	n=y*(y+1)/2
	distnace=y+(x-n)
	n1=(y+1)*(y+2)/2
	dis2=(y+1)+(n1-x)
	ans=min(dis2,distnace)
	print(int(ans))