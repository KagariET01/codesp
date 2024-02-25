# [`TIOJ 2194`](https://tioj.ck.tp.edu.tw/problems/2194) [`TOI 2021 pB`]( ) 掃地機器人
## 標籤

## 題解
***p.s. 此為30/100的解，並非滿分解***

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
	INT n,m;
	cin>>n>>m;
	INT t[n+1]={};
	for(INT i=2;i<=n;i++){
		cin>>t[i];
	}
	INT s[n+1]={};
	for(INT i=1;i<=n;i++){cin>>s[i];}
	INT d[n+1]={};
	for(INT i=1;i<=n;i++){cin>>d[i];};


	if(m>1000 || n>1000 || n*m>=1e8)return 1;
	
	function<INT(INT,INT)> solve=[&](INT lim,INT mm){
		priority_queue<PII> pq;
		for(INT i=1;i<=mm;i++){
			pq.push(PII(s[i],-d[i]));
		}
		INT re=0;
		while(!pq.empty()){
			if(lim<=0 || pq.empty())return re;
			lim--;
			PII nw=pq.top();
			pq.pop();
			re+=nw.first;
			nw.first+=nw.second;
			if(nw.first>0){
				pq.push(nw);
			}
		}
		return re;
	};
	INT lim=m;
	INT ans=0;
	for(INT i=1;i<=n;i++){
		lim-=t[i];
		INT nw=solve(lim,i);
		ans=max(ans,solve(lim,i));
	}
	cout<<ans<<endl;



	return 0;
}




```
