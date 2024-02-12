
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
		INT n,x;
		cin>>n>>x;
		if(n%2 != x%2){
			cout<<"0"<<endl;
			continue;
		}else{
			INT ans=1;
			for(INT i=x;i<=n/2;i++){
				INT md=(i-1)*2;
				INT pnt=n%md;
				if(pnt==0)pnt=2;
				if(pnt>i){
					pnt-=i;
					pnt=i-pnt;
				}
				if(pnt==x)ans++;
				//cout<<"i:"<<i<<" pnt:"<<pnt<<endl;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}



