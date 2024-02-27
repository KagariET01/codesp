# [`CF 1921 pD`](https://codeforces.com/contest/1921/problem/D) Very Different Array
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
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return(ou<<"}");
}
template<typename T1,typename T2>ostream&operator<<(ostream&ou,map<T1,T2>mp){
	bool o=0;
	ou<<"{";
	for(pair<T1,T2>i:mp){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return(ou<<"}");
}










int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n,m;
		cin>>n>>m;
		INT a[n],b[m];
		for(INT&i:a)cin>>i;
		for(INT&i:b)cin>>i;
		sort(a,a+n);
		sort(b,b+m);
		INT al=0,ar=n;
		INT bl=0,br=m;
		INT ans=0;
		while(al<ar){
			INT albr=abs(b[br-1]-a[al]);
			INT arbl=abs(a[ar-1]-b[bl]);
			if(albr>arbl){
				ans+=albr;
				br--,al++;
			}else{
				ans+=arbl;
				ar--,bl++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}




```
