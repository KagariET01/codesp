# [`CF 1926 pG`](https://codeforces.com/contest/1926/problem/G) Vlad and Trouble at MIT
## 標籤

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
	ou<<"{";
	for(T(i):vec){
		ou<<i<<",";
	}
	return(ou<<"\b}");
}










int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		vector<INT> tree[n];
		string str;
		for(INT i=1;i<n;i++){
			INT b;
			cin>>b;
			b--;
			tree[i].push_back(b);
			tree[b].push_back(i);
		}
		INT ans=0;
		cin>>str;
		function<void(INT,INT)> dfs;
		dfs=[&](INT nw,INT pre){
			for(INT nxt:tree[nw]){
				if(nxt==pre)continue;
				dfs(nxt,nw);
			}
			INT P=0,S=0;
			for(INT nxt:tree[nw]){
				if(nxt==pre)continue;
				if(str[nxt]=='P')P++;
				else if(str[nxt]=='S')S++;
			}
			if(str[nw]=='P'){
				ans+=S;
			}else if(str[nw]=='S'){
				ans+=P;
			}else{
				ans+=min(P,S);
				if(P!=S){
					if(P<S)str[nw]='S';
					else str[nw]='P';
				}
			}
		};
		dfs(0,-1);
		cout<<ans<<endl;
	}
	return 0;
}




```
