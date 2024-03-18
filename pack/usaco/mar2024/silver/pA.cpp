

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
template<typename T1>ostream&operator<<(ostream&ou,set<T1>se){
	bool o=0;
	ou<<"{";
	for(T1 i:se){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return(ou<<"}");
}








int main(){
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,k;
	cin>>n>>k;
	INT t[n];
	for(auto&i:t)cin>>i;
	priority_queue<PII,vector<PII>,greater<PII>> pq;//end time,farmer id
	vector<set<INT>> tree(k,set<INT>());
	INT it=k;
	for(INT i=0;i<k;i++){
		pq.push(PII(t[i],i));
	}
	INT lst=-1;
	INT lsf=-1;
	INT fin=-1;
	while(it<n){
		PII nw=pq.top();
		pq.pop();
		if(nw.F==lst){
			if(lsf!=-1){
				tree[lsf].insert(nw.S);
				tree[nw.S].insert(lsf);
			}
		}
		lst=nw.F;
		lsf=nw.S;
		pq.push(PII(nw.F+t[it],nw.S));
		it++;
	}
	for(INT i=0;i<2;i++){
		if(i){
			lst=pq.top().F;
			lsf=pq.top().S;
		}
		while(!pq.empty()&&(pq.top().F==lst || lsf==-1)){
			PII nw=pq.top();
			pq.pop();
			if(lsf!=-1){
				tree[lsf].insert(nw.S);
				tree[nw.S].insert(lsf);
			}
			auto&[lst,lsf]=nw;
		}
	}
	cout<<lst<<endl;
	//
	bool ok[k]={};
	queue<INT> que;
	que.push(lsf);
	while(!que.empty()){
		INT nw=que.front();
		que.pop();
		ok[nw]=1;
		for(INT nx:tree[nw]){
			if(ok[nx])continue;
			ok[nx]=1;
			que.push(nx);
		}
	}
	for(INT i=0;i<k;i++){
		if(ok[i])cout<<1;
		else cout<<0;
	}
	cout<<endl;
	return 0;
}



