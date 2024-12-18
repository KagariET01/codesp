# [`TIOJ 1063`](https://tioj.ck.tp.edu.tw/problems/1063) 最大矩形
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

namespace ET01{
	string list_st="[";
	string list_sep=",";
	string list_ed="]";
	string map_st="{";
	string map_sep1=":";
	string map_sep2=",";
	string map_ed="}";
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
		return ou<<list_st<<p.first<<list_sep<<p.second<<list_ed;
	}
	template<typename T1,typename T2>istream&operator>>(istream&in,pair<T1,T2>&p){
		return in>>p.first>>p.second;
	}
	
	//deque
	template<typename T1,typename T2>ostream&operator<<(ostream&ou,deque<T1,T2>que){
		bool o=0;
		ou<<list_st;
		for(T1(i):que){
			if(o)ou<<list_sep;
			ou<<i;
			o=1;
		}
		return(ou<<list_ed);
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
		ou<<list_st;
		while(!que.empty()){
			if(o)ou<<list_sep;
			ou<<que.front();
			o=1;
			que.pop();
		}
		return(ou<<list_ed);
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
		ou<<list_st;
		for(const T&i:vec){
			if(o)ou<<list_sep;
			ou<<i;
			o=1;
		}
		return(ou<<list_ed);
	}
	
	//array
	template<typename T,std::size_t N>ostream&operator<<(ostream&ou,array<T,N>&a){
		bool o=0;
		ou<<list_st;
		for(T&i:a){
			if(o)ou<<list_sep;
			ou<<i;
			o=1;
		}
		return ou<<list_ed;
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
		ou<<map_st;
		for(pair<T1,T2>i:mp){
			if(o)ou<<map_sep2;
			ou<<i.first<<map_sep1<<i.second;
			o=1;
		}
		return(ou<<map_ed);
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
	
}

using namespace ET01;



/*  ****************************************************  **

    ____ ___  ____  _____   ____ _____  _    ____ _____
   / ___/ _ \|  _ \| ____| / ___|_   _|/ \  |  _ \_   _|
  | |  | | | | | | |  _|   \___ \ | | / _ \ | |_) || |
  | |__| |_| | |_| | |___   ___) || |/ ___ \|  _ < | |
   \____\___/|____/|_____| |____/ |_/_/   \_\_| \_\|_|
  
**  ****************************************************  */

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);cerr.tie(0);
	INT n,m;
	cin>>n>>m;
	vector<queue<INT>>que(n,queue<INT>());
	for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
			if(read(INT)==0){
				que[i].push(j);
			}
		}
		que[i].push(m);
	}
	// cerr<<que<<endl;
	INT ans=0;
	INT mxu=0,mxd=0,mxl=0,mxr=0;
	for(INT i=0;i<m;i++){
		// cerr<<pit(i)<<endl;
		for(INT j=0;j<n;j++){
			if(que[j].front()<i)que[j].pop();
		}
		stack<PII>st;
		for(INT j=0;j<n;j++){
			INT it=j;
			while(!st.empty() && st.top().F>=(que[j].front()-i)){
				it=st.top().S;
				// cerr<<pit(it)<<pit(st.top())<<pit(que[j].front())<<endl;
				if(ans<(j-it)*st.top().F){
					ans=(j-it)*st.top().F;
					mxu=it;
					mxd=j;
					mxl=i;
					mxr=i+st.top().F;
				}
				st.pop();
			}
			st.push(PII(que[j].front()-i,it));
			// cerr<<pit(j)<<pit(st)<<endl;
		}
		while(!st.empty()){
			if(ans<(n-st.top().S)*st.top().F){
				ans=(n-st.top().S)*(st.top().F);
				mxu=st.top().S;
				mxd=n;
				mxl=i;
				mxr=i+st.top().F;
			}
			st.pop();
		}
	}
	cout<<ans<<endl;
	cerr<<mxu<<" "<<mxd<<" "<<mxl<<" "<<mxr<<endl;

	return 0;
}




```
