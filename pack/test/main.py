n=int(input())
inf=open("read.txt","r").read()#讀取等案
inf=inf.split("\n")#將文字以換行分割成表格
outp=inf[0:n]
outp=[i.title()for i in outp]
outf=open("write.txt","w")
outs=""

for i in outp:
	outs+=i
	outs+="\n"

print(outs,end="")
outf.write(outs)

