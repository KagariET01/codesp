
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
	INT t;
	cin>>t;
	while(t--){
		INT a,b,xk,yk,xq,yq;
		cin>>a>>b>>xk>>yk>>xq>>yq;
		set<PII> se;
		se.insert({a,b});
		se.insert({a,-b});
		se.insert({-a,b});
		se.insert({-a,-b});
		se.insert({b,a});
		se.insert({b,-a});
		se.insert({-b,a});
		se.insert({-b,-a});
		vector<PII> vec;
		for(PII i:se){
			for(PII j:se){
				vec.push_back({i.F-j.F,i.S-j.S});
			}
		}
		PII f={xk-xq,yk-yq};
		INT ans=0;
		for(PII i:vec){
			if(i==f)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}



