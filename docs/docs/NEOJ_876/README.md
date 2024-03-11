# [`NEOJ 876`](https://neoj.sprout.tw/problem/876/) 2024算法班入芽考_pE 芽芽與學習歷程
## 標籤

## 題解
NOT FOUND  

## 程式碼
```cpp
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define read(n) reader<n>()
#define P(n,m) pair<n,m>
#define PII P(INT,INT)
template<typename T>T reader(){
	T re;
	cin>>re;
	return re;
}
int main(){
	INT n;
	cin>>n;
	PII lst[n];
	for(INT i=0;i<n;i++){
		cin>>lst[i].first>>lst[i].second;
	}
	PII lu;
	lu.first=lst[1].first-lst[0].first;
	lu.second=lst[1].second-lst[0].second;
	INT lugcd=__gcd(lu.first,lu.second);
	lu.first/=lugcd;
	lu.second/=lugcd;
	for(INT i=1;i<n;i++){
		PII nw;
		nw.first=lst[i].first-lst[i-1].first;
		nw.second=lst[i].second-lst[i-1].second;
		INT nwgcd=__gcd(nw.first,nw.second);
		nw.first/=nwgcd;
		nw.second/=nwgcd;
		if(nw!=lu){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}


```
