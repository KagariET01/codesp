# [`TIOJ 2054`](https://tioj.ck.tp.edu.tw/problems/2054) [`TOI 2018 pD`]() 最大矩形涵蓋
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


template<typename T1,typename T2>ostream&operator<<(ostream&ou,pair<T1,T2>p){
	return ou<<"{"<<p.first<<","<<p.second<<"}";
}
template<typename T1,typename T2>istream&operator>>(istream&in,pair<T1,T2>&p){
	return in>>p.first>>p.second;
}
template<typename T>auto(reader)=[](){T(re);return(cin>>re,re);};
template<typename T>ostream&operator<<(ostream&ou,vector<T>vec){
	bool o=0;
	ou<<"{";
	for(T(i):vec){
		ou<<i<<",";
	}
	return(ou<<"\b}");
}




INT xx[]={1,1,-1,-1};
INT xy[]={1,-1,1,-1};





int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,l,w;
	cin>>n>>l>>w;
	vector<PII> vec;
	for(INT i=0;i<n;i++){
		vec.push_back(read(PII));
	}
	sort(vec.begin(),vec.end());
	INT ans=0;
	INT xl=0;
	for(INT i=0;i<n;i++){
		while(xl<n && vec[xl].F-vec[i].F<=w)xl++;
		vector<INT> yy;
		for(INT j=i;j<xl;j++){
			yy.push_back(vec[j].S);
		}
		sort(yy.begin(),yy.end());
		INT yl=0;
		for(INT j=0;j<yy.size();j++){
			while(yl<yy.size()&&yy[yl]-yy[j]<=l)yl++;
			ans=max(ans,yl-j);
		}
	}
	cout<<ans<<endl;
	return 0;
}




```
