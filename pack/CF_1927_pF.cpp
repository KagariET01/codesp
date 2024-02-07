
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
		ou<<i<<",";
	}
	return(ou<<"\b}");
}


const INT mxn=2e5+5;

INT n,m;
vector<pair<INT,PII>>edgelst;
vector<INT> tre[mxn];
INT dsu[mxn];

INT bos(INT a){
	if(dsu[a]==a)return a;
	else return dsu[a]=bos(dsu[a]),dsu[a];
}

void mrg(INT a,INT b){
	a=bos(a),b=bos(b);
	dsu[a]=b;
}






void solve(){
	for(INT i=0;i<mxn;i++){
		dsu[i]=i;
		tre[i].clear();
	}
	edgelst.clear();
	

	cin>>n>>m;
	for(INT i=0;i<n;i++){
		pair<INT,PII> nw;
		cin>>nw.second>>nw.first;
		if(nw.second.first>nw.second.second)swap(nw.second.first,nw.second.second);
		edgelst.push_back(nw);
	}
	sort(edgelst.begin(),edgelst.end());
	set<INT> st;
	INT b=0;
	for(pair<INT,PII> i:edgelst){
		if(b){
			if(i.first>b)break;
		}

		tre[i.second.first].push_back(i.second.second);
		tre[i.second.second].push_back(i.second.first);

		if(bos(i.second.first)==bos(i.second.second)){
			cout<<i.first<<endl;
			b=i.first;
			st.push_back(bos(i.second.first));
			break;
		}else{
			mrg(i.second.first,i.second.second);
		}
	}
	queue<PII> que;

}








int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	return 0;
}



