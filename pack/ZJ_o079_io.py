import random

n=int(10)
k=random.randint(1e2,5e2)
odecmn=5
lst=[]
odec=0
for i in range(n):
	pb=random.randint(10,100)
	if(odec>=odecmn and pb%2==1 or odec<=-odecmn and pb%2==0):
		pb+=1
	lst+=[pb]
	if(pb%2==1):
		odec+=1
	else:
		odec-=1
print(n,k)
print(*lst)
