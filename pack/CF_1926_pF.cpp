
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
		ou<<i<<",";
	}
	return(ou<<"\b}");
}

INT mx[]={1,1,-1,-1};
INT my[]={1,-1,1,-1};








int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	INT n=7;
	while(t--){
		string mp[7];
		for(INT i=0;i<n;i++){
			cin>>mp[i];
		}
		bool nok=1;
		INT ans=0;
		while(nok){
			if(ans>=10)break;
			nok=0;
			map<PII,INT> mpb;
			for(INT i=0;i<n;i++){
				for(INT j=0;j<n;j++){
					if(mp[i][j]=='W')continue;
					INT cnt=0;
					for(INT k=0;k<4;k++){
						INT x=i+mx[k];
						INT y=j+my[k];
						if(x<0 || n<=x)break;
						if(y<0 || n<=y)break;
						if(mp[x][y]=='W')break;
						cnt++;
					}
					if(cnt>=4){
						nok=1;
						mpb[PII(i,j)]++;
						for(INT k=0;k<4;k++){
							INT x=i+mx[k];
							INT y=j+my[k];
							mpb[PII(x,y)]++;
						}
					}
				}
			}
			if(nok){
				ans++;
				INT mx=0;
				PII p;
				for(auto i:mpb){
					if(i.S>mx){
						mx=i.S;
						p=i.F;
					}
				}
				mp[p.F][p.S]='W';
			}else break;
		}
		cout<<ans<<endl;
	}
	return 0;
}



