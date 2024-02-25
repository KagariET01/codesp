# [`CF 1918 pC`](https://codeforces.com/contest/1918/problem/C) XOR-distance
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




const INT mxb=63;





int main(){
//	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT a,b,rr;
		cin>>a>>b>>rr;
		if(a>b)swap(a,b);//keep a<b
		INT x=0;
		bool fb=1;
		for(INT i=mxb;i>=0;i--){
			if(a&(((INT)1)<<i) ^ b&(((INT)1)<<i)){
//				cout<<"find bit:"<<i<<endl;
				if(fb){
					fb=0;
					continue;
				}else{
					if(b&(((INT)1)<<i) && (x|(((INT)1)<<i))<=rr){
						x|=((INT)1)<<i;
					}
				}
			}
		}
		cout<<abs((a^x)-(b^x))<<endl;
//		cout<<"x:"<<x<<endl;
	}
	return 0;
}




```
