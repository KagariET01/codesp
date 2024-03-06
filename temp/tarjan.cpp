

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



const INT mxn=1e5+5;
INT t=0;//時間戳
INT dfn[mxn];//點i的時間戳，某種意義上算是深度的一種
INT low[mxn];//走一條回邊後，可以到達的最老祖先
bool cut[mxn];//是割點？是：否
vector<INT> tree[mxn];

void reset(INT n){
	t=0;
	for(INT i=0;i<=n;i++){
			dfn[i]=0;
			low[i]=0;
			tree[i].clear();
	}
}

void tarjan(INT nw,INT lst=-1){
	INT cnt=0;
	//先將自己的父節點設為自己
	dfn[nw]=low[nw]=++t;
	for(INT v:tree[nw]){
		if(!dfn[v]){//下一個點沒走過
			tarjan(v,nw);
			low[nw]=min(low[nw],low[v]);//繼續走下去，下一條邊是樹邊，不是回邊，所以取下個點的low
			cnt++;//子樹+1
			if(low[v]>=dfn[nw])cut[nw]=1;//子樹的回邊沒辦法回到比自己老的祖先點
		}else{
			low[nw]=min(low[nw],dfn[v]);//下一個點走過了，代表是祖先，而這條邊是回邊
			//而我們只能走一次回邊，所以求的是和dfn[v]的min
		}
	}
	if(lst==-1 && cnt<=1){cut[nw]=0;}//特判：初始根節點的所有子節點都走不到比根還要高的地方，所以它不是割點
																	 //也是特例：如果子樹數量>1，那也是割點
	
}








int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,m;
	cin>>n>>m;
	reset(n);
	for(INT i=0;i<m;i++){
		INT a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	tarjan(1);
	INT c=0;
	for(INT i=1;i<=n;i++){
		c+=cut[i];
	}
	cout<<c<<endl;
	bool f=0;
	for(INT i=1;i<=n;i++){
		if(cut[i]){
			if(f)cout<<" ";
			cout<<i;
			f=1;
		}
	}
	cout<<endl;
	return 0;
}



