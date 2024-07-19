
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

// const INT mxc=50;
// INT c,t;
// vector<INT> p(mxc);// stay_fee
// vector<INT> s(mxc);// sell_fee
// vector<INT> n(mxc);// get
// vector<vector<INT>> r(mxc,vector<INT>(mxc));

// vector<vector<INT>> dp(mxc,vector<INT>(mxc*mxc,-1));// i=上一個出售地 j=可賣出的數量 dp[i][j]=價格
// 特別的，dp[i][j]=-1表不可能
// vector<INT> pt(mxc);
// vector<INT> nt(mxc);
// vector<vector<INT>> rt(mxc,vector<INT>(mxc));


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);cerr.tie(0);
	INT c,t;
	cin>>c>>t;

	vector<INT> p(c+1);// stay_fee
	vector<INT> s(c+1);// sell_fee
	vector<INT> n(c+1);// get
	vector<vector<INT>> r(c+1,vector<INT>(c+1));

	//vector<vector<INT>> dp(c+1,vector<INT>(c*40+40,-1));// i=上一個出售地 j=可賣出的數量 dp[i][j]=價格
	// 特別的，dp[i][j]=-1表不可能
	vector<INT> pt(c+1);
	vector<INT> nt(c+1);
	vector<vector<INT>> rt(c+1,vector<INT>(c+1));



	for(INT i=1;i<=c;i++){
		cin>>p[i];
		pt[i]=pt[i-1]+p[i];
	}
	for(INT i=1;i<=c;i++){
		cin>>s[i];
	}
	for(INT i=1;i<=c;i++){
		cin>>n[i];
		nt[i]=nt[i-1]+n[i];
	}
	INT nat=nt[c];
	for(INT i=1;i<=c;i++){
		for(INT j=1;j<=i;j++){
			cin>>r[i][j];
			rt[i][j]=rt[i][j-1]+r[i][j];
		}
	}
	vector<vector<INT>>dp(c+1,vector<INT>(nat+1,-1));
	dp[0][0]=0;
	for(INT i=1;i<=c;i++){ // （賣之後）最後賣出的城市
		for(INT j=0;j<=nat;j++){ // （賣之前）已賣出
			for(INT k=0;k<i;k++){ //（賣之前）最後賣出的城市
				if(dp[k][j]==-1)continue;
				// 決定賣出
				INT stay_fee=(nt[c]-nt[k])*(pt[i]-pt[k]);
				INT sell_fee=(nt[i]-nt[k])*s[i];
				INT get=rt[i][i]-rt[i][k];
				if(dp[i][j+get]==-1)dp[i][j+get]=dp[k][j]+stay_fee+sell_fee;
				mins(dp[i][j+get],dp[k][j]+stay_fee+sell_fee);
				if(dp[i][j+get]>t){ // 花費超過上限
					dp[i][j+get]=-1;
				}

			}
		}
	}
	INT ans=-1;
	for(INT i=0;i<=c;i++){
		for(INT j=0;j<=nat;j++){
			if(dp[i][j]==-1)continue;
			INT msf=(nt[c]-nt[i])*(pt[c]-pt[i]);
			INT fee=dp[i][j]+msf;
			if(fee<=t){
				maxs(ans,j);
			}
		}
	}
	cout<<ans<<endl;
	//cerr<<pit(dp)<<endl;
	return 0;
}



