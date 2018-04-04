from itertools import permutations
A=input().split()
B=input().split()
Q=input()
for i in range(int(A[2])):
	if(Q[i]=='!'):
		B.insert(0,B[-1])
		B.pop(-1)
	else:
		
		