# coding: utf-8
import json
import os

web_root="/codesp/"

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
def getN(dta,OJ=[]):#  製造題目列表（單一題目）
	re=""
	if(len(OJ)==0):
		for i in dta["qlink"]:
			re+="`"+i["OJ"]+" "+i["PID"]+"` "
	else:
		for i in dta["qlink"]:
			if(i["OJ"] in OJ):
				re+="`"+i["OJ"]+" "+i["PID"]+"` "
	re+=dta["qname"]
	re="["+re+"]("+web_root+"docs/"+dta["fname"]+")"
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
	root_file.write("["+i+"]("+web_root+i+")  \n")

for id in range(len(dta["data"])):#  建立題目資料夾、每個題目的README.md
	i=dta["data"][id]
	FN=getN(i)
	os.system("mkdir \"docs/docs/"+i["fname"]+"\"")
	print("writing",("\"docs/docs/"+i["fname"]+"/README.md"+"\""))
	file=open(("docs/docs/"+i["fname"]+"/README.md"),"w+")
	file.write("# ")
	i["qlink"].sort(key=lambda x:x["OJ"])
	for j in range(len(i["qlink"])):
		file.write("[`"+i["qlink"][j]["OJ"]+" "+i["qlink"][j]["PID"]+"`]("+i["qlink"][j]["link"]+") ")
		if(j and i["qlink"][j]["OJ"]==i["qlink"][j-1]["OJ"]):
			continue
		book[i["qlink"][j]["OJ"]].append([i["qlink"][j]["PID"],getN(i,i["qlink"][j]["OJ"])])
	file.write(i["qname"]+"\n")
	file.write("## 標籤\n")
	for j in i["tag"]:
		file.write("`"+j+"` ")
	file.write("\n## 題解\n")
	try:
		file.write(open(i["ans_TXT"],"r").read())
	except:
		file.write("NOT FOUND  \n")
	file.write("\n## 程式碼\n")
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
	file.write("[back](..)  \n\n")
	for j in book[OJlist[i]]:
		file.write(j[1]+"  \n")
	file.close()


print("DONE!")








