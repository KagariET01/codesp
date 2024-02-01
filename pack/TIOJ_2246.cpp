
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
template<typename T>auto(reader)=[](){T(re);return(cin>>re,re);};


template<typename T1,typename T2>ostream&operator<<(ostream&ou,pair<T1,T2>p){
	return ou<<"{"<<p.first<<","<<p.second<<"}";
}
template<typename T1,typename T2>istream&operator>>(istream&ii,pair<T1,T2>&p){
	return ii>>p.first>>p.second;
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
	INT n,r;
	cin>>n>>r;
	PII lst[n];
	for(INT i=0;i<n;i++){
		cin>>lst[i];
	}
	map<PII,INT> mp;
	for(INT i=0;i<n;i++){
		for(INT x=-r;x<=r;x++){
			for(INT y=-r;y<=r;y++){
				if(x*x+y*y>r*r)continue;
				else mp[make_pair(lst[i].first+x,lst[i].second+y)]++;
			}
		}
	}
	INT ans=0;
	for(pair<PII,INT> i:mp){
		ans+=(i.second&1);
	}
	cout<<ans<<endl;
	return 0;
}



