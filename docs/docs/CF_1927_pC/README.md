# [`CF 1927_pC`](https://codeforces.com/contest/1927/problem/C) Choose the Different Ones!
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
	INT t;
	cin>>t;
	while(t--){
		INT n,m,k;
		cin>>n>>m>>k;
		bool a[k+1]={},b[k+1]={},tt[k+1]={};
		INT as=0,bs=0;
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			if(inin>k || a[inin])continue;
			a[inin]=1;
			as++;
		}
		for(INT i=0;i<m;i++){
			INT inin=read(INT);
			if(inin>k||b[inin])continue;
			b[inin]=1;
			bs++;
		}
		
		bool ha=0;
		if(as<k/2 || bs<k/2){
			cout<<"no"<<endl;
			continue;
		}
		for(INT i=1;i<=k;i++){
			if(a[i] || b[i])continue;
			else{
				ha=1;
				cout<<"no"<<endl;
				break;
			}
		}
		if(ha)continue;
		cout<<"yes"<<endl;
	}

	return 0;
}




```
