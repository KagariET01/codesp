

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
	INT t;
	cin>>t;
	while(t--){
		INT n,m;
		cin>>n>>m;
		vector<INT>pack(n),item(m);
		cin>>pack>>item;
		sort(pack.begin(),pack.end());
		sort(item.begin(),item.end());
		INT ans=0;
		INT it=0;
		priority_queue<INT,vector<INT>,greater<INT>>que;
		for(INT i=0;i<m;i++){
			if(pack[it]<item[i]){
				if(!que.empty()){
					for(INT j=i;j<m;j++){
						if(item[j]-que.top()<=pack[it]){
							pack[it]-=item[j]-que.top();
							INT tp=item[j];
							item[j]=que.top();
							que.pop();
							que.push(tp);
						}else break;
					}
					while(!que.empty()){
						que.pop();
					}
				}
				while(it<n&&pack[it]<item[i]){
					it++;
				}
			}
			if(it>=n)break;
			pack[it]-=item[i];
			que.push(item[i]);
			ans++;
		}
		cout<<max(ans,3ll)<<endl;
	}
	return 0;
}



