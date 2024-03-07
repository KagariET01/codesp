

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
		INT n,m;
		cin>>n>>m;
		INT lu,ru,ld,rd;
		cout<<"? 1 1"<<endl;//lu
		cout<<"? 1 "<<m<<endl;//ru
		cout<<"? "<<n<<" 1"<<endl;
		cout<<"? "<<n<<" "<<m<<endl;
		cout.flush();
		cin>>lu>>ru>>ld>>rd;
		INT x,y;
		//get y
		if(abs(lu-ru)+1==m){
			if(lu>ru)y=m;
			else y=1;
		}else{
			INT mn=min(lu,ru);
			lu-=mn,ru-=mn;
			if(lu==0){
				y=m-ru-1;
			}else{
				y=lu+1;
			}
			lu+=mn,ru+=mn;
		}
		//get x
		if(abs(lu-ld)+1==n){
			if(lu>ld)x=n;
			else x=1;
		}else{
			INT mn=min(lu,ld);
			lu-=mn,ld-=mn;
			if(lu==0){
				x=n-ld-1;
			}else{
				x=lu+1;
			}
			lu+=mn,ld+=mn;
		}
		cout<<"! "<<x<<" "<<y<<endl;
		cout.flush();
	}
	return 0;
}



