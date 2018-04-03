def get_all_substrings(input_string):
  length = len(input_string)
  return [input_string[i:j+1] for i in xrange(length) for j in xrange(i,length)]

s=raw_input()
x=get_all_substrings(s);
x.sort()
x="".join(x)
g=0
for _ in range(int(raw_input())):
	p,m=list(map(int,raw_input().split()))
	a=(p*g)%m
	print x[a]
	g+=ord(x[a])

