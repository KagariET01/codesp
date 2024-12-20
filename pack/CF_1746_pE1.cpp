
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

INT guess_count=0;

bool query(vector<INT>&a){
	cout<<"? "<<a.size();
	for(auto&i:a){
		cout<<" "<<i;
	}
	cout<<endl;
	string str;
	cin>>str;
	if(str=="NO")return 0;
	else return 1;
}

bool loop_query(INT l,INT r){
	vector<INT>a;
	for(INT i=l;i<r;i++){
		a.push_back(i);
	}
	return query(a);
}

bool guess(INT x){
	cout<<"! "<<x<<endl;
	string str;
	cin>>str;
	if(str==":)")exit(0);
	else return guess_count++,0;
}

int main(){
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);cerr.tie(0);
	INT n;
	cin>>n;
	INT l1=1,r1=n/2,l2=n/2,r2=n;
	while(r2-l2+r1-l1>2){
		INT loop=r1-l1+r2-l2;
		cerr<<pit(l1)<<pit(r1)<<pit(l2)<<pit(r2)<<pit(loop)<<endl;
		for(INT i=1;i<=3;i++){
			INT mid=l1+loop*i/4;
			if(mid<=l1)mid=l1+1;
			if(mid>=r2)mid=r2-1;
			if(mid>=r1)mid=l2+mid-(r1-l1+1);
			cerr<<mid<<" ";
		}
		cerr<<endl;

		INT mid1=l1+loop/2;
		if(mid1<=l1)mid1=l1+1;
		if(mid1>=r1)mid1=l2+mid1-(r1-l1+1);
		bool q1=loop_query(l1,mid1);
		if(q1){ // left
			INT mid2=l1+loop*3/4;
			if(mid2>=r2)mid2=r2-1;
			if(mid2>r1)mid2=l2+mid2-(r1-l1+1);
			bool q2=loop_query(mid2,r2);
			if(q2){ // right
				// one is fake
				r1=mid1;
				l2=mid2;
			}else{
				if(l2<=mid2&&mid2<=r2){
					r2=mid2;
				}else{
					r1=l2=r2=mid2;
				}
			}
		}else{ //right
			INT mid2=l1+loop/4;
			if(mid2<=l1)mid2=l1+1;
			if(mid2>=r1)mid2=l2+mid2-(r1-l1+1);
			bool q2=loop_query(l1,mid2);
			if(q2){
				r1=mid2;
				l2=mid1;
			}else{
				if(l1<=mid2&&mid2<=l1){
					l1=mid2;
				}else{
					l1=r1=l2=mid2;
				}
			}
		}
	}
	guess(l1);
	guess(l2);

	return 0;
}



