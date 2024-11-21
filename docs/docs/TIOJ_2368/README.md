# [`TIOJ 2368`](https://tioj.ck.tp.edu.tw/problems/2368) 與自動輔助駕駛暢遊世界
## 標籤

## 題解
NOT FOUND  

## 程式碼
```cpp

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

const INT mxn=3005;
INT n,m;
vector<INT>tree[mxn];
vector<INT>bktree[mxn];
INT s,t;
INT mx[mxn];
INT mn[mxn];
INT ans[mxn];
bool flag[mxn]; // can go to goal
bool endpnt[mxn]; // can not go to goal
bool done[mxn]; // do dijkstra?


void dfs(INT nw,bool*lst){
	lst[nw]=1;
	for(auto&i:bktree[nw]){
		if(!lst[i])dfs(i,lst);
	}
}

void bot(INT nw){ // check 哪些點可以用機器隨機選點
	bool vis[n+1]={};
	for(INT i=1;i<=n;i++){ // 已走過的"可走點"標記為1
		if(flag[i] && done[i])vis[i]=1;
	}
	for(INT i=1;i<=n;i++){ // 為所有可能走到"死路"的點標記1，特別的是：DFS到"已走過的點"就會停下來
		if(!flag[i] && !vis[i])dfs(i,vis);
	}
	for(INT i=1;i<=n;i++){
		if(!vis[i] && !endpnt[i] && !done[i]){ // 找尋剩下"不會走到(死路)"的點，他們都多了一個選擇：讓電腦隨機選擇
			mins(ans[i],nw);
		}
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);cerr.tie(0);
	cin>>n>>m;

	for(INT i=0;i<m;i++){
		INT a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		bktree[b].push_back(a);
	}
	cin>>s>>t;

	for(INT i=0;i<=n;i++){
		ans[i]=n+10;
	}

	INT remain=n; // count 有多少可達終點的點

	dfs(t,flag);
	for(INT i=1;i<=n;i++){
		if(!flag[i]){
			remain--;
			endpnt[i]=1;
		}
	}
	mins(ans[t],0ll);
	while(remain--){ // do dijkstra
		INT best=-1,best_val=n+20;
		for(INT i=1;i<=n;i++){ // find minium ans pnt
			if(!endpnt[i] && !done[i]){
				if(best_val>ans[i]){
					best_val=ans[i];
					best=i;
				}
			}
		}
		done[best]=1;
		for(INT&i:bktree[best]){ // 鬆弛父節點（父節點多一個選擇：多付1$並走到目前這個節點
			mins(ans[i],ans[best]+1);
		}
		bot(ans[best]);


	}
	if(ans[s]>=n+1)cout<<-1<<endl;
	else cout<<ans[s]<<endl;

	return 0;
}




```
