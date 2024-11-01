import random

n=1000
a=[random.randint(1,200) for i in range(n)]
b=[random.randint(1,200) for i in range(n)]

print(n)
print(*a,sep=" ")
print(*b,sep=" ")


