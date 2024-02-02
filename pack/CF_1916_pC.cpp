
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
	function<void()> solve=[](){
		INT n;
		cin>>n;
		vector<INT>vec;
		for(INT(i)=0;i<n;i++){
			vec.push_back(read(INT));
		}
		INT oddc=0;
		INT tt=0;
		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			tt+=vec[i]-vec[i]%2;
			oddc+=vec[i]&1;
			INT nw=tt;
			if(oddc%3==0){
				nw+=oddc/3*2;
			}else if(oddc%3==1){
				nw+=(oddc-1)/3*2;
			}else{
				nw+=(oddc-2)/3*2+2;
			}
			if(i==0)nw=vec[0];
			cout<<nw;
		}
		cout<<endl;
	};

	INT t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}



