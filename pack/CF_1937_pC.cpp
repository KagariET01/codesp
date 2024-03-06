

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



char query(INT a,INT b,INT c,INT d){
	cout<<"? "<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	cout.flush();
	char re;
	cin>>re;
	cout.flush();
	return re;
}






int main(){
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		if(n==2){
			cout<<"! 0 1"<<endl;
			continue;
		}
		INT ans1=0,ans2;
		vector<INT> vec;
		vec.push_back(0);
		for(INT i=1;i<n;i++){
			char re=query(ans1,ans1,i,i);
			if(re=='<'){
				ans1=i;
			}
		}
		for(INT i=1;i<n;i++){
			char re=query(ans1,vec[0],ans1,i);
			if(re=='<'){
				vec.clear();
				vec.push_back(i);
			}else if(re=='='){
				vec.push_back(i);
			}
		}
		ans2=vec[0];
		for(INT i=1;i<vec.size();i++){
			char re=query(ans2,ans2,vec[i],vec[i]);
			if(re=='>'){
				ans2=vec[i];
			}
		}
		cout<<"! "<<ans1<<" "<<ans2<<endl;
		cout.flush();
	}
	return 0;
}



