# [`ZJ n262`](https://zerojudge.tw/ShowProblem?problemid=n262) 我討厭零錢
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
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)

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
	INT n,m;
	cin>>n>>m;
	INT cbig[7]={1,5,10,50,100,500,1000};
	INT hve[7]={};// wen have
	for(INT i=6;i>=0;i--){
		hve[i]=n/cbig[i];
		n%=cbig[i];
	}
	INT lned[7]={};
	for(INT i=6;i>=0;i--){
		lned[i]=m/cbig[i];
		m%=cbig[i];
	}
	INT ans=0;
	for(INT i=0;i<7;i++){
		if(i<6){
		//進位
			INT mpc=cbig[i+1]/cbig[i];//幾枚i幣可以換成i+1幣
			lned[i+1]+=lned[i]/mpc;
			lned[i]%=mpc;
		}
		//給$
		if(hve[i]>=lned[i]){
			ans+=cbig[i]*lned[i];
		}else if(i<6){
			lned[i+1]++;
		}
	}
	cout<<ans<<endl;
	return 0;
}




```
