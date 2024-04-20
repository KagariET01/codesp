

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
		INT n,x,y;
		cin>>n>>x>>y;
		vector<INT>vec(x);
		cin>>vec;
		sort(vec.begin(),vec.end());
		INT ans=0;
		INT a=vec[0];
		INT b=vec[1];
		vector<INT>avec;
		INT cadd=0;
		auto rec=[&](){
			if(b-a<=2)return;
			else{
				INT md=b-a-1;
				INT c=(md)/2;//a->a+1->a+2->a  add:a+2->a
				if(md%2==1)avec.push_back(c);
				cadd+=c;
				//cerr<<pit(a)<<pit(b)<<pit(md)<<pit(c)<<endl;
			}
		};
		if(b-a==2)ans++;
		else{
			rec();
		}
		for(INT i=2;i<x;i++){
			INT c=vec[i];
			if(c-b==2)ans++;
			ans++;//a->b->c->a
			a=b;
			b=c;
			rec();
		}
		b=n+vec[0];
		a=vec[x-1];
		rec();
		if(b-a==2)ans++;
		//cerr<<pit(ans)<<endl;
		//cerr<<pit(cadd)<<pit(y);
		ans+=min(cadd,y)*2;
		sort(avec.begin(),avec.end());
		//cerr<<pit(avec)<<endl;
		for(INT i:avec){
			if(i>y)break;
			y-=i;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}



