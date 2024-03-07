

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



const INT mxn=1e9+7;






int main(){
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	vector<INT> lst={1,3,6,10,15};
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		priority_queue<PII,vector<PII>,greater<PII>> pq;//{time,left}
		pq.push(PII(0,n));
		INT ans=1e9+7;
		while(!pq.empty()){
			PII nw=pq.top();
			pq.pop();
			if(nw.F+nw.S/15>ans)continue;
			if(nw.S==0){
				mins(ans,nw.F);
			}else{
				for(INT i=0;i<5;i++){
					if(nw.S<lst[i])break;
					pq.push(PII(nw.F+1,nw.S-lst[i]));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



