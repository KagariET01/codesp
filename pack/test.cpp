

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

struct str{
	INT l=1e18+7,c=0,id=0;
};

INT cc(PII a,PII b){
	return  (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}

const INT mxn=1e5+5;
INT n,m;
vector<INT> tree[mxn];
INT a[mxn];
bool ps[mxn];

PII dfs(INT nw){
	ps[nw]=1;
	PII re=PII(0,a[nw]);
	for(INT&i:tree[nw]){
		if(ps[i])continue;
		cout<<nw<<"->"<<i<<endl;
		PII nx=dfs(i);
		maxs(re.F,nx.F);
		maxs(re.F,re.S+nx.S);
		maxs(re.S,nx.S+a[nw]);
	}
	//ps[nw]=0;
	cout<<pit(nw)<<" "<<pit(re)<<endl;
	return re;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	for(INT i=0;i<m;i++){
		INT u,v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for(INT i=1;i<=n;i++)cin>>a[i];
	cout<<dfs(1).F<<endl;
	return 0;
}



