

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


INT isqrt(INT n){
	INT l=0,r=n;
	while(l<r){
		INT(mid)=(r-l)/2+l;
		if(mid*mid>=n){
			r=mid;
		}else{l=mid+1;}
	}
	return (l);
}







int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT(t);
	cin>>t;
	while(t--){
		INT(n)=read(INT);
		if(n%3==0&&n%2==0)cout<<1;
		else if(n%2&&n%3)cout<<2;
		else if(isqrt(n)*isqrt(n)==n||(n%7&&n%2==0))cout<<3;
		else{cout<<0;}
		if(t)cout<<char(32);
		else{cout<<endl;}
	}
	return 0;
}



