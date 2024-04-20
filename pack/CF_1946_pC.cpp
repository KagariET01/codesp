

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
//	cin.tie(0);cout.tie(0);cerr.tie(0);ios::sync_with_stdio(0);
	INT(t);
	cin>>t;
	while(t--){
		INT n,k;
		cin>>n>>k;
		vector<vector<INT>>tree(n+1,vector<INT>(0));
		for(INT(i)=0;i<n-1;i++){
			INT(u),v;
			cin>>u>>v;
			u--,v--;
			tree[u].push_back(v);
			tree[v].push_back(u);

		}
		auto checker=[&](INT need)->INT{//計算可切割成多少子樹
			INT cnt=0;
			INT allnode=0;
			auto dfs=[&](auto dfs2,INT nw,INT lst)->INT{
				INT re=1;
				for(INT&i:tree[nw]){
					if(i==lst)continue;
					re+=dfs2(dfs2,i,nw);
				}
				if(re>=need){cnt++;allnode+=re;return 0;}
				return re;
			};
			dfs(dfs,0,-1);
			if(n-allnode>=need)cnt++;
			return cnt;
		};
		INT(l)=0,r=n+1;
		while(l<r){
			INT mid=(r-l)/2+l+1;//二分搜子數大小
			INT sub=checker(mid);//有多少子樹
			if(sub>k){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<l<<endl;
	}
	return 0;
}



