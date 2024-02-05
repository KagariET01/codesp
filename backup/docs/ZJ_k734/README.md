# [`ZJ k734`](https://zerojudge.tw/ShowProblem?problemid=k734) [`APCS 2023 06 PD`]() 開啟寶盒
## 標籤
`APCS` `grapth` `dp` 
## 題解
NOT FOUND  

## 程式碼
```cpp
// [Q] https://zerojudge.tw/ShowProblem?problemid=k734
// [Q] APCS 2023-06-pD
// [AC]

#include<bits/stdc++.h>

using namespace std;
#define INT long long int
#define FINT long double
#define endl "\n"
#define read(n) reader<n>()
#define DBG if(debug)
#define PII pair<INT,INT>
//#define max(a,b) ((a>b)?a:b)
//#define min(a,b) ((a<b)?a:b)
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define F first
#define S second
template<typename tpe>tpe reader(){tpe re;cin>>re;return re;}
bool debug=0;
bool noTLE=1;

bool one_case=1;
bool ynans=0;
bool eof=0;
string yes="YES";
string no="NO";
template<typename T1,typename T2>istream& operator>>(istream &cn,pair<T1,T2> &p){
	return cn>>p.first>>p.second;
}
template<typename T1,typename T2>ostream& operator<<(ostream &cn,pair<T1,T2> p){
	return (cn<<"{"<<p.first<<","<<p.second<<"}");
}

template<typename T1,typename T2>void operator+=(T1 &a,T2 &b){
	a=a+b;
}
template<typename T1,typename T2>void operator-=(T1 &a,T2 &b){
	a=a-b;
}

PII operator+(PII &a,PII &b){
	return make_pair(a.F+b.F,a.S+b.S);
}
PII operator-(PII &a,PII &b){
	return make_pair(a.F-b.F,a.S-b.S);
}

const INT mxn=1e5+10;
const INT mxk=10;
bool qvek[mxn+5]={};//紀錄queue有沒有該把要使
INT nk[mxn+5];//紀錄每個香紙還需要幾把key
vector<INT> open[mxn+5];//紀錄該把要使能打開那些們
vector<INT> gt[mxn+5];//紀錄門能得到那些要使
queue<INT> fkey;//初始要使
function<int(INT)> solve=[](INT casenum){
	INT n,m,k;
	if(!(cin>>n>>m>>k))return -1;
	for(INT i=0;i<=n;i++){
		nk[i]=k;
	}
	INT t;
	cin>>t;
	for(INT i=0;i<t;i++){
		INT inin=read(INT);
		fkey.push(inin);
		qvek[inin]=1;
	}
	for(INT i=0;i<n;i++){//讀入門需要的key
		for(INT j=0;j<k;j++){
			open[read(INT)].push_back(i);
		}
	}
	for(INT i=0;i<n;i++){//read which keys can get when open a door
		for(INT j=0;j<k;j++){
			gt[i].push_back(read(INT));
		}
	}
	while(!fkey.empty()){
		INT nwk=fkey.front();
		fkey.pop();
		for(INT i:open[nwk]){
			nk[i]--;
			if(!nk[i]){
				for(INT j:gt[i]){
					if(!qvek[j]){
						qvek[j]=1;
						fkey.push(j);
					}
				}
			}
		}
	}
	INT ans=0;
	for(INT i=0;i<n;i++){
		if(!nk[i])ans++;
	}
	cout<<ans<<endl;
	return 0;
};

//#ifndef EVAL
int main(int argc,char** argv){
	for(int i=0;i<argc;i++){
		string nwstr=argv[i];
		if(nwstr=="-Dev"){
			debug=1;
			noTLE=0;
		}else if(nwstr=="-TLE"){
			noTLE=0;
		}
	}
	DBG{
		cout<<"Temp by KagariET01"<<endl;
		cout<<"My Webpage: https://kagariet01.github.io/about"<<endl;
		cout<<"===DBG mod on==="<<endl;
		cout<<"Here's your CFG"<<endl;
		for(int i=0;i<argc;i++){
			string nwstr=argv[i];
			cout<<'['<<nwstr<<']'<<endl;
		}
		cout<<"===Code start==="<<endl;
	}
	if(noTLE && !debug){cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);}
	do{
		INT t=1;
		if(!one_case && !(cin>>t)){
			eof=0;
			break;
		}
		for(INT i=0;i<t;i++){
			INT re=solve(i);
			if(re==-1)return 0;
			if(ynans){
				if(re==1){
					cout<<yes<<endl;
				}else if(re==0){
					cout<<no<<endl;
				}
			}
		}
	}while(eof);
	return 0;
}
//#endif
/**/

```
