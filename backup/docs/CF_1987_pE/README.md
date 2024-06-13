# [`CF 1987 pE`](https://codeforces.com/contest/1987/problem/E) Wonderful Tree!
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
template<typename T>ostream&operator>>(ostream&ou,T a){
	return ou<<a;
}
template<typename T>istream&operator<<(istream&in,T a){
	return in>>a;
}

template<typename T>void sort(vector<T>&vec){
	sort(vec.begin(),vec.end());
}






/*  ****************************************************  **

    ____ ___  ____  _____   ____ _____  _    ____ _____
   / ___/ _ \|  _ \| ____| / ___|_   _|/ \  |  _ \_   _|
  | |  | | | | | | |  _|   \___ \ | | / _ \ | |_) || |
  | |__| |_| | |_| | |___   ___) || |/ ___ \|  _ < | |
   \____\___/|____/|_____| |____/ |_/_/   \_\_| \_\|_|
  
**  ****************************************************  */

struct tree{
	INT a=0;// what Q mean
	INT minlen=0;// 子樹最短深度
	vector<tree*>sub;// 子節點
	INT cost=0;// 目前花費
	vector<INT>spcost;// 若想要增加此節點的數字，可以用i點購買spcost[i]次數字增加機會
	INT id=0;
	// 也就是說如果spcost[i]>0，則可以只使用i點，讓此數值+1
	void init(INT i){
		a=0;
		minlen=0;
		sub.clear();
		cost=0;
		spcost.clear();
		id=i;
	}
	void solve(){
		//cerr<<pit(id)<<endl;

		minlen=1e9+7;
		if(sub.size()<=0)minlen=0;
		cost=0;
		spcost.clear();
		INT alltot=0;
		for(auto&i:sub){
			i->solve();
			mins(minlen,i->minlen);
			cost+=i->cost;
			vector<INT>&spc2=i->spcost;
			spcost.resize(max(spcost.size(),spc2.size()+1));
			for(INT i=0;i<spc2.size();i++){
				spcost[i+1]+=spc2[i];
			}

			alltot+=i->a;
		}
		spcost.resize(max(minlen,1ll));
		INT i=0;
		while(a>alltot){
			INT need=a-alltot;
			if(i==minlen){
				cost+=need*minlen;
				alltot+=need;
				break;
			}
			INT buy=min(need,spcost[i]);
			cost+=buy*(i);
			spcost[i]-=buy;
			alltot+=buy;
			i++;
		}
		spcost[0]+=alltot-a;
		minlen++;
		//cerr<<pit(a)<<endl;
		//cerr<<pit(minlen)<<endl;
		//cerr<<pit(cost)<<endl;
		//cerr<<pit(spcost)<<endl;
		//cerr<<pit(alltot)<<endl;
		//cerr<<"endl"<<endl;
	}
};


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		tree* te[n];
		for(auto&i:te)i=new tree;
		for(INT i=0;i<n;i++)te[i]->init(i);
		for(auto&i:te)i->a=read(INT);
		for(INT i=1;i<n;i++){
			INT rt=read(INT);
			rt--;
			te[rt]->sub.push_back(te[i]);
		}
		
		te[0]->solve();
		cout<<te[0]->cost<<endl;
	}
	return 0;
}




```
