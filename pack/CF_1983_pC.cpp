
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

struct ansdta{
	INT al=0;
	INT ar=0;
	INT bl=0;
	INT br=0;
	INT cl=0;
	INT cr=0;
	ansdta(INT a,INT b,INT c,INT d,INT e,INT f){
		al=a;
		ar=b;
		bl=c;
		br=d;
		cl=e;
		cr=f;
	}
	ansdta(){
	}
	bool check(){
		if(al==-1 ||
				ar==-1 ||
				bl==-1 ||
				br==-1 ||
				cl==-1 ||
				cr==-1)return 0;
		return 1;
	}
};

ansdta imp(-1,-1,-1,-1,-1,-1);

ansdta solve(vector<INT>&a,vector<INT>&b,vector<INT>&c,INT goal,INT n){
	INT i=0;
	ansdta re;

	INT anw=0;
	re.al=i;
	while(i<=n && anw<goal){
		if(i==n || i==-1){
			i=-1;
			break;
		}
		anw+=a[i];
		i++;
	}
	re.ar=i;

	INT bnw=0;
	re.bl=i;
	while(i<=n && bnw<goal){
		if(i==n || i==-1){
			i=-1;
			break;
		}
		bnw+=b[i];
		i++;
	}
	re.br=i;

	INT cnw=0;
	re.cl=i;
	while(i<=n && cnw<goal){
		if(i==n || i==-1){
			i=-1;
			break;
		}
		cnw+=c[i];
		i++;
	}
	re.cr=i;
	if(re.cr!=-1)re.cr=n;
	return re;

}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);cerr.tie(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		vector<INT>a(n),b(n),c(n);
		cin>>a>>b>>c;
		INT goal=0;
		for(INT&i:a)goal+=i;
		goal=goal/3+(goal%3?1:0);
		ansdta ans;

		ans=solve(a,b,c,goal,n);
		if(ans.check()){
			cout<<ans.al+1<<" "<<ans.ar<<" ";
			cout<<ans.bl+1<<" "<<ans.br<<" ";
			cout<<ans.cl+1<<" "<<ans.cr<<endl;
			continue;
		}

		ans=solve(a,c,b,goal,n);
		if(ans.check()){
			cout<<ans.al+1<<" "<<ans.ar<<" ";
			cout<<ans.cl+1<<" "<<ans.cr<<" ";
			cout<<ans.bl+1<<" "<<ans.br<<endl;
			continue;
		}
		ans=solve(b,a,c,goal,n);
		if(ans.check()){
			cout<<ans.bl+1<<" "<<ans.br<<" ";
			cout<<ans.al+1<<" "<<ans.ar<<" ";
			cout<<ans.cl+1<<" "<<ans.cr<<endl;
			continue;
		}
		ans=solve(b,c,a,goal,n);
		if(ans.check()){
			cout<<ans.cl+1<<" "<<ans.cr<<" ";
			cout<<ans.al+1<<" "<<ans.ar<<" ";
			cout<<ans.bl+1<<" "<<ans.br<<endl;
			continue;
		}
		ans=solve(c,a,b,goal,n);
		if(ans.check()){
			cout<<ans.bl+1<<" "<<ans.br<<" ";
			cout<<ans.cl+1<<" "<<ans.cr<<" ";
			cout<<ans.al+1<<" "<<ans.ar<<endl;
			continue;
		}
		ans=solve(c,b,a,goal,n);
		if(ans.check()){
			cout<<ans.cl+1<<" "<<ans.cr<<" ";
			cout<<ans.bl+1<<" "<<ans.br<<" ";
			cout<<ans.al+1<<" "<<ans.ar<<endl;
			continue;
		}
		
		cout<<-1<<endl;
		
	}
	return 0;
}



