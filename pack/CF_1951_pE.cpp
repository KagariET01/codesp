

#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define superINT INT
#define read(n) reader<n>()
#define PII pair<INT,INT>
#define PPIIPII pair<PII,PII>
#define pit(n) #n<<":"<<n<<" "
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

//vector
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

//map
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
		string str;
		cin>>str;
		INT n=str.size();
		auto lf=[](string&s,INT l,INT r)->bool{
			r--;
			if(l>=r)return(false);
			while(l<r){
				if(s[l]!=s[r])return(true);
				l++,r--;
			};
			return(false);
		};
		if(lf(str,0,n)){
			cout<<"YES"<<endl;
			cout<<1<<endl;
			cout<<str<<endl;
			continue;
		}
		INT fdf=-1;
		for(INT i=1;i<n;i++){
			if(str[i]!=str[0]){
				fdf=i;
				break;
			}
		}
		if(fdf==-1){
			cout<<"NO"<<endl;
			continue;
		}
		bool ans=0;
		for(INT cc=1;cc<3;cc++){
			if(lf(str,0,fdf+cc)&&lf(str,fdf+cc,n)&&(n-(fdf+cc))>0){
				cout<<"YES"<<endl;
				cout<<2<<endl;
				cout<<str.substr(0,fdf+cc)<<" "<<str.substr(fdf+cc,n)<<endl;
				ans=1;
				break;
			}
		}
		if(!ans)cout<<"NO"<<endl;
	}
	return 0;
}



