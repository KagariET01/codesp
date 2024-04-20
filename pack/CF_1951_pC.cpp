

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

//vector
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

//map
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
		INT n,m,k;
		cin>>n>>m>>k;
		vector<PII>vec;
		vector<INT>a;
		for(INT i=0;i<n;i++){
			vec.push_back(PII(read(INT),i));
			a.push_back(vec[i].F);
		}
		sort(vec.begin(),vec.end());
		INT b[n]={};
		INT c=k;
		INT i=0;
		while(c){
			b[vec[i].S]=min(c,m);
			c-=min(c,m);
			i++;
		}
		INT ans=0;
		INT nwh=0;
		for(INT i=0;i<n;i++){
			ans+=(a[i]+nwh)*b[i];
			nwh+=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}



