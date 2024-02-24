
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
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		char c;
		cin>>c;
		string str[n*2];
		map<char,vector<string>> mp;
		for(INT i=0;i<n*2;i++){
			cin>>str[i];
			mp[str[i][1]].push_back(str[i]);
		}
		for(auto&i:mp){
			sort(i.second.begin(),i.second.end());
		}
		INT odd=0;
		for(auto&i:mp){
			if(i.F==c)continue;
			odd+=(i.S.size())&1;
		}
		if(odd>mp[c].size()){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		INT k=0;
		for(auto&i:mp){
			if(i.F==c)continue;
			for(INT j=0;j<i.S.size();j+=2){
				if(j==i.S.size()-1){
					cout<<i.S[j]<<" "<<mp[c][k]<<endl;
					k++;
				}else{
					cout<<i.S[j]<<" "<<i.S[j+1]<<endl;
				}
			}
		}
		for(INT i=odd;i<mp[c].size();i+=2){
			cout<<mp[c][i]<<" "<<mp[c][i+1]<<endl;
		}
	}
	return 0;
}



