
#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

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
#define dequeue deque
template<typename T>T reader(){T re;cin>>re;return re;}

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
template<typename T1,typename T2,typename T3>pair<T1,T2>operator/(pair<T1,T2>a,T3 b){
	return pair<T1,T2>(a.F/b,a.S/b);
}
template<typename T1,typename T2,typename T3>pair<T1,T2>operator/=(pair<T1,T2>&a,T3 b){
	return a=a/b;
}

template<typename T1,typename T2>ostream&operator<<(ostream&ou,pair<T1,T2>p){
	return ou<<"["<<p.first<<","<<p.second<<"]";
}
template<typename T1,typename T2>istream&operator>>(istream&in,pair<T1,T2>&p){
	return in>>p.first>>p.second;
}

//deque
template<typename T1,typename T2>ostream&operator<<(ostream&ou,deque<T1,T2>&que){
	bool o=0;
	ou<<"[";
	for(T1(i):que){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return(ou<<"]");
}

//stack
template<typename T1,typename T2>ostream&operator<<(ostream&ou,stack<T1,T2>st){
	deque<T1>dq;
	while(!st.empty()){
		dq.push_front(st.top());
		st.pop();
	}
	return(ou<<dq);
}

//queue
template<typename T1,typename T2>ostream&operator<<(ostream&ou,queue<T1,T2>que){
	bool o=0;
	ou<<"[";
	while(!que.empty()){
		if(o)ou<<",";
		ou<<que.front();
		o=1;
		que.pop();
	}
	return(ou<<"]");
}

//priority_queue
template<typename T1,typename T2,typename T3>ostream&operator<<(ostream&ou,priority_queue<T1,T2,T3>pq){
	deque<T1>dq;
	while(!pq.empty()){
		dq.push_front(pq.top());
		pq.pop();
	}
	return(ou<<dq);
}

//vector
template<typename T>istream&operator>>(istream&in,vector<T>&vec){
	for(T&i:vec)in>>i;
	return in;
}
template<typename T>ostream&operator<<(ostream&ou,vector<T>vec){
	bool o=0;
	ou<<"[";
	for(T(i):vec){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return(ou<<"]");
}

//array
template<typename T,std::size_t N>ostream&operator<<(ostream&ou,array<T,N>&a){
	bool o=0;
	ou<<"[";
	for(T&i:a){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return ou<<"]";
}
template<typename T,std::size_t N>istream&operator>>(istream&in,array<T,N>&a){
	for(T&i:a)in>>i;
	return in;
}

//list
template<typename T,std::size_t N>istream&operator>>(istream&in,T(&a)[N]){
	for(T&i:a)in>>i;
	return in;
}



//map
template<typename T1,typename T2>ostream&operator<<(ostream&ou,map<T1,T2>mp){
	bool o=0;
	ou<<"{";
	for(pair<T1,T2>i:mp){
		if(o)ou<<",";
		ou<<i.first<<":"<<i.second;
		o=1;
	}
	return(ou<<"}");
}

//io

template<typename T>void sort(vector<T>&vec){
	sort(vec.begin(),vec.end());
}

template<typename T1,typename T2>vector<pair<T1,T2>>zip(vector<T1>a,vector<T2>b){
	vector<pair<T1,T2>>re;
	for(INT i=0;i<a.size()&&i<b.size();i++){
		re.push_back(PII(a[i],b[i]));
	}
	return re;
}




/*  ****************************************************  **

    ____ ___  ____  _____   ____ _____  _    ____ _____
   / ___/ _ \|  _ \| ____| / ___|_   _|/ \  |  _ \_   _|
  | |  | | | | | | |  _|   \___ \ | | / _ \ | |_) || |
  | |__| |_| | |_| | |___   ___) || |/ ___ \|  _ < | |
   \____\___/|____/|_____| |____/ |_/_/   \_\_| \_\|_|
  
**  ****************************************************  */

INT n,m;
const INT mxn=805;
const INT bc=32;
set<INT>tree[32][mxn];
set<INT>tree2[mxn];


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);cerr.tie(0);
	cin>>n>>m;
	for(INT i=0;i<m;i++){
		INT a,b;
		cin>>a>>b;
		tree[0][a].insert(b);
	}

	for(INT i=1;i<bc;i++){
		for(INT st=1;st<=n;st++){
			for(INT mid:tree[i-1][st]){
				for(INT ed:tree[i-1][mid]){
					tree[i][st].insert(ed);
				}
			}
		}
	}
	for(INT i=1;i<=n;i++){
		for(INT j=0;j<bc;j++){
			for(INT k:tree[j][i]){
				tree2[i].insert(k);
			}
		}
	}

	priority_queue<PII,vector<PII>,greater<PII>>pq;
	pq.push(PII(0,1));
	INT best[n+1]={};
	for(auto&i:best)i=1e9+7;
	best[1]=0;
	while(!pq.empty()){
		PII nw=pq.top();
		pq.pop();
		if(best[nw.F]<nw.F)continue;
		if(nw.F==n)break;
		for(auto&i:tree2[nw.S]){
			if(best[i]>best[nw.S]+1){
				best[i]=best[nw.S]+1;
				pq.push(PII(best[i],i));
			}
		}

	}
	cout<<best[n]<<endl;

	return 0;
}



