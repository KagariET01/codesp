# [`CF 1918 pB`](https://codeforces.com/contest/1918/problem/B) Minimize Inversions
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
	function<void()>solve=[](){
		INT n;
		cin>>n;
		vector<PII> vec;
		vec.resize(n);
		for(PII &i:vec){
			cin>>i.first;
		}for(PII &i:vec){
			cin>>i.second;
		}
		sort(vec.begin(),vec.end());
		for(PII &i:vec){
			cout<<i.first<<" ";
		}
		cout<<endl;
		for(PII &i:vec){
			cout<<i.second<<" ";
		}
		cout<<endl;
	};


	INT t=read(INT);
	while(t--){
		solve();
	}
	return 0;
}




```
