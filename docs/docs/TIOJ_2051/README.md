# [`TIOJ 2051`](https://tioj.ck.tp.edu.tw/problems/2051) [`TOI 2018 pA`]() 化學元素分析
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
template<typename T1,typename T2>ostream&operator<<(ostream&ou,map<T1,T2>mp){
	ou<<"";
	pair<T1,T2> ed=*mp.rbegin();
	for(pair<T1,T2>i:mp){
		
		ou<<""<<i.first<<":"<<i.second<<"\n";
		//if(ed!=i)ou<<",";
	}
	return (ou<<"");
}

map<string,INT> mp;

string str="";
string nwstr="";
INT cnt=0;
INT xx=1;
INT i=0;

void solve(INT x=1){
	while(1){
		if(i<0)break;
		if(str[i]==')'){
			if(cnt==0)cnt=1;
			i--;
			xx=1;
			INT rcnt=cnt;
			cnt=0;
			solve(x*rcnt);
		}
		if(str[i]=='('){
			i--;
			return;
		}
		if('0'<=str[i]&&str[i]<='9'){
			cnt+=xx*(str[i]-'0');
			xx*=10;
			i--;
		}
		if('a'<=str[i]&&str[i]<='z'){
			nwstr=str[i]+nwstr;
			i--;
		}
		if('A'<=str[i]&&str[i]<='Z'){
			nwstr=str[i]+nwstr;
			if(cnt==0)cnt=1;
			mp[nwstr]+=x*cnt;
			cnt=0;
			xx=1;
			nwstr="";
			i--;
		}
	}
}






int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>str;
	i=str.size()-1;
	solve();
	cout<<str<<endl;
	cout<<mp<<endl;
	return 0;
}




```
