

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
	INT n,p;
	cin>>n>>p;
	PII plst[p];
	INT mxx=0,mxy=0;	
	for(auto&i:plst)cin>>i,maxs(mxx,i.F),maxs(mxy,i.S);
	INT mp[mxx+1][mxy+1];
	for(auto&i:mp)for(auto&j:i)j=-1;
	for(INT i=0;i<p;i++){
		INT j=i+1;
		j%=p;
		if(plst[i].F==plst[j].F){
			if(plst[i].S<plst[j].S){
				for(INT y=plst[i].S;y<=(plst[i].S+plst[j].S)/2;y++){
					mp[plst[i].F][y]=i;
				}
				for(INT y=(plst[i].S+plst[j].S)/2+1;y<=plst[j].S;y++){
					mp[plst[i].F][y]=j;
				}
			}else{
				for(INT y=plst[i].S;y>(plst[i].S+plst[j].S)/2;y--){
					mp[plst[i].F][y]=i;
				}
				for(INT y=(plst[i].S+plst[j].S)/2;y>=plst[j].S;y--){
					mp[plst[i].F][y]=j;
				}
			}
		}else{
			if(plst[i].F<plst[j].F){
				for(INT y=plst[i].F;y<=(plst[i].F+plst[j].F)/2;y++){
					mp[y][plst[i].S]=i;
				}
				for(INT y=(plst[i].F+plst[j].F)/2+1;y<=plst[j].F;y++){
					mp[y][plst[i].S]=j;
				}
			}else{
				for(INT y=plst[i].F;y>(plst[i].F+plst[j].F)/2;y--){
					mp[y][plst[i].S]=i;
				}
				for(INT y=(plst[i].F+plst[j].F)/2;y>=plst[j].F;y--){
					mp[y][plst[i].S]=j;
				}
			}
		}
	}

	INT ans[p]={};
	while(n--){
		bool mn[p]={};
		INT sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		if(sx>ex)swap(sx,ex);
		if(sy>ey)swap(sy,ey);
		if(sx==ex){
			for(INT i=sy;i<=ey;i++){
				if(mp[sx][i]==-1)continue;
				mn[mp[sx][i]]=1;
			}
		}else{
			for(INT i=sx;i<=ex;i++){
				if(mp[i][sy]==-1)continue;
				mn[mp[i][sy]]=1;
			}
		}
		for(INT i=0;i<p;i++){
			ans[i]+=mn[i];
		}
	}
	for(INT i=0;i<p;i++){
		cout<<ans[i]<<endl;
	}
	for(auto&i:mp){
		for(auto&j:i)cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}



