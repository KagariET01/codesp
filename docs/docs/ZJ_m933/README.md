# [`APCS 2024 01 pC`]( ) [`ZJ m933`](https://zerojudge.tw/ShowProblem?problemid=m933) 邏輯電路
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
	//ou<<"[";
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

function<bool(bool,bool)>
	o_self=[](bool a,bool b){return(a);},
	o_not=[](bool a,bool b){return(!a);},
	o_or=[](bool a,bool b){return(a|b);},
	o_and=[](bool a,bool b){return(a&b);},
	o_xor=[](bool a,bool b){return(a^b);};



struct pnt{

	//root node
	pnt *lp=nullptr;
	pnt *rp=nullptr;
	
	INT ld=0;
	INT rd=0;

	//value get
	bool lg=false;
	bool rg=false;
	bool meg=false;
	//false:not get
	//true:get

	//value
	bool l=false;
	bool r=false;
	bool me=false;

	INT delay=0;

	//operator
	function<bool(bool,bool)>*op=nullptr;

	void add_link(pnt*p){
		if(lp==nullptr && lg==false)lp=p;
		else rp=p;
	}

	void set_value(bool v){
		if(lp==nullptr && lg==false)l=v,lg=1;
		else r=v,rg=1;
	}

	void set_ans(bool v){
		me=v;
		meg=1;
	}

	void passby(){
		op=&o_or;
		rg=1;
		r=0;
	}

	bool get_v(){
		if(meg){
			return(me);
		}
		//cerr<<"o(";
		if(!lg){
			l=lp->get_v();
			ld=lp->delay;
			lg=true;
		}
		//cerr<<l;
		//cerr<<",";
		if(!rg){
			r=rp->get_v();
			rd=rp->delay;
			rg=true;
		}
		//cerr<<r;
		//cerr<<")->";
		me=(*op)(l,r);
		//cerr<<me;
		delay+=max(ld,rd);
		meg=true;
		return me;
	}
};

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	INT p,q,r,m;
	cin>>p>>q>>r>>m;
	pnt *v[p+q+r];
	for(auto&i:v)i=new pnt;
	for(INT i=0;i<p;i++){
		v[i]->set_ans(read(INT));
		//cerr<<i<<"->"<<v[i]->get_v()<<endl;
	}
	//cerr<<"st_pnt_seted"<<endl;
	for(INT i=p;i<p+q;i++){
		v[i]->delay=1;
		INT inin=read(INT);
		if(inin==4){
			v[i]->set_value(true);
			v[i]->op=&o_xor;
			//cerr<<i<<" -> [xor]"<<endl;
			//cerr<<"1 ->"<<endl;
			//cerr<<endl;
		}else if(inin==1){
			v[i]->op=&o_and;
			//cerr<<i<<" -> [and]"<<endl;
			//cerr<<endl;
		}else if(inin==2){
			v[i]->op=&o_or;
			//cerr<<i<<" -> [or]"<<endl;
			//cerr<<endl;
		}else if(inin==3){
			v[i]->op=&o_xor;
			//cerr<<i<<" -> [xor]"<<endl;
			//cerr<<endl;
		}
	}
	//cerr<<"operator_seted"<<endl;
	for(INT i=0;i<m;i++){
		INT a,b;
		cin>>a>>b;
		a--,b--;
		//cerr<<a<<" -> "<<b;
		if(p+q<=b){
			v[b]=v[a];
			//cerr<<" [fast]";
		}else{
			v[b]->add_link(v[a]);
		}
		//cerr<<" [set]"<<endl;
	}
	//cerr<<"link_seted"<<endl;
	//cerr<<"passby_seted"<<endl;
	INT mx=0;
	vector<bool>ans;
	for(INT i=p+q;i<p+q+r;i++){
		ans.push_back(v[i]->get_v());
		//cerr<<endl;
		//cerr<<i<<" -> "<<v[i]->get_v()<<" , "<<v[i]->delay<<endl;
		maxs(mx,v[i]->delay);
	}
	//cerr<<"finish"<<endl;
	cout<<mx<<endl;
	cout<<ans<<endl;

	return 0;
}




```
