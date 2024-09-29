import os
import json
os.system("python3 build.py")
os.system("git add .")

old_dta=json.load(open("data_old.json","r"))
new_dta=json.load(open("data.json","r"))
old_dta["data"].sort(key=lambda a: a["fname"])
new_dta["data"].sort(key=lambda a: a["fname"])

old_file=[]
old_ac=[]
new_file=[]
new_ac=[]

for i in old_dta["data"]:
	old_file.append(i["fname"]);
	if(i["AC"]):
		old_ac.append(i["fname"]);

it=0
n=old_file.__len__()
it2=0
n2=old_file.__len__()

for i in new_dta["data"]:
	if(it<n and i["fname"]==old_file[it]):
		it+=1
		continue
	new_file.append(i["fname"])

for i in new_dta["data"]:
	if(it2<n2 and i["fname"]==old_ac[it2]):
		it+=1
		continue
	if(i["AC"]):
		new_ac.append(i["fname"])


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


