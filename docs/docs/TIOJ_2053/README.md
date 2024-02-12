# [`TIOJ 2053`](https://tioj.ck.tp.edu.tw/problems/2053) [`TOI 2018 pC`]() 費氏數列
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

struct str{
	INT lst[2][2]={};
};

const INT mod=1000000007;

str operator*(str a,str b){
	str re;
	for(INT i=0;i<2;i++){
		for(INT j=0;j<2;j++){
			for(INT k=0;k<2;k++){
				re.lst[i][j]+=a.lst[i][k]*b.lst[k][j];
				re.lst[i][j]%=mod;
			}
		}
	}
	return re;
}

template<typename T>T spow(T a,INT n){
	if(n<=0){
		T re;
		return re;
	}
	T re=a;
	T x=a;
	n--;
	while(n){
		if(n&1){
			re=re*x;
		}
		x=x*x;
		n>>=1;
	}
	return re;
}






int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT x1,x2,a,b,n;
	cin>>x1>>x2>>a>>b>>n;
	str x;
	x.lst[0][1]=a;
	x.lst[1][1]=b;
	x.lst[1][0]=1;
	x.lst[0][0]=0;
	str f;
	f.lst[0][0]=x1;
	f.lst[0][1]=x2;
	n-=2;
	x=spow(x,n);
	f=f*x;
	cout<<f.lst[0][1]<<endl;
	return 0;
}




```
