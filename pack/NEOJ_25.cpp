

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

struct myque{
	INT v=0;
	myque *l=nullptr;
	myque *r=nullptr;
};








int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,m;
	cin>>n>>m;
	myque *front[n];
	myque *back[n];
	for(INT i=0;i<n;i++){
		front[i]=back[i]=nullptr;
	}
	while(m--){
		string str=read(string);
		if(str=="ADD"){
			INT a,b;
			cin>>a>>b;
			a--;
			myque *newnote=new myque;
			newnote->v=b;
			if(front[a]==nullptr){
				front[a]=back[a]=newnote;
			}else{
				back[a]->r=newnote;
				newnote->l=back[a];
				back[a]=newnote;
			}
		}else if(str=="LEAVE"){
			INT i;
			cin>>i;
			i--;
			if(front[i]==nullptr){
				cout<<"queue "<<i+1<<" is empty!"<<endl;
				continue;
			}else{
				myque *lst;
				lst=front[i];
				front[i]=front[i]->r;
				if(front[i]!=nullptr){
					front[i]->l=nullptr;
				}
				delete(lst);
			}
		}else if(str=="JOIN"){
			INT a,b;
			cin>>a>>b;
			a--;
			b--;
			if(front[a]==nullptr)continue;
			else if(front[b]==nullptr){
				front[b]=front[a];
				back[b]=back[a];
				front[a]=nullptr;
				back[a]=nullptr;
				continue;
			}else{
				back[b]->r=front[a];
				front[a]->l=back[a];
				back[b]=back[a];
				front[a]=back[a]=nullptr;
			}
		}else{
			cout<<"FUCKYOU"<<endl;
			return 1;
		}
	}
	for(INT i=0;i<n;i++){
		cout<<"queue "<<i+1<<":";
		if(front[i]==nullptr){
			cout<<" empty"<<endl;
		}else{
			while(front[i]!=nullptr){
				cout<<" "<<front[i]->v;
				myque *lst;
				lst=front[i];
				front[i]=front[i]->r;
				if(front[i]!=nullptr){
					front[i]->l=nullptr;
				}
				delete(lst);
			}
			cout<<endl;
		}
	}
	return 0;
}



