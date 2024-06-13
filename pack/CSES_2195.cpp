
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

PII operator-(PII a,PII b){
	return PII(a.F-b.F,a.S-b.S);
}

INT operator*(PII a,PII b){
	return a.F*b.F + a.S*b.S;
}

INT operator^(PII a,PII b){
	return a.F*b.S - a.S*b.F;
}

bool dopop(PII a,PII b,PII c){
	//cout<<"checking: "<<a<<" "<<b<<" "<<c<<endl;
	// true: need pop
	// false: do not pop
	PII a2b=b-a;
	PII a2c=c-a;
	INT cro=a2b^a2c;
	//if(cro<0)cout<<"POP"<<endl;
	return cro<0;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	// INPUT
	INT n;
	cin>>n;
	vector<PII>vec(n);
	cin>>vec;
	// FIND POINT O
	PII root=vec[0];
	for(PII&i:vec){
		mins(root,i);
	}
	// SORT
	sort(vec.begin(),vec.end(),[&](PII a,PII b){
			INT cro=(a-root)^(b-root);
			if(cro!=0){
				return cro>0;
			}else{
				return (a-root)*(a-root)<(b-root)*(b-root);
			}
	});
	//cout<<pit(vec)<<endl;
	
	cerr<<"Polygon(";
	bool o=0;
	for(PII&i:vec){
		if(o)cerr<<",";
		cerr<<"("<<i.F<<","<<i.S<<")";
		o=1;
	}
	cerr<<")"<<endl;

	deque<PII>dq;
	dq.push_back(vec[0]);
	dq.push_back(vec[1]);
	for(INT i=2;i<n;i++){
		PII c=vec[i];
		while(dq.size()>=2){
			PII b,a;
			deque<PII>::reverse_iterator it=dq.rbegin();
			b=*it;
			it++;
			a=*it;
			if(dopop(a,b,c))dq.pop_back();
			else break;
		}
		dq.push_back(c);
	}
	while(dq.size()>=3){
		PII a,b,c;
		c=dq.front();
		deque<PII>::reverse_iterator it=dq.rbegin();
		b=*it;
		it++;
		a=*it;
		if(dopop(a,b,c))dq.pop_back();
		else break;
	}
	
	while(dq.size()>=3){
		PII a,b,c;
		a=dq.back();
		deque<PII>::iterator it=dq.begin();
		b=*it;
		it++;
		c=*it;
		if(dopop(a,b,c))dq.pop_front();
		else break;
	}

	cout<<dq.size()<<endl;

	for(PII&i:dq){
		cout<<i.F<<" "<<i.S<<endl;
	}


	/*
	cerr<<"Polygon(";
	for(PII&i:vec){
		cerr<<"("<<i.F<<","<<i.S<<"),";
	}
	cerr<<")"<<endl;
	/*
	lls *nw=new lls;
	nw->a=vec[0];
	for(INT i=1;i<n;i++){
		nw->pb(vec[i]);
		nw=nw->r;
	}
	INT nws=n;
	for(INT i=0;i<n*2;i++){
		lls *nx;
		nx=nw->r;
		PII a=nw->l->a;
		PII b=nw->a;
		PII c=nw->r->a;
		PII a2b=b-a;
		PII a2c=c-a;
		INT cs=a2b^a2c;
		if(cs<0){
			nw->pop();
			nws--;
		}
		nw=nx;
	}
	cout<<nws<<endl;
	for(INT i=0;i<nws;i++){
		cout<<nw->a.F<<" "<<nw->a.S<<endl;
		nw=nw->r;
	}
	cerr<<"Polygon(";
	for(INT i=0;i<nws;i++){
		cerr<<"("<<nw->a.F<<","<<nw->a.S<<"),";
		nw=nw->r;
	}
	cerr<<")"<<endl;
	/*
	////cerr<<vec<<endl;
	deque<PII>que;
	que.push_back(vec[0]);
	que.push_back(vec[1]);
	for(INT i=2;i<n;i++){
		que.push_back(vec[i]);
		//cerr<<"PUSH ("<<vec[i].F<<","<<vec[i].S<<")"<<endl;
		while(1){
			if(que.size()<3)break;
			deque<PII>::iterator it=que.end();
			it--;
			PII c=*it;
			it--;
			PII b=*it;
			it--;
			PII a=*it;
			//cerr<<"checking point: ";
			//cerr<<"("<<a.F<<","<<a.S<<") ";
			//cerr<<"("<<b.F<<","<<b.S<<") ";
			//cerr<<"("<<c.F<<","<<c.S<<")"<<endl;

			PII a2b=b-a;
			PII a2c=c-a;


			INT cross=a2b^a2c;
			if(cross<0){
				que.pop_back();
				que.pop_back();
				que.push_back(c);
				//cerr<<"POP"<<endl;
			}else break;
		}
		//cerr<<pit(i)<<pit(que)<<endl;
	}
	while(1){
		if(que.size()<3)break;
		deque<PII>::iterator it=que.end();
		it--;
		PII b=*it;
		it--;
		PII a=*it;
		PII c=que.front();
		PII a2b=b-a;
		PII a2c=c-a;

		INT cross=a2b^a2c;
		if(cross<0){
			que.pop_back();
		}else break;
	}

	while(1){
		if(que.size()<3)break;
		deque<PII>::iterator it=que.begin();
		PII a=que.back();
		PII b=*it;
		it++;
		PII c=*it;
		PII a2b=b-a;
		PII a2c=c-a;

		INT cross=a2b^a2c;
		if(cross<0){
			que.pop_front();
		}else break;
	}
	cout<<que.size()<<endl;
	for(PII i:que){
		cout<<i.F<<" "<<i.S<<endl;
	}
	cerr<<"Polygon(";
	for(PII i:que){
		cerr<<"("<<i.F<<","<<i.S<<"),";
	}
	cerr<<")"<<endl;
	*/
	return 0;
}



