

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
		INT n,m,k,d;
		cin>>n>>m>>k>>d;
		INT mp[n][m];
		for(auto&i:mp)for(INT&j:i)cin>>j;
		INT dp[n][m]={};
		for(auto&i:dp)for(auto&j:i)j=1e18;
		for(INT i=0;i<n;i++){
			dp[i][0]=mp[i][0]+1;
		}
		vector<INT> vec;
		vec.clear();
		for(INT i=0;i<n;i++){
			deque<INT> que;
			que.clear();
			que.push_back(0);
			for(INT j=1;j<m;j++){
				while(abs(j-que.front())-1>d){
					que.pop_front();
				}
				dp[i][j]=dp[i][que.front()]+mp[i][j]+1;
				while(!que.empty() && dp[i][que.back()]>=dp[i][j]){
					que.pop_back();
				}
				que.push_back(j);
			}
			vec.push_back(dp[i][m-1]);
		}
		INT ans=1e18;
		for(INT i=0;i+k-1<n;i++){
			INT nw=0;
			for(INT j=0;j<k;j++){
				nw+=vec[i+j];
			}
			mins(ans,nw);
		}
		cout<<ans<<endl;
		if(0){
			for(INT i=0;i<n;i++){
				for(INT j=0;j<m;j++){
					cout<<dp[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
}



