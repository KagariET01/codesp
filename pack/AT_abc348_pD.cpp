

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

//PII
template<typename T1,typename T2>pair<T1,T2>operator+(pair<T1,T2>a,pair<T1,T2>b){
	return pair<T1,T2>(a.F+b.F,a.S+b.S);
}
template<typename T1,typename T2>pair<T1,T2>operator+=(pair<T1,T2>&a,pair<T1,T2>b){
	return a=a+b;
}
template<typename T1,typename T2>pair<T1,T2>operator-(pair<T1,T2>a,pair<T1,T2>b){
	return pair<T1,T2>(a.F-b.F,a.S-b.S);
}
template<typename T1,typename T2>pair<T1,T2>operator-=(pair<T1,T2>&a,pair<T1,T2>b){
	return a=a-b;
}
template<typename T1,typename T2,typename T3>pair<T1,T2>operator*(pair<T1,T2>a,T3 b){
	return pair<T1,T2>(a.F*b,a.S*b);
}
template<typename T1,typename T2,typename T3>pair<T1,T2>operator*=(pair<T1,T2>&a,T3 b){
	return a=a*b;
}

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









#define PIPII pair<INT,PII>
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT mx[]={0,1,0,-1};
	INT my[]={1,0,-1,0};

	INT h,w;
	cin>>h>>w;
	string str[h];
	for(auto&i:str)cin>>i;
	INT mp[h][w]={};//那格的能量
	INT ps[h][w]={};//曾經最大
	bool passby[h][w]={};
	INT n;
	cin>>n;
	for(INT i=0;i<n;i++){
		INT r,c,e;
		cin>>r>>c>>e;
		r--,c--;
		mp[r][c]=e;
	}
	priority_queue<PIPII>pq;
	PII st={};
	PII ed={};
	for(INT i=0;i<h;i++){
		for(INT j=0;j<w;j++){
			if(str[i][j]=='S'){
				st=PII(i,j);
			}else if(str[i][j]=='T'){
				ed=PII(i,j);
			}
		}
	}
	bool ans=0;
	pq.push(PIPII(mp[st.F][st.S],st));
	ps[st.F][st.S]=mp[st.F][st.S];
	while(!pq.empty()){
		PIPII nw=pq.top();
		pq.pop();
		//cerr<<pit(nw)<<endl;
		if(nw.F==0)continue;
		if(nw.F<ps[nw.S.F][nw.S.S])continue;
		passby[nw.S.F][nw.S.S]=1;
		for(INT i=0;i<4;i++){
			INT nx=nw.S.F+mx[i];
			INT ny=nw.S.S+my[i];
			if(nx<0||h<=nx)continue;
			if(ny<0||w<=ny)continue;
			if(PII(nx,ny)==ed){
				ans=1;
				break;
			}
			INT np=max(nw.F,mp[nx][ny]);
			if(!passby[nx][ny]){
				if(ps[nx][ny]<np){
					ps[nx][ny]=np;
					pq.push(PIPII(np,PII(nx,ny)));
					//cerr<<"  push "<<PIPII(np,PII(nx,ny))<<endl;
				}
			}
		}
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}



