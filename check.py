t=input()
inp=open(f"ios/{t}.in","r").read()
inpl=inp.split('\n')
inpl[1]=inpl[1].split(' ')
inpl[2]=inpl[2].split(' ')
print("====input============")
print(inp)


ou=open(f"ios/{t}.out","r").read()
ou=ou.split(" ")
print("====output===========")
print(ou)

ans=open(f"ios/{t}.ans","r").read()
ans=ans.split(" ")
print("====ans==============")
print(ans)



if(ou[0]!=ans[0]):
	print("Wrong Ans")
	print(f"Ans is {ans[0]}, found {ou[0]}.")

# check user output


a=0
b=0
for i in range(int(inpl[0])):
	if(int(ou[1])<=i+1<=int(ou[2])):
		b+=int(inpl[1][i])
		a+=int(inpl[2][i])
	else:
		a+=int(inpl[1][i])
		b+=int(inpl[2][i])

print(a,b)

if(a!=int(ou[0]) and b!=int(ou[0])):
	print("Wrong Ans")
	print(f"loop {ou[1]} to loop {ou[2]} can not get the ans")
	exit()

print("AC")


