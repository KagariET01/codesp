


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
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return(ou<<"}");
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
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		INT a[n+1]={};
		INT tota[n+1]={};
		INT itcan[n+1]={};
		INT totitcan[n+1]={};
		for(INT i=1;i<=n;i++){
			cin>>a[i];
			tota[i]=tota[i-1]+a[i];
		}
		for(INT i=1;i<=n;i++){
			if(i>1){
				if(a[i-1]<a[i])itcan[i]=1;
			}if(i<n){
				if(a[i]>a[i+1])itcan[i]=1;
			}
			totitcan[i]=totitcan[i-1]+itcan[i];
		}
		auto check_l=[&](INT i){
			if(tota[i-1]<=a[i] || totitcan[i-1]==totitcan[0])return -1ll;
			INT l=1,r=i;
			while(l<r){
				INT mid=(r-l)/2+l+1;
				
				INT t=tota[i-1]-tota[mid-1];
				INT itc=totitcan[i-1]-totitcan[mid];
				if(a[mid]>a[mid+1])itc++;
				if(itc && t>a[i]){
					l=mid;
					continue;
				}else{
					r=mid-1;
					continue;
				}
			}
			return i-l;
		};
		auto check_r=[&](INT i){
			if(tota[n]-tota[i]<=a[i] || totitcan[n]==totitcan[i])return -1ll;
			INT l=i+1,r=n+1;
			while(l<r){
				INT mid=(r-l)/2+l;
				INT t=tota[mid]-tota[i];
				INT itc=totitcan[mid-1]-totitcan[i];
				if(a[mid]>a[mid-1])itc++;
				if(itc && t>a[i]){
					r=mid;
					continue;
				}else{
					l=mid+1;
					continue;
				}
			}
			return l-i;
		};
		for(INT i=1;i<=n;i++){
			if(i>1)cout<<" ";
			INT ll=check_l(i);
			INT rr=check_r(i);
			if(rr==-1)cout<<ll;
			else if(ll==-1)cout<<rr;
			else cout<<min(ll,rr);
		}
		cout<<endl;
	}
	return 0;
}



