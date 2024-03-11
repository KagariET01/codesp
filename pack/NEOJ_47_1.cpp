

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

struct btree{
	INT v;
	btree *l=nullptr;
	btree *r=nullptr;
};

bool operator<(INT&a,btree&b){
	return a<b.v;
}

bool operator<(btree&a,INT&b){
	return a.v<b;
}






int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	btree *root=nullptr;
	INT q;
	cin>>q;
	while(q--){
		string str;
		INT a;
		cin>>str>>it;
		if(str=="insert"){
			if(root==nullptr){
				root=new btree;
				root->v=a;
			}else{
				btree *nw;
				nw=root;
				while(1){
					if(a<=nw->v){
						if(nw->l==nullptr){
							nw->l=new btree;
							nw->l->v=a;
							break;
						}else{
							nw=nw->l;
						}
					}else{
						if(nw->r==nullptr){
							nw->r=new btree;
							nw->r->v=a;
							break;
						}else{
							nw=nw->r;
						}
					}
				}
			}
		}else if(str=="query"){
			INT l=-1e9-7,r=1e9+7;
			bool same=0;
			//find l
			btree *nw;
			nw=root;
			while(1){
				if(nw->v==a){
					same=1;
					break;
				}
				if(nw->v<a){
					l=max(l,*nw->v);

				}
			}
			if(same){
				cout<<a<<endl;
				continue;
			}
		}else{
		}
	}
	return 0;
}



