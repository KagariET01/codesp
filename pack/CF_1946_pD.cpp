

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
		INT n,x;
		cin>>n>>x;
		vector<INT> vec(n+1);
		vector<INT> xvec(n+1);
		for(INT i=1;i<=n;i++){
			cin>>vec[i];
			xvec[i]=xvec[i-1];
			xvec[i]^=vec[i];
		}
		//cerr<<pit(xvec)<<endl;
		INT l=0;
		INT ans=0;
		INT ltt=0;
		INT lst=0;
		if(xvec[n]>x){
			cout<<-1<<endl;
			continue;
		}
		for(INT r=1;r<=n;r++){
			if(( ltt | lst | (xvec[l]^xvec[r]) | (xvec[r]^xvec[n]) )<=x){
				ans++;
				ltt|=lst;
				lst=xvec[l]^xvec[r];
				l=r;
			}else if(lst^xvec[l]^xvec[r]<lst){
				lst^=xvec[l]^xvec[r];
				l=r;
			}
			//cerr<<pit(l)<<" "<<pit(r)<<" "<<pit(ltt)<<" "<<pit(lst)<<" "<<pit(ans)<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}



