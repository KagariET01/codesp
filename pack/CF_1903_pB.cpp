
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
		INT n;
		cin>>n;
		INT m[n][n];
		for(auto &i:m)for(auto&j:i)cin>>j;
		INT a[n]={};
		for(INT&i:a){
			i=(1ll<<30ll)-1;
		}
		for(INT i=0;i<n;i++){
			for(INT j=0;j<n;j++){
				if(i==j)continue;
				a[i]&=m[i][j];
				a[j]&=m[i][j];
			}
		}

		bool ans=1;
		for(INT i=0;i<n && ans;i++){
			for(INT j=0;j<n&&ans;j++){
				if(i==j)continue;
				if((a[i]|a[j])!=m[i][j]){
					ans=0;
				}
			}
		}
		if(ans){
			cout<<"YES"<<endl;
			for(INT i=0;i<n;i++){
				if(i)cout<<" ";
				cout<<a[i];
			}
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}



