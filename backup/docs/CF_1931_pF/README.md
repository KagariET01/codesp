# [`CF 1931 pF`](https://codeforces.com/contest/1931/problem/F) Chat Screenshots
## 標籤
`grapth` `topologicalSort` 
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
		INT n,k;
		cin>>n>>k;
		vector<INT> tree[n];
		INT bk[n]={};
		for(INT i=0;i<k;i++){
			INT lst[n];
			for(INT j=0;j<n;j++){
				cin>>lst[j];
				lst[j]--;
			}
			for(INT j=2;j<n;j++){
				tree[lst[j-1]].push_back(lst[j]);
				bk[lst[j]]++;
			}
		}
		queue<INT> que;
		for(INT i=0;i<n;i++){
			if(!bk[i])que.push(i);
		}
		INT cnt=0;
		while(!que.empty()){
			INT nw=que.front();
			que.pop();
			cnt++;
			for(INT i:tree[nw]){
				bk[i]--;
				if(!bk[i])que.push(i);
			}
		}
		if(cnt>=n){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}




```
