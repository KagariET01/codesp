import os
import json
os.system("python3 build.py")
os.system("git add .")

old_dta=json.load(open("data_old.json","r"))
new_dta=json.load(open("data.json","r"))
old_dta["data"].sort(key=lambda a: a["fname"])
new_dta["data"].sort(key=lambda a: a["fname"])


new_file=[]
new_ac=[]

it=0
n=new_dta["data"].__len__()
def doit(i=None):
	global it,old_dta,new_dta
	while(it<n):
		if(i!=None and i["fname"]==new_dta["data"][it]["fname"]):
			if(i["AC"]==new_dta["data"][it]["AC"]):
				it+=1
				break
			else:
				new_ac.append(new_dta["data"][it]["fname"])
		elif(new_dta["data"][it]["AC"]):
			new_ac.append(new_dta["data"][it]["fname"])
		else:
			new_file.append(new_dta["data"][it]["fname"])
		it+=1


for i in old_dta["data"]:
	doit(i)
doit(None)


print("you add some new file")
print(*new_file,sep="\n")
print("=====================")
print("you AC some question!")
print(*new_ac,sep="\n")
print("=====================")
print("Let's all. Good job, boy!")

commit_msg="AC: "
for i in new_ac:
	commit_msg+=i
	commit_msg+=" "

commit_msg=commit_msg.replace("\"","\\\"")

os.system("git commit -m \""+commit_msg+"\"")
os.system("git push")
os.system("rm data_old.json")
os.system("cp data.json data_old.json")


