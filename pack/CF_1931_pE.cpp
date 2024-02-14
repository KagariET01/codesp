
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










int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n,m;
		cin>>n>>m;
		vector<INT> p;
		p.resize(n);
		INT sz=0;
		for(INT i=0;i<n;i++){
			string str;
			cin>>str;
			INT c=0;
			for(INT j=str.size()-1;j>=0;j--){
				if(str[j]=='0')c++;
				else break;
			}
			p[i]=c;
			sz+=str.size()-c;
		}
		sort(p.begin(),p.end());
		INT xx=0;
		for(INT i=n-1;i>=0;i--){
			sz+=p[i]*xx;
			xx=1-xx;
		}
		if(sz>m){
			cout<<"Sasha"<<endl;
		}else{
			cout<<"Anna"<<endl;
		}
	}

	return 0;
}



