

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

const INT mxn=2e5;

struct seg{
	seg *l=nullptr;
	seg *r=nullptr;
	INT sum=0;
	void init(){
		l=nullptr;
		r=nullptr;
		sum=0;
	}
};

ostream&operator<<(ostream&ou,seg *s){
	if(s->l==nullptr)return ou<<s->sum<<" ";
	else return ou<<s->l<<s->r;
}

seg *tl[mxn+1];
INT n=0;//原始資料的大小，[1,2,2]==>  n=3 [2,1,4,3,3]==>  n=5
INT len;//不同數字的數量，[1,2,2]==>len=2 [2,1,4,3,3]==>len=4
vector<INT>a,b,c;
map<INT,INT>mp;
// seg[i:j]==>第i:j小的數字有多少個

seg *init(INT sz=0){//初始化
	seg *re=new(seg);
	if(sz<=1)return re;
	INT ls=sz/2;
	INT rs=sz-ls;
	re->l=init(ls);
	re->r=init(rs);
	return re;
}

seg *modify(INT k,INT l,INT r,seg *root){//改值
	//k=位置
	seg *re=new(seg);
	//cout<<pit(k)<<pit(l)<<pit(r);
	re->l=root->l;
	re->r=root->r;
	re->sum=root->sum+1;
	if(r-l<=1)return re;
	INT mid=(r-l)/2+l;
	//cout<<pit(mid)<<endl;
	if(l<=k&&k<mid)re->l=modify(k,l,mid,root->l);
	else re->r=modify(k,mid,r,root->r);
	return re;
}

INT query(seg *root1,seg *root2,INT k,INT l,INT r){
	//root1,root2:seg_tree root
	//k:第k大
	//l,r:seg_tree範圍
	//cout<<pit(k)<<pit(l)<<pit(r)<<pit(root1->sum)<<pit(root2->sum)<<endl;
	//cout<<pit(root1)<<endl;
	//cout<<pit(root2)<<endl;
	if(r-l<=1)return l;
	INT lsz=root2->l->sum-root1->l->sum;
	//cerr<<lsz<<endl;
	INT mid=(r-l)/2+l;
	if(k<=lsz)return query(root1->l,root2->l,k,l,mid);
	else return query(root1->r,root2->r,k-lsz,mid,r);
}

void solve(){
	INT m;
	cin>>n>>m;
	a.resize(n);
	cin>>a;
	b=a;
	sort(b);
	len=1;
	c.push_back(b[0]);
	mp[b[0]]=0;
	for(INT i=1;i<n;i++){
		if(b[i]!=b[i-1]){
			mp[b[i]]=len;
			c.push_back(b[i]);
			len++;
		}
	}
	//cout<<pit(mp)<<pit(c)<<endl;
	tl[0]=init(len);
	for(INT i=0;i<n;i++){
		tl[i+1]=modify(mp[a[i]],0,len,tl[i]);
		//cout<<"add "<<mp[a[i]]<<endl;
		//cout<<tl[i+1]<<endl;
	}
	
	while(m--){
		INT l,r,kk;
		cin>>l>>r>>kk;
		//kk--;
		cout<<c[query(tl[l-1],tl[r],kk,0,len)]<<endl;
	}
	
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	solve();
	return 0;
}



