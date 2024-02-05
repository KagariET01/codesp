# [`TIOJ 2193`](https://tioj.ck.tp.edu.tw/problems/2193) 原始人排序
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
	INT n;
	cin>>n;
	vector<PII>vec;
	vec.reserve(n);
	for(INT(i)=0;i<n;i++)vec.push_back({read(INT),i});
	sort(vec.begin(),vec.end(),[](PII(a),PII(b)){
		INT(x)=0,y=0;
		for(INT(i)=0;i<32;i++){
			x+=(a.first>>i)&1;
			y+=(b.first>>i)&1;
		}
		if(x==y)return(a.second<b.second);
		return(x<y);
	});
	for(PII(i):vec)cout<<i.first<<" ";
	cout<<endl;
	return 0;
}




```
