
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
template<typename T>auto(reader)=[](){T(re);return(cin>>re,re);};


template<typename T1,typename T2>ostream&operator<<(ostream&ou,pair<T1,T2>p){
	return ou<<"{"<<p.first<<","<<p.second<<"}";
}
template<typename T1,typename T2>istream&operator>>(istream&in,pair<T1,T2>&p){
	return in>>p.first>>p.second;
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

const INT mxa=1e9+7;

struct str{
	bool b=1;
	map<INT,str*> nxt;
};

ostream&operator<<(ostream&ou,str&st){
	if(st.nxt.empty())return ou<<"{}";
	else{
		ou<<"{";
		bool o=0;
		for(auto i:st.nxt){
			if(o)ou<<",";
			ou<<"{"<<i.F<<","<<*(i.S)<<"}";
			o=1;
		}
		return(ou<<"}");
	}
}

void pp(INT lv){
	for(INT i=0;i<lv;i++){
		cout<<">";
	}
	cout<<" ";
}

void apit(str *root,INT lv=0){
	for(auto i:root->nxt){
		pp(lv);
		cout<<i.F<<" "<<i.S->b<<endl;
		apit(i.S,lv+1);
	}
}




int main(){
	//cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		INT a[n];
		for(INT&i:a)cin>>i;
		str *root=new str;
		map<INT,vector<str*>> mp;
		INT ans=0;
		for(INT i=0;i<n;i++){
			if(i){
				INT nn=mp[a[i-1]].size();
				vector<str*>&nwmp=mp[a[i-1]];
				for(INT jj=0;jj<nn;jj++){
					str *j;
					j=nwmp[jj];
					if(j->nxt[a[i]]==NULL){
						j->nxt[a[i]]=new str;
						mp[a[i]].push_back(j->nxt[a[i]]);
						ans++;
					}else{
						ans-=j->nxt[a[i]]->b;
						j->nxt[a[i]]->b=0;
					}
				}
			}
			if(root->nxt[a[i]]==NULL){
				root->nxt[a[i]]=new str;
				mp[a[i]].push_back(root->nxt[a[i]]);
				ans++;
			}else{
				ans-=root->nxt[a[i]]->b;
				root->nxt[a[i]]->b=0;
			}
		}
		cout<<ans<<endl;
		apit(root);
	}
	return 0;
}



