import os

t=int(input("輸入測資數量> "))

# build

print("Building your code")
if(os.system("g++ -o run pack/test/main.cpp")):
	print("Compiler Error")
	exit()

print("Building ans generater")
if os.system("g++ -o ans pack/test/test.cpp"):
	print("Ans Compiler Error")
	exit()

print("Building ans checker")

print("Building task generater")



for i in range(t):
	print("task:",i,end=" ")
	nw=str(t)
	os.system(f"python3 task.py > ios/{nw}.in")
	if os.system(f"./run < ios/{nw}.in > ios/{nw}.out 2> ios/{nw}.log"):
		print("Runtime Error")
		exit()
	if os.system(f"./ans < ios/{nw}.in > ios/{nw}.ans 2> ios/{nw}.anslog"):
		print("Ans Runtime Error")
		exit()
	if os.system(f"echo {nw} | python3 check.py > ios/{nw}.res"):
		print("Checker Runtime Error")
		exit()
	res=open(f"ios/{nw}.res","r").read()
	if("AC" not in res):
		print("Wrong Ans")
		print(res)
		exit()
	else:
		print("AC")


