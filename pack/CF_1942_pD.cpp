

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

//vector
template<typename T>istream&operator>>(istream&in,vector<T>&vec){
	for(T&i:vec)in>>i;
	return in;
}
template<typename T>ostream&operator<<(ostream&ou,vector<T>vec){
	bool o=0;
	ou<<"";
	for(T(i):vec){
		if(o)ou<<" ";
		ou<<i;
		o=1;
	}
	return(ou<<"");
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

//deque
template<typename T1,typename T2>ostream&operator<<(ostream&ou,deque<T1,T2>st){
	bool o=0;
	ou<<"{";
	while(!st.empty()){
		if(o)ou<<",";
		ou<<st.front();
		st.pop_front();
	}
	return(ou<<"}");
}

//priority_queue
template<typename T1,typename T2,typename T3>ostream&operator<<(ostream&ou,priority_queue<T1,T2,T3>que){
	deque<T1>st;
	while(!que.empty()){
		st.push_front(que.top());
		que.pop();
	}
	return(ou<<st);
}








int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n,k;
		cin>>n>>k;
		vector<vector<INT>>vec(n,vector<INT>(0));
		for(INT(i)=0;i<n;i++){
			vec[i].resize(n-i);
		}
		cin>>vec;
		struct cmp{
			bool operator()(PII(a),PII(b)){
				if(a.F!=b.F)return a.F<b.F;
				else return a.S>b.S;
			}
		};
		priority_queue<PII,vector<PII>,cmp>que;//{nowv,nowlv}
		que.push(PII(0,0));
		priority_queue<INT>ans;
		while(!que.empty()){
			PII(now)=que.top();
			que.pop();
			//cerr<<pit(now)<<endl;
			if(now.S>=n){
				//cerr<<pit(now)<<endl;
				ans.push(now.F);
				if(ans.size()>=k)break;
			}else{
				//cerr<<"\t";
				for(INT(i)=0;i<n-now.S;i++){
					//cerr<<PII(now.F+vec[now.S][i],now.S+i+2)<<"  ";
					que.push(PII(now.F+vec[now.S][i],now.S+i+2));
				}
				//cerr<<endl;
				que.push(PII(now.F,now.S+1));
			}
			//cerr<<que<<endl;
		}
		vector<INT>ansvec;
		while(!ans.empty()){
			ansvec.push_back(ans.top());
			ans.pop();
		}
		cout<<ansvec<<endl;
	}
	return 0;
}



