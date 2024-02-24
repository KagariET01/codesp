

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
		INT n,q;
		cin>>n>>q;
		INT a[n+1]={};
		INT att[n+1]={};
		INT onett[n+1]={};
		for(INT i=1;i<=n;i++){
			cin>>a[i];
			onett[i]=onett[i-1];
			if(a[i]==1)onett[i]++;
			att[i]=att[i-1]+a[i];
		}
		while(q--){
			INT l,r;
			cin>>l>>r;
			INT sz=r-l+1;
			if(l==r){
				cout<<"NO"<<endl;
				continue;
			}
			INT nedtt=att[r]-att[l-1];
			INT twott=onett[r]-onett[l-1];
			nedtt-=twott*2;
			nedtt-=sz-twott;
			if(nedtt>=0)cout<<"YES"<<endl;
			else{cout<<"NO"<<endl;}
		}
	}
	return 0;
}



