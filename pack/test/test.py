import random
import logging


mnn=10000
mxn=10000
mna=-99
mxa=999
logging.basicConfig(level=logging.DEBUG)
def log(a):
	logging.debug(a);

n=random.randint(mnn,mxn)
m=random.randint(mnn,mxn)
print(n,m)
for i in range(n):
	for j in range(m):
		print(random.randint(mna,mxa),end=' ')
	print()
	if(not(i%100)):
		log("nw"+str(i))
log("===============")
for i in range(n):
	for j in range(m):
		print(random.randint(mna,mxa),end=' ')
	print()
	if(not(i%100)):
		log("nw"+str(i))

