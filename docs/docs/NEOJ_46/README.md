# [`NEOJ 46`](https://neoj.sprout.tw/problem/46/) 染色遊戲
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
template<typename T>istream&operator>>(istream&in,vector<T>&vec){
	for(T&i:vec)in>>i;
	return in;
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
		INT n;
		cin>>n;
		PII R,Y,B;
		for(INT i=0;i<3;i++){
			char c;
			PII addr;
			cin>>c>>addr;
			if(c=='R')R=addr;
			if(c=='Y')Y=addr;
			if(c=='B')B=addr;
		}
		char q;
		cin>>q;
		auto ctr=[&](INT pnt,INT i){
			pnt+=i;
			if(pnt<=0)pnt=0;
			if(pnt>=n)pnt=n-1;
			return pnt;
		};
		auto min3=[](INT a,INT b,INT c){
			return min(a,min(b,c));
		};
		auto max3=[](INT a,INT b,INT c){
			return max(a,max(b,c));
		};
		auto sz=[](INT u,INT d,INT l,INT r){
			return max(d-u+1,0ll)*max(r-l+1,0ll);
		};
		INT ans=0;
		for(INT i=0;i<=n;i++){
			INT ys=0,bs=0,rs=0;
			INT os=0,ps=0,gs=0;
			INT ds=0;
			//y
			INT yu=ctr(Y.F,-i);
			INT yd=ctr(Y.F,i);
			INT yl=ctr(Y.S,-i);
			INT yr=ctr(Y.S,i);
			ys=sz(yu,yd,yl,yr);
			//b
			INT bu=ctr(B.F,-i);
			INT bd=ctr(B.F,i);
			INT bl=ctr(B.S,-i);
			INT br=ctr(B.S,i);
			bs=sz(bu,bd,bl,br);
			//r
			INT ru=ctr(R.F,-i);
			INT rd=ctr(R.F,i);
			INT rl=ctr(R.S,-i);
			INT rr=ctr(R.S,i);
			rs=sz(ru,rd,rl,rr);

			//o
			INT ou=max(yu,ru);
			INT od=min(yd,rd);
			INT ol=max(yl,rl);
			INT ori=min(yr,rr);
			os=sz(ou,od,ol,ori);
			//g
			INT gu=max(yu,bu);
			INT gd=min(yd,bd);
			INT gl=max(yl,bl);
			INT gr=min(yr,br);
			gs=sz(gu,gd,gl,gr);
			//p
			INT pu=max(ru,bu);
			INT pd=min(rd,bd);
			INT pl=max(rl,bl);
			INT pr=min(rr,br);
			ps=sz(pu,pd,pl,pr);

			//d
			INT du=max3(ru,yu,bu);
			INT dd=min3(rd,yd,bd);
			INT dl=max3(rl,yl,bl);
			INT dr=min3(rr,yr,br);
			ds=sz(du,dd,dl,dr);

			os-=ds;
			gs-=ds;
			ps-=ds;

			ys-=os;
			ys-=gs;
			ys-=ds;

			rs-=os;
			rs-=ps;
			rs-=ds;

			bs-=gs;
			bs-=ps;
			bs-=ds;

			if(q=='R')maxs(ans,rs);
			if(q=='Y')maxs(ans,ys);
			if(q=='B')maxs(ans,bs);
			if(q=='O')maxs(ans,os);
			if(q=='P')maxs(ans,ps);
			if(q=='G')maxs(ans,gs);
			if(q=='D')maxs(ans,ds);
		}
		cout<<ans<<endl;
	}
	return 0;
}




```
