n=100000
print(n)
a=[1 for i in range(n)]
print(*a,sep=" ")
b=[i for i in range(1,n)]
print(*b,sep=" ")
q=30
print(q)
for i in range(10):
	if((i+1)*500>=n):
		break
	print(1,(i+1)*500)
	print(2,(i+1)*500,100)
	print(3,(i+1)*500)

