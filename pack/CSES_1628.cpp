

#include<bits/stdc++.h>
using namespace std;
#define INT unsigned int
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
	INT(n),x;
	cin>>n>>x;
	vector<INT>t1(n/2),t2(n-n/2);
	cin>>t1>>t2;
	map<INT,INT>mp1,mp2;
	auto bitfind=[&](vector<INT>&t,map<INT,INT>&m){
		for(INT(i)=0;i<(1<<(t.size()));i++){
			INT(nw)=0;
			for(INT(j)=0;j<t.size();j++){
if(i&(1<<j))nw+=t[j];
			}
m[nw]++;
		}
	};
	bitfind(t1,mp1);
	bitfind(t2,mp2);
	INT(ans)=0;
	for(auto&i:mp1){
		if(i.F>x)break;
ans+=i.S*mp2[x-i.F];
	}
	cout<<ans<<endl;

	return 0;
}



