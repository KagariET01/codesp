
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
	INT n,m;
	cin>>n>>m;
	string way;
	cin>>way;
	INT a[n];
	INT ora[n];
	for(INT i=0;i<n;i++){
		cin>>a[i],ora[i]=a[i];
	}
	for(INT i=0;i<n;i++){
		if(way[i]=='R'){
			a[(i+1)%n]+=m;
		}else{
			a[(i+n-1)%n]+=m;
		}
		a[i]-=m;
	}
	bool notok=1;
	while(notok){
		for(INT i=0;i<n;i++){
			if(a[i]<0){
				if(way[i]=='R'){
					a[(i+1)%n]+=a[i];
				}else{
					a[(i+n-1)%n]+=a[i];
				}
				a[i]-=a[i];
			}
		}
		notok=0;
		for(INT i=0;i<n;i++){
			if(a[i]<0){
				notok=1;
				break;
			}
		}
	}
	INT ans=0;
	for(INT i=0;i<n;i++){
		ans+=min(a[i],ora[i]);
	}
	cout<<ans<<endl;
	return 0;
}



