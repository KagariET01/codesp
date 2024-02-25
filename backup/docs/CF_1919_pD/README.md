# [`CF 1919 pD`](https://codeforces.com/contest/1919/problem/D) 01 Tree
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
		INT prev[n+2]={};
		INT nxt[n+2]={};
		INT a[n+2]={};
		bool ins[n+2]={};
		a[0]=a[n+1]=-100;
		INT mn=1e9+7;
		for(INT i=1;i<=n;i++){
			cin>>a[i];
			mn=min(mn,a[i]);
			prev[i]=i-1;
			nxt[i]=i+1;
		}
		auto isok=[&](INT i)->bool{
			if(i<=0 || n<i)return 0;
			return a[i]==a[prev[i]]+1 || a[i]==a[nxt[i]]+1;
		};
		priority_queue<PII> pq;
		for(INT i=1;i<=n;i++){
			if(isok(i)){
				ins[i]=1;
				pq.push(PII(a[i],i));
			}
		}
		while(!pq.empty()){
			INT nw=pq.top().second;
			pq.pop();
			prev[nxt[nw]]=prev[nw];
			nxt[prev[nw]]=nxt[nw];
			if(!ins[prev[nw]] && isok(prev[nw])){
				ins[prev[nw]]=1;
				pq.push(PII(a[prev[nw]],prev[nw]));
			}
			if(!ins[nxt[nw]] && isok(nxt[nw])){
				ins[nxt[nw]]=1;
				pq.push(PII(a[nxt[nw]],nxt[nw]));
			}
		}
		INT cnt=0;
		for(INT i=1;i<=n;i++){
			cnt+=!ins[i];
		}
		if(cnt==1 && mn==0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}




```
