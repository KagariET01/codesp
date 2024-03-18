

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
	ou<<"";
	for(T(i):vec){
		if(o)ou<<" ";
		ou<<i;
		o=1;
	}
	return(ou<<"");
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
	cin.tie(0);cout.tie(0);cerr.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n,k;
		cin>>n>>k;
		vector<INT> a(n+1),b(n+1);
		for(INT i=0;i<n;i++)a[read(INT)]++;
		for(INT i=0;i<n;i++)b[read(INT)]++;
		vector<INT> ansa,ansb;
		for(INT i=1;i<=n;i++){
			if(a[i]==2&&ansa.size()<=k*2-2){
				ansa.push_back(i);
				ansa.push_back(i);
			}else if(b[i]==2 && ansb.size()<=k*2-2){
				ansb.push_back(i);
				ansb.push_back(i);
			}
		}
		for(INT i=1;i<=n;i++){
			if(ansa.size()==k*2 && ansb.size()==k*2)break;
			else if(a[i]&&b[i]){
				ansa.push_back(i);
				ansb.push_back(i);
			}
		}
		cout<<ansa<<endl;
		cout<<ansb<<endl;
	}
	return 0;
}



