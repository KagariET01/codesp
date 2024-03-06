

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


INT cer(INT c){
	return (c+1)*c/2;
}







int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		PII lst[n];
		for(auto&[i,j]:lst)cin>>i;
		for(auto&[i,j]:lst)cin>>j;
		INT dp[n]={};
		for(INT i=0;i<n;i++){
			dp[i]=lst[i].F-lst[i].S+1;
			for(INT j=i-1;j>=0;j--){
				if(lst[j].F>=dp[i])mins(dp[i],dp[j]);
			}
		}
		INT ans=0;
		INT nw=1e18;
		for(INT i=n-1;i>=0;i--){
			if(lst[i].F<nw){
				nw=dp[i];
				ans+=cer(lst[i].F-dp[i]+1);

			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



