
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






/*  ******************************************************  **

      ____ ___  ____  _____   ____ _____  _    ____ _____
     / ___/ _ \|  _ \| ____| / ___|_   _|/ \  |  _ \_   _|
    | |  | | | | | | |  _|   \___ \ | | / _ \ | |_) || |
    | |__| |_| | |_| | |___   ___) || |/ ___ \|  _ < | |
     \____\___/|____/|_____| |____/ |_/_/   \_\_| \_\|_|
  
**  ******************************************************  */

struct str{
	INT v=0;
	str *l=nullptr;
	str *r=nullptr;
	str*gl(){
		if(l!=nullptr)return l;
		else return l=new(str);
	}
	str*gr(){
		if(r!=nullptr)return r;
		else return r=new(str);
	}
};

INT n,m;

const INT mxn=1e5;
const INT mxa=1e9+7;

str *root[mxn+1];

str*init(){
	str*nw=new(str);
	return nw;
}

str*build(INT id,INT l,INT r,str*orig){
	//cout<<pit(id)<<pit(l)<<pit(r)<<endl;
	str*nw=new(str);
	if(r-l<=1){
		nw->v=orig->v+1;
		return nw;
	}else{
		nw->l=orig->l;
		nw->r=orig->r;
		nw->v=orig->v+1;
		INT mid=(r-l)/2+l;
		if(l<=id&&id<mid)nw->l=build(id,l,mid,orig->gl());
		else nw->r=build(id,mid,r,orig->gr());
		return nw;
	}
}

void modify(INT id,INT v,INT l,INT r,str*root){
	root->v+=v;
	cout<<"modify: "<<pit(id)<<pit(v)<<pit(l)<<pit(r)<<pit(root->v)<<endl;
	if(r-l>1){
		INT mid=(r-l)/2+l;
		if(l<=id&&id<mid)modify(id,v,l,mid,root->gl());
		else modify(id,v,mid,r,root->gr());
	}
}

INT query(str*root1,str*root2,INT k,INT l,INT r){
	cout<<pit(k)<<pit(l)<<pit(r)<<"  "<<pit(root2->gl()->v)<<pit(root1->gl()->v)<<endl;
	if(r-l<=1)return l;
	else{
		INT lsz=root2->gl()->v - root1->gl()->v;
		INT mid=(r-l)/2+l;
		if(k<=lsz)return query(root1->gl(),root2->gl(),k,l,mid);
		else return query(root1->gr(),root2->gr(),k-lsz,mid,r);
	}
}



int main(){
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	root[0]=init();
	cin>>n>>m;
	vector<INT>a(n);
	cin>>a;
	for(INT i=0;i<n;i++){
		root[i+1]=build(a[i],0,mxa,root[i]);
	}
	while(m--){
		char op;
		cin>>op;
		if(op=='Q'){
			INT l,r,k;
			cin>>l>>r>>k;
			cout<<query(root[l-1],root[r],k,0,mxa)<<endl;
		}else{
			INT x,y;
			cin>>x>>y;
			cout<<"============扣"<<a[x-1]<<"============"<<endl;
			modify(a[x-1],-1,0,mxa,root[x]);
			a[x-1]=y;
			cout<<"============加"<<a[x-1]<<"在"<<x<<"============"<<endl;
			modify(a[x-1],1,0,mxa,root[x]);
			cout<<pit(a)<<endl;
		}
	}
	return 0;
}



