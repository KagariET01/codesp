
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
		INT n,k;
		cin>>n>>k;
		vector<INT> vec;
		for(INT i=0;i<n;i++){
			vec.push_back(read(INT));
		}
		if(k>=3){
			cout<<"0"<<endl;
			continue;
		}
		else if(k==1){
			sort(vec.begin(),vec.end());
			INT ans=vec[0];
			for(INT i=1;i<n;i++){
				ans=min(ans,vec[i]-vec[i-1]);
				ans=min(ans,vec[i]);
			}
			cout<<ans<<endl;
			continue;
		}else{
			sort(vec.begin(),vec.end());
			INT ans=vec[0];
			for(INT i=0;i<n;i++){
				ans=min(ans,vec[i]);
				for(INT j=i+1;j<n;j++){
					INT nw=abs(vec[i]-vec[j]);
					ans=min(ans,nw);
					vector<INT>::iterator it=lower_bound(vec.begin(),vec.end(),nw);
					if(it<vec.end()){
						ans=min(ans,abs(nw-(*it)));
					}
					it--;
					if(vec.begin()<=it){
						ans=min(ans,abs(nw-(*it)));
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}



