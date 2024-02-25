# [`CF 1926 pB`](https://codeforces.com/contest/1926/problem/B) Vlad and Shapes
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
		string mp[n];
		for(INT i=0;i<n;i++){
			cin>>mp[i];
		}
		bool nans=1;
		for(INT i=0;i<n && nans;i++){
			for(INT j=0;j<n&&nans;j++){
				if(mp[i][j]=='1'){
					if(mp[i][j+1]=='1' && mp[i+1][j]=='1'){
						cout<<"SQUARE"<<endl;
						nans=0;
					}else{
						cout<<"TRIANGLE"<<endl;
						nans=0;
					}
					break;
				}
			}
		}
	}
	return 0;
}




```
