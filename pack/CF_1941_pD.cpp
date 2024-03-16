

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
		INT n,m,x;
		cin>>n>>m>>x;
		set<INT> pos;
		pos.insert(0);
		while(m--){
			INT r;
			char op;
			cin>>r>>op;
			if(op=='0'){
				x+=r;
				x+=n;
				x%=n;
			}else if(op=='1'){
				x-=r;
				x+=n;
				x%=n;
			}else{
				vector<INT> nw;
				for(const INT&i:pos)nw.push_back(i);
				pos.clear();
				for(INT&i:nw){
					INT li=i+r;
					li+=n;
					li%=n;
					pos.insert(li);

					INT ri=i-r;
					ri+=n;
					ri%=n;
					pos.insert(ri);
				}
			}
		}
		set<INT> ans;
		for(INT i:pos){
			INT read=((i+x)%n+n)%n;
			if(read==0){
				read=n;
			}
			ans.insert(read);
		}
		cout<<ans.size()<<endl;
		bool f=0;
		for(const INT&i:ans){
			if(f)cout<<" ";
			cout<<i,f=1;
		}
		cout<<endl;
	}
	return 0;
}



