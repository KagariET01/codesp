# [`TIOJ 2055`](https://tioj.ck.tp.edu.tw/problems/2055) [`TOI 2018 pE`]() 直升機
## 標籤

## 題解
***注意，他求的是h[i]+1(i=l,l+1...r)的最小值，非最大值***

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
	INT n;
	cin>>n;
	INT h[__lg(n)+1][n];
	for(INT i=0;i<n;i++)cin>>h[0][i];
	for(INT i=1;i<__lg(n)+1;i++){
		for(INT j=0;j<n;j++){
			if(j+(1<<(i-1))>=n)break;
			h[i][j]=min(h[i-1][j],h[i-1][j+(1<<(i-1))]);
			//cout<<"i:"<<i<<" j:"<<j<<" j+...:"<<(j+(1<<(i-1)))<<endl;;
		}
	}
	INT q=n;
	while(q--){
		INT l,r;
		cin>>l>>r;
		l--,r--;
		INT ln=__lg(r-l+1);
		INT ans=h[ln][l];
		ans=min(ans,h[ln][r-(1<<ln)+1]);
		//cout<<"ln:"<<ln<<" r-...:"<<(r-(1<<ln))<<" ";
		cout<<ans+1<<endl;
	}
	return 0;
}




```
