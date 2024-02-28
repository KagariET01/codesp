# [`CF 1925 pC`](https://codeforces.com/contest/1925/problem/C) Did We Get Everything Covered?
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
		INT n,k,m;
		cin>>n>>k>>m;
		string str;
		cin>>str;
		bool b[k];
		for(bool&i:b)i=1;
		INT cnt=k;
		string ans="";
		for(char c:str){
			if(c-'a'>=k)continue;
			cnt-=b[c-'a'];
			b[c-'a']=0;
			if(!cnt){
				ans+=c;
				cnt=k;
				for(bool&j:b)j=1;
			}
			if(ans.size()==n)break;
		}
		if(ans.size()==n){
			cout<<"YES"<<endl;
		}else{
			char abc=' ';
			for(INT i=0;i<k;i++){
				if(b[i]){
					abc='a'+i;
					break;
				}
			}
			while(ans.size()<n){
				ans+=abc;
			}
			cout<<"NO"<<endl;
			cout<<ans<<endl;
		}
	}
	return 0;
}




```
