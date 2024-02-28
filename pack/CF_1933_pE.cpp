

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
		INT tot[n+1]={};
		for(INT i=1;i<=n;i++){
			cin>>a[i];
			tot[i]=tot[i-1]+a[i];
		}
		INT q;
		cin>>q;
		auto c=[&](INT l,INT u){
			if(l<0)return (INT)(-1e9-7);
			return (INT)((u+(u-l+1))*l/2);
		};
		while(q--){
			INT l,u;
			cin>>l>>u;
			l--;
			INT it=lower_bound(tot+l,tot+n,tot[l]+u)-tot;
			if(it>n)cout<<it;
			else if(c(tot[it]-tot[l],u)>c(tot[it-1]-tot[l],u)){
				cout<<it;
			}else{
				cout<<min(n,max(it-1,l+1));
			}
			if(q)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}



