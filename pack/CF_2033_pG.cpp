#include<bits/stdc++.h>
namespace ET01{ // Segment_tree
	template<typename T,typename INT=long long int>struct Segment_tree_node{
		// note:所有區間皆不包含右邊界，如(0,3)表[0,1,2]
		T v,landmark;
		INT sz=0;
		Segment_tree_node<T,INT>*l=nullptr,*r=nullptr;
		void free(){
			if(l!=nullptr)l->free();
			if(r!=nullptr)r->free();
			delete this;
		}
		void new_node(){
			if(sz<=1)return;
			if(l==nullptr && r==nullptr){
				
				INT nsz=sz/2;
				l=new Segment_tree_node<T,INT>(nsz);
				r=new Segment_tree_node<T,INT>(sz-nsz);
				l->sz=nsz;
				r->sz=sz-nsz;
			}
		}
		Segment_tree_node<T,INT>*gl(){
			if(sz<=1)return nullptr;
			new_node();
			return l;
		}
		Segment_tree_node<T,INT>*gr(){
			if(sz<=1)return nullptr;
			new_node();
			return r;
		}
		Segment_tree_node(){};
		Segment_tree_node(INT sz):sz(sz){};
	};

	template<typename T,typename INT=long long int>class Segment_tree{
		// private:
		public:
			INT sz=0;
			Segment_tree_node<T,INT>*root=nullptr;
			T landmark_reset;
			T v_reset;
			void init(INT n=0){
				sz=n;
				if(root!=nullptr)root->free();
				root=new Segment_tree_node<T,INT>(n);
				root->v=v_reset;
				root->landmark=landmark_reset;
			}
			std::function<T(T,T)>merge=[](T a,T b)->T{
				return a+b;
			};
			std::function<T(T,T,INT)>loop_update=[](T original,T update_value,INT sz)->T{ // 懶人標記更新到節點的value上
				return original+update_value*sz;
			};
			std::function<T(T,T,INT)>landmark_update=[](T original,T update_value,INT sz)->T{ // 區間修改時，更新到懶標上
				// original=原本landmark的數值
				// update_value=區間修改（增加）的數值
				// sz=此節點的大小
				return original+update_value;
			};
			void do_landmark(Segment_tree_node<T,INT>*now){
				if(now->landmark!=landmark_reset){
					now->v=loop_update(now->v,now->landmark,now->sz);
					if(now->sz!=1){
						now->l->landmark=landmark_update(now->l->landmark,now->landmark,now->l->sz);
						now->r->landmark=landmark_update(now->r->landmark,now->landmark,now->r->sz);
					}
					now->landmark=landmark_reset;
				}
			}
			void newnode(Segment_tree_node<T,INT>*now){
				if(now->sz<=1)return;
				if(now->l==nullptr && now->r==nullptr){
					// std::cerr<<"new_node"<<now->sz<<std::endl;
					now->new_node();
					now->l->landmark=landmark_reset;
					now->r->landmark=landmark_reset;
					now->l->v=v_reset;
					now->r->v=v_reset;
				}
				do_landmark(now);
			}

			void modify(
					T v,
					INT id,
					Segment_tree_node<T,INT>*now=nullptr,
					INT l=0
				){
				if(now==nullptr)now=root;
				newnode(now);
				// do_landmark(now);
				// std::cerr<<pit(now->sz)<<pit(l)<<pit(now->sz)<<std::endl;
				if(now->sz==1){
					now->v=v;
					// std::cerr<<"return"<<std::endl;
					return;
				}else{
					INT mid=l+now->l->sz;
					if(id<mid)modify(v,id,now->l,l);
					else modify(v,id,now->r,mid);
					now->v=merge(now->l->v,now->r->v);
				}
				// std::cerr<<pit(now->sz)<<pit(l)<<pit(now->sz)<<pit(now->landmark)<<std::endl;
			}
			void loop_modify(
					T v,
					INT l,INT r,
					Segment_tree_node<T,INT>*now=nullptr,
					INT nl=0
			){
				if(now==nullptr)now=root;
				newnode(now);
				if(now->sz==1){
					now->v=loop_update(now->v,v,1);
					// std::cerr<<pit(now->sz)<<pit(l)<<pit(r)<<pit(nl)<<pit(nl+now->sz)<<pit(now->v)<<pit(now->landmark)<<std::endl;
				}else if(l<=nl && l+now->sz<=r){
					now->landmark=landmark_update(now->landmark,v,now->sz);
					// std::cerr<<pit(now->sz)<<pit(l)<<pit(r)<<pit(nl)<<pit(nl+now->sz)<<pit(now->v)<<pit(now->landmark)<<std::endl;
				}else{
					INT mid=nl+now->l->sz;
					if(l<mid)loop_modify(v,l,r,now->l,nl);
					if(mid<r)loop_modify(v,l,r,now->r,mid);
					INT sl=std::max(l,nl),sr=std::min(r,nl+now->sz);
					now->v=loop_update(now->v,v,sr-sl);
					// std::cerr<<pit(now->sz)<<pit(l)<<pit(r)<<pit(nl)<<pit(mid)<<pit(nl+now->sz)<<std::endl;
				}
			}
			T query(
					INT id,
					Segment_tree_node<T,INT>*now=nullptr,
					INT l=0
			){
				if(now==nullptr)now=root;
				newnode(now);
				// do_landmark(now);
				now->v=loop_update(now->v,now->landmark,now->sz);
				if(now->sz!=1){
					now->l->landmark=landmark_update(now->l->landmark,now->landmark,now->l->sz);
					now->r->landmark=landmark_update(now->r->landmark,now->landmark,now->r->sz);
				}
				now->landmark=landmark_reset;
				if(now->sz==1){
					return now->v;
				}else{
					INT mid=l+now->l->sz;
					if(id<mid)return query(id,now->l,l);
					else return query(id,now->r,mid);
				}
			}
			T operator[](INT id){
				return query(id);
			}

			// typedef std::pair<Segment_tree_node<T,INT>*,INT> PSI;

			// stack<pair<PSI>dbg_st;

			T loop_query(
					INT l,INT r,
					Segment_tree_node<T,INT>*now=nullptr,
					INT nl=0
			){
				if(now==nullptr)now=root;
				newnode(now);
				// do_landmark(now);
				now->v=loop_update(now->v,now->landmark,now->sz);
				if(now->sz!=1){
					now->l->landmark=landmark_update(now->l->landmark,now->landmark,now->l->sz);
					now->r->landmark=landmark_update(now->r->landmark,now->landmark,now->r->sz);
				}
				now->landmark=landmark_reset;
				if(now->sz==1){
					// std::cerr<<pit(now->sz)<<pit(l)<<pit(r)<<pit(nl)<<pit(nl+now->sz)<<pit(now->v)<<std::endl;
					return now->v;
				}else if(l<=nl && nl+now->sz<=r){
					// std::cerr<<pit(now->sz)<<pit(l)<<pit(r)<<pit(nl)<<pit(nl+now->sz)<<pit(now->v)<<std::endl;
					return now->v;
				}else{
					INT mid=nl+now->l->sz;
					T res;
					bool flag=false;
					if(l<mid){
						res=loop_query(l,r,now->l,nl);
						flag=1;
					}
					if(mid<r){
						if(flag)res=merge(res,loop_query(l,r,now->r,mid));
						else res=loop_query(l,r,now->r,mid);
					}
					// std::cerr<<pit(now->sz)<<pit(l)<<pit(r)<<pit(nl)<<pit(mid)<<pit(nl+now->sz);
					// std::cerr<<pit(res)<<std::endl;
					return res;
				}
			}
	};

	template<typename T,typename INT>std::ostream&operator<<(std::ostream&ou,const Segment_tree_node<T,INT>&a){
		std::stack<std::pair<const Segment_tree_node<T,INT>*,INT>>st;
		st.push(std::make_pair(&a,0));
		while(!st.empty()){
			const Segment_tree_node<T,INT>*now=st.top().first;
			INT d=st.top().second;
			st.pop();
			for(INT i=0;i<d;i++)ou<<"  ";
			ou<<"{v:"<<now->v<<",landmark:"<<now->landmark<<",sz:"<<now->sz<<"}"<<std::endl;
			if(now->r!=nullptr)st.push(std::make_pair(now->r,d+1));
			if(now->l!=nullptr)st.push(std::make_pair(now->l,d+1));
		}
		return ou;
	}
};

// #include"ET01.h"
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

const INT mxn=2e5+5;

#define PPIIPII pair<PII,PII>

// INT n;
// INT q;
vector<vector<INT>>tree;
vector<INT>parent;
vector<vector<PII>>query;
vector<INT>ans;
vector<INT>h;
vector<PPIIPII>deep;

ET01::Segment_tree<INT>st;

void get_h(INT nw){
	for(INT&i:tree[nw]){
		if(parent[nw]==i)continue;
		parent[i]=nw;
		h[i]=h[nw]+1;
		get_h(i);
	}
}

void get_deep(INT nw){
	deep[nw]=PPIIPII(
		PII(0,nw),
		PII(0,nw)
	);
	// cerr<<pit(nw)<<"    "<<pit(deep[nw])<<endl;
	for(INT&i:tree[nw]){
		if(parent[nw]==i)continue;
		get_deep(i);
		PII nwp=PII(deep[i].F.F+1,i);
		if(nwp>deep[nw].F)swap(nwp,deep[nw].F);
		if(nwp>deep[nw].S)swap(nwp,deep[nw].S);
		// cerr<<pit(nw)<<pit(i)<<pit(deep[nw])<<endl;
	}
}

void get_ans(INT nw){
	// cerr<<pit(nw)<<pit(h[nw])<<" st:";
	// for(INT i=0;i<st.sz;i++){
	// 	cerr<<st.query(i)<<" ";
	// }
	// cerr<<endl;
	for(PII&i:query[nw]){
		ans[i.S]=deep[nw].F.F;
		maxs(ans[i.S],st.loop_query(max(0ll,h[nw]-i.F),h[nw]+1)+h[nw]);
		// cerr<<pit(i)<<pit(ans[i.S])<<pit(h[nw]-i.F)<<pit(h[nw])<<endl;
	}
	for(INT&i:tree[nw]){
		if(parent[nw]==i)continue;
		if(i==deep[nw].F.S){
			st.modify(max(deep[nw].S.F-h[nw],st[h[nw]]),h[nw]);
		}else{
			st.modify(max(deep[nw].F.F-h[nw],st[h[nw]]),h[nw]);
		}
		get_ans(i);
		st.modify((INT)(-1e9-7),h[nw]);
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);cerr.tie(0);
	INT t;
	cin>>t;
	st.merge=[](INT a,INT b){
		return max(a,b);
	};
	while(t--){
		INT n;
		cin>>n;
		tree.clear();
		tree.resize(n+1,vector<INT>(0));
		parent.clear();
		parent.resize(n+1,-1);
		query.clear();
		query.resize(n+1,vector<PII>(0));
		h.clear();
		h.resize(n+1,0);
		deep.clear();
		deep.resize(n+5,PPIIPII(MP(0,0),MP(0,0)));
		st.init(n+10);
		for(INT i=0;i<n+1;i++){
			st.modify((INT)(-1e9-7),i);
		}

		for(INT i=1;i<n;i++){
			INT a,b;
			cin>>a>>b;
			a--,b--;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		get_h(0);
		get_deep(0);
		INT q;
		cin>>q;
		ans.clear();
		ans.resize(q+5,0);
		for(INT i=0;i<q;i++){
			INT v,k;
			cin>>v>>k;
			v--;
			query[v].push_back(PII(k,i));
		}

		// cerr<<pit(parent)<<endl;
		// cerr<<pit(h)<<endl;
		// cerr<<pit(deep)<<endl;
		// cerr<<pit(query)<<endl;


		get_ans(0);

		for(INT i=0;i<q;i++){
			if(i)cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}




