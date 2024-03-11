

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










int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT q;
	cin>>q;
	set<INT> se;
	se.clear();
	while(q--){
		string str;
		INT a;
		cin>>str>>a;
		if(str=="insert"){
			se.insert(a);
		}else if(str=="delete"){
			se.erase(a);
		}else if(str=="query"){
			set<INT>::iterator it=se.lower_bound(a);
			if(it==se.begin()){
				cout<<(*it)<<endl;
				continue;
			}else if(it==se.end()){
				it--;
			}
			INT le=(*it)-a;
			it--;
			INT lle=a-(*it);
			if(le==lle){
				cout<<(*it)<<" ";
				it++;
				cout<<(*it)<<endl;
				continue;
			}else if(lle<le){
				cout<<(*it)<<endl;
				continue;
			}else{
				it++;
				cout<<(*it)<<endl;
				continue;
			}
		}
	}
	return 0;
}



