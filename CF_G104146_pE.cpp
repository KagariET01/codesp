

#include<bits/stdc++.h>
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
	ou<<"";
	for(T(i):vec){
		if(o)ou<<" ";
		ou<<i;
		o=1;
	}
	return(ou<<"");
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


void bugmk(){
	int zero=0;
	int a=10;
	int b=0;
	b=a/zero;
	while(1);

}

const INT n=15;

INT w[n];
INT wtt[n];

INT t;
INT nwt;
void init(){
	w[0]=wtt[0]=2;
	for(INT i=1;i<n;i++){
		w[i]=w[i-1]*3;
		wtt[i]=wtt[i-1]+w[i];
	}
}

INT qul[n];//query_list


void query(INT v,INT nwp=n){
	if(nwp==n){
		for(INT i=0;i<n;i++){
			qul[i]=0;
		}
		nwp--;
	}
	if(v<0){
		query(-v,nwp);
		for(INT i=0;i<=nwp;i++){
			qul[i]=-qul[i];
		}
	}else if(v==0)return;
	else{
		if(nwp){
			if(abs(v-w[nwp])<=wtt[nwp-1])qul[nwp]=1;
			else if(abs(v)<=wtt[nwp-1])qul[nwp]=0;
			else qul[nwp]=-1;
			query(v-w[nwp]*qul[nwp],nwp-1);
		}else{
			if(v>0)qul[nwp]=1;
			else qul[nwp]=-1;
		}
	}
	
}

bool getA(bool ext=false,INT qq=-1){
	if(ext){
		cout<<"VERDICT"<<endl;
		cout<<"HEAVY"<<endl;
	}else if(qq!=-1){
		cout<<"VERDICT"<<endl;
		cout<<"EXACT"<<endl;
		cout<<qq<<endl;
	}else{
		INT ans=0;
		for(INT i=0;i<n;i++){
			ans+=w[i]*qul[i];
		}
		cout<<"VERDICT"<<endl;
		cout<<"EXACT"<<endl;
		cout<<ans<<endl;
	}
	string restr;
	cin>>restr;
	
	if(restr==":)"){
		return 1;
	}else if(restr==">:("){
		return 0;
	}else return 0;
}

INT outer(){//1=心臟輕 -1=心臟重 0=等重
	vector<INT>r,l;
	l.push_back(0);
	for(INT i=0;i<n;i++){
		if(qul[i]==1)r.push_back(i+1);
		else if(qul[i]==-1)l.push_back(i+1);
	}
	cout<<"WEIGH"<<endl;
	cout<<l.size()<<endl;
	cout<<l<<endl;
	cout<<r.size()<<endl;
	cout<<r<<endl;
	string res;
	cin>>res;
	if(res=="<"){
		return 1;
	}else if(res==">"){
		return -1;
	}else if(res=="="){
		return 0;
	}else{
		return -2;
	}

}

bool solve(){
		if(nwt==4)bugmk();//3 successful
	query(wtt[n-1]);
	INT rrr=outer();
	if(rrr==-1){
		return getA(1);
	}else if(rrr==-2){
		return 0;
	}else if(rrr==0){
		return getA(0,wtt[n-1]);
	}


	INT l=0,r=wtt[n-1];
	r/=w[0];
	r++;
	while(l<r){
		
		INT mid=(r-l)/2+l;
		query(mid*w[0]);
		INT res=outer();
		if(res==1){
			r=mid;
		}else if(res==-1){
			l=mid+1;
		}else if(res==0){
			return getA(0,mid*w[0]);
		}else return 0;
	}
	query(l*w[0]);
	INT res1=outer();
	query(l*w[0]-w[0]);
	INT res2=outer();
	if(res1==0){
		return getA(0,l*w[0]);
	}else if(res2==0){
		return getA(0,l*w[0]-w[0]);
	}else{
		return getA(0,l*w[0]-1);
	}

}

int main(){
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	init();
	cout<<n<<endl;
	for(INT i=0;i<n;i++){
		if(i)cout<<" ";
		cout<<w[i];
	}
	cout<<endl;
	cout<<wtt[n-1]<<endl;
	cin>>t;
	for(nwt=0;nwt<t;nwt++){
		if(!solve())return 0;
	}
	return 1;
}



