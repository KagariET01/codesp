# coding: utf-8

import json
import os
import copy
from auto_temp import *

dta=json.load(open("data.json","r"))
dta["data"].sort(key=lambda a: a["fname"])
basic_data={"qname":"","fname":"","qlink":[],"tag":[],"ans_code":"","ans_TXT":"","AC":False}

show_per_page=100000000

def IN(txt):
	while(1):
		re=input(txt)
		if(re=="s"):
			print("[sys]儲存中...")
			open("data.json", "w").write(json.dumps(dta, indent=2, ensure_ascii=False))
			print("[sys]儲存完成")
		elif(len(re)>0 and re[0]=="!"):
			os.system(re[1:])
		elif(re==""):
			continue
		else:
			return re

def print_q(data):
	os.system("clear")
	print("建檔名稱："+data["fname"])
	print("題目名稱："+data["qname"])
	print("題目連結：")
	for j in range(len(data["qlink"])):
		print("\t"+str(j)+":"+data["qlink"][j]["OJ"]+" "+data["qlink"][j]["PID"],data["qlink"][j]["link"])
	print("標籤：",data["tag"])
	print("題解路徑(cpp)：",data["ans_code"])
	print("題解路徑(md)：",data["ans_TXT"])
	print("已解：",data["AC"])
	print()


def edit_ans():
	i=0
	while(1):
		os.system("clear")
		n=len(dta["data"])
		print("總大小：",n)
		cnt=0
		while(cnt<show_per_page and i+cnt<n):
			id=i+cnt
			fn=dta["data"][id]["fname"]
			if(dta["data"][id]["AC"]):
				print("[AC]",end="")
			else:
				print("[  ]",end="")
			print(f"{id}: { {dta['data'][id]['fname']} }",end="\t")
			for j in dta["data"][id]["qlink"]:
				print("["+j["OJ"]+" "+j["PID"]+"]",end=" ")
			print("\t"+dta["data"][id]["qname"])
			cnt+=1
		print()
		print("輸入編號")
		print("輸入-1結束")
		print("輸入-2向右移動")
		print("輸入-3向左移動")
		print("輸入-4新增")
		print("輸入-5智能新增")
		print("輸入-6找檔案")
		nwid=int(IN(">"))
		if(nwid==-1):
			break
		elif(nwid==-2):
			i+=show_per_page
			if(i>=n):
				i-=show_per_page
		elif(nwid==-3):
			i-=show_per_page
			if(i<0):
				i+=show_per_page
		elif(nwid==-4):
			dta["data"].append(copy.deepcopy(basic_data))
		elif(nwid==-5):
			OJ=input("輸入OJ ex CF>")
			CID=input("輸入CID ex 1234>")
			PID=input("輸入PID ex A>")
			Q=input("輸入題目名稱>")
			if(OJ not in supported):
				print("不支援的OJ")
				continue
			else:
				dta["data"].append(eval(OJ)(CID,PID,Q))
		else:
			if(nwid==-6):
				fqname=IN("輸入建檔名稱>")
				for j in range(len(dta["data"])):
					if(dta["data"][j]["fname"]==fqname):
						nwid=j
						break
			if(not(0<=nwid<n)):
				continue
			while(1):
				print_q(dta["data"][nwid])
				print("輸入動作")
				print("輸入-1結束")
				print("輸入-2向右移動")
				print("輸入-3向左移動")
				print("輸入-4編輯")
				print("輸入-5刪除")
				print("輸入-6打開題解(vim code)")
				print("輸入-7輸出題解(cat < code)")
				print("輸入-8打開題解(md)")
				print("輸入-8打開題解(cat > code)")
				op2=int(IN(">"))
				if(op2==-1):#  結束
					break
				elif(op2==-2):#  向右移動
					nwid+=1
					nwid=min(n-1,nwid)
				elif(op2==-3):#  向左移動
					nwid-=1
					nwid=max(0,nwid)
				elif(op2==-4):#  編輯
					while(1):
						os.system("clear")
						print_q(dta["data"][nwid])
						print("輸入動作")
						print("0. 建檔名稱")
						print("1. 題目名稱")
						print("2. 題目連結")
						print("3. 標籤")
						print("4. 題解路徑(code)")
						print("5. 題解路徑(md)")
						print("6. 已解標籤")
						print("-1 結束")
						op3=int(IN(">"))
						if(op3==0):#  題目名稱
							print("輸入建檔名稱，空格請改用底線")
							dta["data"][nwid]["fname"]=IN(">")
						if(op3==1):#  題目名稱
							print("輸入題目名稱")
							dta["data"][nwid]["qname"]=IN(">")
						elif(op3==2):#  題目連結
							print("輸入動作")
							print("1. 新增")
							print("2. 編輯")
							print("3. 刪除")
							op4=int(IN(">"))
							if(op4==1):#  新增
								print("輸入OJ")
								OJ=IN(">")
								print("輸入PID")
								PID=IN(">")
								print("輸入連結")
								link=IN(">")
								print("輸入編號")
								id=int(IN(">"))
								print("你即將新增：")
								print({"OJ":OJ,"PID":PID,"link":link})
								print("確定？")
								print("1. 是")
								print("2. 否")
								op5=int(IN(">"))
								if(op5==1):
									if(id<len(dta["data"][nwid]["qlink"])):
										dta["data"][nwid]["qlink"].insert(id,{"OJ":OJ,"PID":PID,"link":link})
									else:
										dta["data"][nwid]["qlink"].append({"OJ":OJ,"PID":PID,"link":link})
							elif(op4==2):#  編輯
								print("輸入編號")
								id=int(IN(">"))
								print("輸入OJ")
								OJ=IN(">")
								print("輸入PID")
								PID=IN(">")
								print("輸入連結")
								link=IN(">")
								print("你即將編輯：")
								print(dta["data"][nwid]["qlink"][id])
								print("成")
								print({"OJ":OJ,"PID":PID,"link":link})
								print("確定？")
								print("1. 是")
								print("2. 否")
								op5=int(IN(">"))
								if(op5==1):
									dta["data"][nwid]["qlink"][id]={"OJ":OJ,"PID":PID,"link":link}
							elif(op4==3):#  刪除
								print("輸入編號")
								id=int(IN(">"))
								print("你即將刪除：")
								print(dta["data"][nwid]["qlink"][id])
								print("確定？")
								print("1. 是")
								print("2. 否")
								op5=int(IN(">"))
								if(op5==1):
									dta["data"][nwid]["qlink"].pop(id)
						elif(op3==3):#  標籤
							print("輸入動作")
							print("1. 新增")
							print("3. 刪除")
							op4=int(IN(">"))
							if(op4==1):#  新增
								print("標籤列表：")
								for j in range(len(dta["tag"])):
									print("\t"+str(j)+". "+dta["tag"][j])
								print("輸入標籤編號（-1取消）")
								tag=int(IN(">"))
								if(tag==-1):
									continue
								print("你即將新增：")
								print(dta["tag"][tag])
								print("確定？")
								print("1. 是")
								print("2. 否")
								op5=int(IN(">"))
								if(op5==1):
									dta["data"][nwid]["tag"].append(dta["tag"][tag])
							elif(op4==3):#  刪除
								print("輸入編號")
								id=int(IN(">"))
								print("你即將刪除：")
								print(dta["data"][nwid]["tag"][id])
								print("確定？")
								print("1. 是")
								print("2. 否")
								op5=int(IN(">"))
								if(op5==1):
									dta["data"][nwid]["tag"].pop(id)
						elif(op3==4):#  題解路徑(code)
							print("輸入題解路徑(code)")
							dta["data"][nwid]["ans_code"]=IN(">")
						elif(op3==5):#  題解路徑(md)
							print("輸入題解路徑(md)")
							dta["data"][nwid]["ans_TXT"]=IN(">")
						elif(op3==6):#  已解標籤
							dta["data"][nwid]["AC"]=not dta["data"][nwid]["AC"]
						elif(op3==-1):#  結束
							break
				elif(op2==-5):#  刪除
					print("你即將刪除：")
					print(dta["data"][nwid]["qname"])
					print("確定？")
					print("1. 是")
					print("2. 否")
					op5=int(IN(">"))
					if(op5==1):
						dta["data"].pop(nwid)
						break
				elif(op2==-6):#  打開題解(cpp)
					os.system("clear")
					os.system("vim "+dta["data"][nwid]["ans_code"])
				elif(op2==-7):
					os.system("clear")
					os.system("cat < "+dta["data"][nwid]["ans_code"])
					print()
					IN("")
				elif(op2==-8):#  打開題解(md)
					os.system("clear")
					os.system("vim "+dta["data"][nwid]["ans_TXT"])
				elif(op2==-9):#  打開題解(cpp)
					os.system("clear")
					os.system("cat > "+dta["data"][nwid]["ans_code"])


def edit_tag():
	i=0
	while(1):
		os.system("clear")
		n=len(dta["tag"])
		print("總大小：",n)
		cnt=0
		while(cnt<show_per_page and i+cnt<n):
			id=i+cnt
			print(str(id)+", "+dta["tag"][id])
			cnt+=1
		print()
		print("輸入編號")
		print("輸入-1結束")
		print("輸入-2向右移動")
		print("輸入-3向左移動")
		print("輸入-4新增")
		nwid=int(IN(">"))
		if(nwid==-1):
			return
		elif(nwid==-2):
			i+=show_per_page
			if(i>=n):
				i-=show_per_page
		elif(nwid==-3):
			i-=show_per_page
			if(i<0):
				i+=show_per_page
		elif(nwid==-4):
			dta["tag"].append(IN("輸入標籤名稱："))
		else:
			while(1):
				os.system("clear")
				print("標籤名稱："+dta["tag"][nwid])
				print()
				print("輸入動作")
				print("1. 編輯")
				print("2. 刪除")
				print("-1 結束")
				op2=int(IN(">"))
				if(op2==1):#  編輯
					print("輸入標籤名稱")
					newtag=IN(">")
					for j in range(len(dta["data"])):
						for k in range(len(dta["data"][j]["tag"])):
							if(dta["data"][j]["tag"][k]==dta["tag"][nwid]):
								dta["data"][j]["tag"][k]=newtag
					dta["tag"][nwid]=newtag
				elif(op2==2):#  刪除
					print("你即將刪除：")
					print(dta["tag"][nwid])
					print("確定？")
					print("1. 是")
					print("2. 否")
					op5=int(IN(">"))
					if(op5==1):
						dta["tag"].pop(nwid)
				elif(op2==-1):#  結束
					break
while True:
	try:
		print("輸入動作")
		print("1. 題解")
		print("2. 標籤")
		op=int(IN(">"))
		if(op==1):
			edit_ans()
		elif(op==2):
			edit_tag()
		else:
			print("無效動作")
	except KeyboardInterrupt:
		print("程式中止")
		op=input("是否儲存？(y/n)")
		if(op=="y"):
			print("[sys]儲存中...")
			open("data.json", "w").write(json.dumps(dta, indent=2, ensure_ascii=False))
			print("[sys]儲存完成")
		break
	except:
		print("程式意外中止")


