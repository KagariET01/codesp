# [`CF 1927 pD`](https://codeforces.com/contest/1927/problem/D) Find the Different Ones!
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
//	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		INT a[n+1]={};
		for(INT i=1;i<=n;i++){
			cin>>a[i];
		}
		INT r[n+1];
		for(INT i=0;i<=n;i++){
			r[i]=n+5;
		}
		for(INT i=n-1;i>=1;i--){
			if(a[i]==a[i+1]){
				r[i]=r[i+1];
			}else{
				r[i]=i+1;
			}
		}
		cout<<endl;
		INT q;
		cin>>q;
		while(q--){
			INT l,rr;
			cin>>l>>rr;
			if(r[l]>rr){
				cout<<"-1 -1"<<endl;
			}else{
				cout<<l<<" "<<r[l]<<endl;
			}
		}
		cout<<endl;

	}
	return 0;
}




```
