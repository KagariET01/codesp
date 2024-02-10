
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
		INT ans=0;
		vector<INT> lst(n);
		for(INT &i:lst){
			cin>>i;
			ans=max(ans,i);
		}
		INT l=0,r=1e12;
		auto checker=[&](INT need){
			for(INT i=0;i<n;i++){
				INT nwk=k;
				INT nwneed=need;
				for(INT j=i;j<n;j++){
					if(lst[j]>=nwneed)return true;
					else{
						nwk-=nwneed-lst[j];
						nwneed--;
					}
					if(nwk<0)break;
				}
			}
			return false;
		};
		while(l<r){
			INT mid=(r-l)/2+l+1;
			if(checker(mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<l<<endl;

	}
	return 0;
}



