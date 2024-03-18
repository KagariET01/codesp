

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
	INT n,c;
	cin>>n>>c;
	vector<INT> a(n);
	cin>>a;
	INT tot=0;
	for(INT&i:a)tot+=i;
	INT al=0;
	INT bl=0;
	INT mx=0;
	INT mn=0;
	INT anw=0;
	INT bnw=0;
	for(INT r=0;r<n;r++){
		anw+=a[r];
		bnw+=a[r];
		while(anw<0){
			anw-=a[al];
			al++;
		}
		while(bnw>0){
			bnw-=a[bl];
			bl++;
		}
		maxs(mx,anw);
		mins(mn,bnw);
	}
	if(c<=0){
		tot-=mn;
		tot+=mn*c;
	}else{
		tot-=mx;
		tot+=mx*c;
	}
	cout<<tot<<endl;
	return 0;
}



