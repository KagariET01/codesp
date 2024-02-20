
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
	INT n,q;
	cin>>n>>q;
	INT a[n];
	for(INT&i:a)cin>>i;
	for(INT&i:a)i-=read(INT);
	sort(a,a+n);
	INT ans[1000005]={};
	INT it=n-1;
	for(INT i=1000000;i>=0;i--){
		while(1){
			if(it<0)break;
			if(a[it]<=i)break;
			it--;
		}
		ans[i]=n-it-1;
	}
	while(q--){
		INT v,s;
		cin>>v>>s;
		if(ans[s]>=v)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}



