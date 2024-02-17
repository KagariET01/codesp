import json
import json

lst=[]
fname="{0}_{2}"
build={
	"CF":lambda cid,pid:'{"qname": "","fname": "CF_'+cid+'_p'+pid+'","qlink": [{"OJ": "CF","PID": "'+cid+' p'+pid+'","link": "https://codeforces.com/contest/'+cid+'/problem/'+pid+'"}],"tag": [],"ans_code": "pack/CF_'+cid+'_p'+pid+'.cpp","ans_TXT": "","AC": false}',
	"TIOJ":lambda cid,pid:'{"qname": "","fname": "TIOJ_'+pid+'","qlink": [{"OJ": "TIOJ","PID": "'+pid+'","link": "https://tioj.ck.tp.edu.tw/problems/'+pid+'"}],"tag": [],"ans_code": "pack/TIOJ_'+pid+'.cpp","ans_TXT": "","AC": false}',
}


try:
	while True:
		lst.append(input().split())
except:
	pass

orig=json.loads(open("data.json","r").read())["data"]
print("============================")
for i in lst:
	nw=fname.format(i[0],i[1],i[2])
	if(nw not in (orig[j]["fname"] for j in range(len(orig)))):
		pt=build[i[0]](i[1],i[2])
		print(pt)

