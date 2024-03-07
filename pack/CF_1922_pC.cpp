

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
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)

template<typename T>auto(reader)=[](){T(re);return(cin>>re,re);};


template<typename T1,typename T2>ostream&operator<<(ostream&ou,pair<T1,T2>p){
	return ou<<"{"<<p.first<<","<<p.second<<"}";
}
template<typename T1,typename T2>istream&operator>>(istream&in,pair<T1,T2>&p){
	return in>>p.first>>p.second;
}
template<typename T>istream&operator>>(istream&in,vector<T>&vec){
	for(T&i:vec)in>>i;
	return in;
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
		for(INT i=1;i<=n;i++){
			cin>>a[i];
		}
		INT glf[n+1]={};//go left get free
		INT grf[n+1]={};//go right get free
		for(INT i=1;i<=n;i++){
			if(i==1 || (i!=n && a[i]-a[i-1]>a[i+1]-a[i])){
				grf[i]=a[i+1]-a[i]-1;
			}else if(i==n || a[i]-a[i-1]<a[i+1]-a[i]){
				glf[i]=a[i]-a[i-1]-1;
			}
		}
		for(INT i=1;i<=n;i++){
			glf[i]+=glf[i-1];
			grf[i]+=grf[i-1];
		}
		INT m;
		cin>>m;
		while(m--){
			INT x,y;
			cin>>x>>y;
			if(x<y){//go right
				INT ans=a[y]-a[x];
				ans-=grf[y-1]-grf[x-1];
				cout<<ans<<endl;
			}else{
				INT ans=a[x]-a[y];
				ans-=glf[x]-glf[y];
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}



