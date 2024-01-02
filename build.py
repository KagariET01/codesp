# coding: utf-8
import json
import os

os.system("rm -rf backup")
os.system("mkdir backup")
os.system("mv docs/* backup/")

dta=json.load(open("data.json","r"))
OJlist=json.load(open("OJlist.json","r"))

def fix():#  將沒解出來的題目刪除
	poplist=[]
	for i in range(len(dta["data"])):
		if(not dta["data"][i]["AC"]):
			poplist.append(i)
	poplist.reverse()
	for i in poplist:
		dta["data"].pop(i)
def getN(dta):
	re=""
	for i in dta["qlink"]:
		re+="`"+i["OJ"]+" "+i["PID"]+"` "
	re+=dta["qname"]
	re="["+re+"](/docs/"+dta["fname"]+")"
	return re

fix()
print("data:",dta["data"])
os.system("mkdir docs/docs")
book={}

root_file=open("docs/README.md","w+")
root_file.write("# ET01 題解系統\n")
docs_file=open("docs/docs/README.md","w+")
docs_file.write("# 所有題解列表\n")
docs_file.write("資料未排序，請善用Ctrl+F搜尋  \n")
for i in OJlist:
	book[i]=[]
	root_file.write("["+i+"](/"+i+")  \n")

for id in range(len(dta["data"])):#  建立題目資料夾、每個題目的README.md
	i=dta["data"][id]
	FN=getN(i)
	os.system("mkdir \"docs/docs/"+i["fname"]+"\"")
	print("writing",("\"docs/docs/"+i["fname"]+"/README.md"+"\""))
	file=open(("docs/docs/"+i["fname"]+"/README.md"),"w+")
	file.write("# ")
	for j in i["qlink"]:
		file.write("[`"+j["OJ"]+" "+j["PID"]+"`]("+j["link"]+") ")
		book[j["OJ"]].append([j["PID"],FN])
	file.write(i["qname"]+"\n")
	file.write("## 標籤\n")
	for j in i["tag"]:
		file.write("`"+j+"` ")
	file.write("## 程式碼\n")
	file.write("```cpp\n")
	file.write(open(i["ans_code"],"r").read())
	file.write("\n```\n")
	file.close()
	docs_file.write(FN+"  \n")

for i in range(len(OJlist)):
	book[OJlist[i]].sort()
	os.system("mkdir docs/"+OJlist[i])
	file=open("docs/"+OJlist[i]+"/README.md","w+")
	file.write("# "+OJlist[i]+"\n")
	for j in book[OJlist[i]]:
		file.write(j[1]+"  \n")
	file.close()











