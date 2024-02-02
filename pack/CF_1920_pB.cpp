
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
	function<void()>solve=[](){
		INT n,k,x;
		cin>>n>>k>>x;
		vector<INT> vec;
		INT all=0;
		for(INT i=0;i<n;i++){
			INT inin=read(INT);
			vec.push_back(inin);
		}
		sort(vec.begin(),vec.end());
		vector<INT> vectot;
		vectot.push_back(0);
		for(INT i:vec){
			all+=i;
			vectot.push_back(all);
		}
		INT ans=-1e9-7;
		for(INT i=n;i>=n-k;i--){
			ans=max(ans,all-(vectot[i]-vectot[max(i-x,(INT)0)])*2-(vectot[n]-vectot[i]));
		}
		cout<<ans<<endl;

	};
	INT t=read(INT);
	while(t--){
		solve();
	}
	return 0;
}



