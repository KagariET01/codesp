

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
		INT n,q,cmax;
		cin>>n>>q>>cmax;
		INT c[n];
		bool cb[n];
		for(INT i=0;i<n;i++)cin>>c[i],cb[i]=c[i];

		PII qu[q];
		for(auto&i:qu)cin>>i,i.F--,i.S--;
		sort(qu,qu+q);
		INT rit=0,lit=0;
		INT rmx=1;
		INT lmx=1;
		bool ans=1;
		for(auto&i:qu){
			while(lit<=i.F){
				maxs(lmx,c[lit]);
				lit++;
			}
			while(rit<i.S){
				maxs(rmx,c[rit]);
				rit++;
			}

			if(!cb[i.F]){
				if(lmx<rmx){
					maxs(c[i.F],rmx);
					maxs(lmx,c[i.F]);
				}else maxs(c[i.F],1ll);
			}
			if(!cb[i.S]){maxs(c[i.S],lmx+1);}


		}
		rit=lit=0;
		rmx=lmx=1;
		for(auto&i:qu){
			while(lit<=i.F){
				maxs(lmx,c[lit]);
				lit++;
			}
			while(rit<i.S){
				maxs(rmx,c[rit]);
				rit++;
			}
			if(c[i.S]<=lmx || rmx>lmx){
				ans=0;
				break;
			}
		}

		if(ans)for(auto&i:c)if(i>cmax){ans=0;break;}else maxs(i,1ll);
		if(ans)for(INT i=0;i<n;i++)cout<<c[i]<<(i<n-1?' ':endl);
		else cout<<-1<<endl;
	}
	return 0;
}



