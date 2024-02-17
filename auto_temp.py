supported = ["ZJ","TIOJ","CF"]

def ZJ(pid,cid,qname):
	return {
		"qname": qname,
		"fname": "ZJ_"+pid,
		"qlink": [
			{
				"OJ": "ZJ",
				"PID": pid,
				"link": "https://zerojudge.tw/ShowProblem?problemid="+pid
			}
		],
		"tag": [],
		"ans_code": "pack/ZJ_"+pid+".cpp",
		"ans_TXT": "",
		"AC": False
	}

def TIOJ(pid,cid,qname):
	return {
		"qname": qname,
		"fname": "TIOJ_"+pid,
		"qlink": [
			{
				"OJ": "TIOJ",
				"PID": pid,
				"link": "https://tioj.ck.tp.edu.tw/problems/"+pid
			}
		],
		"tag": [],
		"ans_code": "pack/TIOJ_"+pid+".cpp",
		"ans_TXT": "",
		"AC": False
	}

def CF(cid,pid,qname):
	return {
		"qname": qname,
		"fname": "CF_"+cid+"_p"+pid,
		"qlink": [
			{
				"OJ": "CF",
				"PID": cid+" p"+pid,
				"link": "https://codeforces.com/contest/"+cid+"/problem/"+pid
			}
		],
		"tag": [],
		"ans_code": "pack/CF_"+cid+"_p"+pid+".cpp",
		"ans_TXT": "",
		"AC": False
	}


def TEMP(cid,pid,qname):
	return {
		"qname": qname,
		"fname": pid,
		"qlink": [
		],
		"tag": [],
		"ans_code": "temp/"+pid+".cpp",
		"ans_TXT": "",
		"AC": False
	}