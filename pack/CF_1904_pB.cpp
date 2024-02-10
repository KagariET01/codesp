
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
	ou<<"";
	bool f=0;
	for(T(i):vec){
		if(f)cout<<" ";
		ou<<i<<"";
		f=1;
	}
	return(ou<<"");
}










int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		PII lst[n];
		for(INT i=0;i<n;i++){
			cin>>lst[i].first;
			lst[i].second=i;
		}
		sort(lst,lst+n);
		INT allp=0;
		vector<INT>ans(n);
		INT r=0;
		for(INT i=0;i<n;i++){
			if(i>=r){allp+=lst[i].first;r=i+1;}
			while(r<n&&allp>=lst[r].first){
				allp+=lst[r].first;
				r++;
			}
			ans[lst[i].second]=r-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}



