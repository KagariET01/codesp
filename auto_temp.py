supported = ["ZJ","TIOJ","CF","NEOJ","TEMP","AT","CSES","LUOGU"]

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

def LUOGU(cid,pid,qname):
	return {
		"qname": qname,
		"fname": "LUOGU_"+pid,
		"qlink": [
			{
				"OJ": "LUOGU",
				"PID": pid,
				"link": "https://www.luogu.com.cn/problem/P"+pid
			}
		],
		"tag": [],
		"ans_code": "pack/LUOGU_"+pid+".cpp",
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

def CSES(cid,pid,qname):
	return {
		"qname": qname,
		"fname": "CSES_"+pid,
		"qlink": [
			{
				"OJ": "CSES",
				"PID": pid,
				"link": "https://cses.fi/problemset/task/"+pid
			}
		],
		"tag": [],
		"ans_code": "pack/CSES_"+pid+".cpp",
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

def AT(cid,pid,qname):
	return{
		"qname":qname,
		"fname":"AT_"+cid+"_p"+pid,
		"qlink":[
			{
				"OJ":"AT",
				"PID":cid+" p"+pid,
				"link":"https://atcoder.jp/contests/"+cid+"/tasks/"+cid+"_"+pid
			}
		],
		"tag":[],
		"ans_code":"pack/AT_"+cid+"_p"+pid+".cpp",
		"ans_TXT":"",
		"AC":False
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
