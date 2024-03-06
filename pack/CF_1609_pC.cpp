

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

vector<INT> prime(INT n){
	vector<INT> re;
	vector<INT> l(n+1);
	if(n<2)return re;
	for(INT i=2;i<=n;i++){
		if(l[i]<=1){
			re.push_back(i);
		}
		for(INT&j:re){
			if(i*j>n)break;
			l[i*j]=j;
			if(j==l[i])break;
		}


	}
	return re;
}








int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	vector<INT> v=prime(1e6+5);
	vector<bool> v2(1e6+5);
	for(INT&i:v){
		v2[i]=true;
	}
	INT t;
	cin>>t;
	while(t--){
		INT n,e;
		cin>>n>>e;
		INT a[n];
		for(INT&i:a)cin>>i;
		vector<INT> lst[e];
		for(INT i=0;i<n;i++){
			lst[i%e].push_back(a[i]);
		}
//		for(INT i=0;i<e;i++){
//			cout<<lst[i]<<endl;
//		}
		INT ans=0;
		for(INT i=0;i<e;i++){
			INT loc=1;
			INT roc=1;
			bool f=0;
			for(INT j=0;j<lst[i].size();j++){
				if(lst[i][j]==1){
					if(!f)loc++;
					else roc++;
				}else if(v2[lst[i][j]]){
					if(f){
						ans+=loc*roc-1;
						loc=roc;
						roc=1;
					}
					f=1;
				}else{
					ans+=(loc*roc-1)*f;
					f=0;
					loc=roc=1;
				}
			}
			if(f){
				ans+=loc*roc-1;
			}
//			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}



