

#include<bits/stdc++.h>
using namespace std;
#define INT int
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
		string mp[2];
		cin>>mp[0]>>mp[1];
		string ansstr;
		INT x=0,y=0;
//		INT dp[2][n]={};
//		dp[0][0]=1;
//		for(INT i=0;i<n-1;i++){
//			if(mp[0][i+1]==mp[1][i]){
//				dp[0][i+1]+=dp[0][i];
//				dp[1][i]+=dp[0][i];
//				dp[1][i+1]+=dp[1][i];
//			}else if(mp[0][i+1]=='0'){
//				dp[0][i+1]+=dp[0][i];
//			}else{
//				dp[
//			}
//		}
		INT cnt=1;
		while(x!=1 || y!=n-1){
			ansstr+=mp[x][y];
			if(x==1){
				y++;
			}else if(y==n-1){
				x++;
			}else if(mp[x+1][y]==mp[x][y+1]){
				y++;
				cnt++;
			}else if(mp[x+1][y]=='0'){
				x++;
			}else{
				y++;
				cnt=1;
			}
		}
		ansstr+=mp[1][n-1];
		cout<<ansstr<<endl;
//		cout<<dp[1][n-1]<<endl;
		cout<<cnt<<endl;
	}
	return 0;
}



