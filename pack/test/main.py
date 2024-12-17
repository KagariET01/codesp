n=list(map(int,input().split()))[0]
mp=[input() for _ in range(n)]
for i in mp:
	for j in i:
		print(j,end=",")
	print()

