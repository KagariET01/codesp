

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
template<typename T1,typename T2,typename T3>pair<T1,T2>operator/(pair<T1,T2>a,T3 b){
	return pair<T1,T2>(a.F/b,a.S/b);
}
template<typename T1,typename T2,typename T3>pair<T1,T2>operator/=(pair<T1,T2>&a,T3 b){
	return a=a/b;
}

template<typename T1,typename T2>ostream&operator<<(ostream&ou,pair<T1,T2>p){
	return ou<<"{"<<p.first<<","<<p.second<<"}";
}
template<typename T1,typename T2>istream&operator>>(istream&in,pair<T1,T2>&p){
	return in>>p.first>>p.second;
}

//deque
template<typename T1,typename T2>ostream&operator<<(ostream&ou,deque<T1,T2>&que){
	bool o=0;
	ou<<"{";
	for(T1(i):que){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return(ou<<"}");
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
	ou<<"{";
	while(!que.empty()){
		if(o)ou<<",";
		ou<<que.front();
		o=1;
		que.pop();
	}
	return(ou<<"}");
}

//priority_queue
template<typename T1,typename T2,typename T3>ostream&operator<<(ostream&ou,priority_queue<T1,T2,T3>pq){
	deque<T1>dq;
	while(!pq.empty()){
		dq.push_front(pq.top());
		pq.pop();
	}
	return(ou<<pq);
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

//array
template<typename T,std::size_t N>ostream&operator<<(ostream&ou,array<T,N>&a){
	bool o=0;
	ou<<"{";
	for(T&i:a){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return ou<<"}";
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






const INT mxn=500005;
vector<INT>tre[mxn];
vector<INT>flag;

#define PIPII pair<INT,PII>
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,m;
	cin>>n>>m;
	vector<PIPII>vec(m);
	for(INT i=0;i<m;i++){
		INT a,b,p;
		cin>>a>>b>>p;
		a--,b--;
		vec[i]=PIPII(p,PII(a,b));
	}
	sort(vec.begin(),vec.end(),greater<PIPII>());
	//cerr<<vec<<endl;
	function<bool(INT,vector<INT>&)>dfs;
	dfs=[&](INT nw,vector<INT>&flag)->bool{//dfs fn
		for(INT&i:tre[nw]){
			if(flag[i]){
				if(flag[i]==flag[nw])return 0;
			}else{
				flag[i]=3-flag[nw];
				if(!dfs(i,flag))return 0;
			}
		}
		return 1;
	};

	auto checker=[](INT&n,vector<PIPII>&vec,INT&lim,function<bool(INT,vector<INT>&)>&dfs)->bool{//透過DFS檢查是否為二分圖
		for(INT i=0;i<n;i++){
			tre[i].clear();
		}
		for(PIPII&i:vec){//邊權>lim者才需要考慮二分圖，<=lim者則不需考慮
			if(i.F<=lim)break;
			tre[i.S.F].push_back(i.S.S);
			tre[i.S.S].push_back(i.S.F);
		}
		flag.clear();
		flag.resize(n);
		for(INT i=0;i<n;i++){
			if(!flag[i]){
				flag[i]=1;
				if(!dfs(i,flag))return false;
			}
		}
		return true;
	};

	INT l=0,r=1e9+7;
	while(l<r){
		INT mid=(r-l)/2+l;
		if(checker(n,vec,mid,dfs)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	cout<<l<<endl;
	return 0;
}



