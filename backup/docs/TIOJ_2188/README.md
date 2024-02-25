# [`TIOJ 2188`](https://tioj.ck.tp.edu.tw/problems/2188) [`TOI 2020 pA`]( ) 字串解壓縮
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
	string str;
	cin>>str;
	stringstream ss;
	bool num=0;
	for(char c:str){
		if('0'<=c && c<='9'){
			ss<<c;
			num=1;
			continue;
		}else{
			if(num){
				INT n;
				ss>>n;
				for(INT j=0;j<n;j++){
					cout<<c;
				}
				num=0;
				ss.clear();
			}else{
				cout<<c;
			}
		}
	}
	cout<<endl;
	return 0;
}




```
