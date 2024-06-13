import sys
import os
inf=".in"
os.system("clear")
print("Enter Input:")
os.system(f"cat > {inf}")
print("==========INPUT==========")
print(open(inf,"r").read())
for i in sys.argv[1:]:
	if(not os.system(f"g++ -o run {i}")):
		print(f"=========={i}==========")
		os.system(f"./run < {inf}")



