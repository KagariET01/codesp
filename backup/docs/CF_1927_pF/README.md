# [`CF 1927 pF`](https://codeforces.com/contest/1927/problem/F) Microcycle
## 標籤
`grapth` `bfs` 
## 題解
NOT FOUND  

## 程式碼
```cpp

#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define superINT INT
#define read(n) reader<n>()
#define PII pair<INT,INT>
#define PPIIPII pair<PII,PII>
#define pit(n) #n<<":"<<n
#define MP(n,m) make_pair(n,m)
#define endl '\n'
#define F first
#define S second
template<typename T>auto(reader)=[](){T(re);return(cin>>re,re);};


template<typename T1,typename T2>ostream&operator<<(ostream&ou,pair<T1,T2>p){
	return ou<<"{"<<p.first<<","<<p.second<<"}";
}
template<typename T1,typename T2>istream&operator>>(istream&in,pair<T1,T2>&p){
	return in>>p.first>>p.second;
}
template<typename T>ostream&operator<<(ostream&ou,vector<T>vec){
	bool o=0;
	ou<<"";
	bool f=0;
	for(T(i):vec){
		if(f)ou<<" ";
		ou<<i;
		f=1;
	}
	return(ou<<"");
}


const INT mxn=2e5+5;

INT n,m;
vector<pair<INT,PII>>edgelst;
vector<INT> tre[mxn];
vector<INT> path;
INT dsu[mxn];

INT bos(INT a){
	if(dsu[a]==a)return a;
	else return dsu[a]=bos(dsu[a]),dsu[a];
}

void mrg(INT a,INT b){
	a=bos(a),b=bos(b);
	dsu[a]=b;
}


bool dfs(INT nw,INT lst,INT ed){
	path.push_back(nw);
	if(nw==ed)return 1;
	for(INT i:tre[nw]){
		if(i==lst)continue;
		else{
			if(dfs(i,nw,ed))return 1;
		}
	}
	path.pop_back();
	return 0;
}



void solve(){
	cin>>n>>m;
	for(INT i=0;i<=n+5;i++){
		dsu[i]=i;
		tre[i].clear();
	}
	edgelst.clear();
	path.clear();
	

	for(INT i=0;i<m;i++){
		pair<INT,PII> nw;
		cin>>nw.second>>nw.first;
		edgelst.push_back(nw);
	}
	sort(edgelst.begin(),edgelst.end(),[](pair<INT,PII> a,pair<INT,PII> b){return a>b;});
	pair<INT,PII> best={-1,{-1,-1}};
	for(pair<INT,PII> i:edgelst){
		INT bosa=bos(i.S.F);
		INT bosb=bos(i.S.S);
		if(bosa==bosb){
			best=i;
		}else{
			tre[i.S.F].push_back(i.S.S);
			tre[i.S.S].push_back(i.S.F);
			mrg(i.S.F,i.S.S);
		}
	}
	cout<<best.F<<" ";
	dfs(best.S.F,-1,best.S.S);
	cout<<path.size()<<endl;
	cout<<path<<endl;
}








int main(){
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}




```
