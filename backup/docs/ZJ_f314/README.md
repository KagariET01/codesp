# [`ZJ ZJ f314`](https://zerojudge.tw/ShowProblem?problemid=f314) [`APCS 2020 10 pC`]() 勇者修煉
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
	INT dp[m]={};
	INT mp[n+1][m];
	
	for(INT i=1;i<=n;i++){
		for(INT j=0;j<m;j++){
			cin>>mp[i][j];
		}
	}
	for(INT i=1;i<=n;i++){
		INT l[m],r[m];
		for(INT j=0;j<m;j++){
			l[j]=r[j]=dp[j]+mp[i][j];
		}
		for(INT j=1;j<m;j++){
			l[j]=max(l[j],l[j-1]+mp[i][j]);
		}
		for(INT j=m-2;j>=0;j--){
			r[j]=max(r[j],r[j+1]+mp[i][j]);
		}
		for(INT j=0;j<m;j++){
			dp[j]=max(l[j],r[j]);
		}
	}
	INT ans=dp[0];
	for(INT i=0;i<m;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}




```
