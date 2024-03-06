supported = ["ZJ","TIOJ","CF","NEOJ","TEMP"]

def ZJ(cid,pid,qname):
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

def TIOJ(cid,pid,qname):
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

def NEOJ(cid,pid,qname):
	return {
		"qname": qname,
		"fname": "NEOJ_"+pid,
		"qlink": [
			{
				"OJ": "NEOJ",
				"PID": pid,
				"link": "https://neoj.sprout.tw/problem/"+pid+"/"
			}
		],
		"tag": [],
		"ans_code": "pack/NEOJ_"+pid+".cpp",
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
