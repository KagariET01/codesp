
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
		ou<<i<<",";
	}
	return(ou<<"\b}");
}










int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT c,n,k;
		cin>>c>>n>>k;
		INT eget[n]={};//event
		INT oget[n]={};//odd
		for(INT i=0;i<n;i++){
			INT emin=1e9+7;
			INT emax=0;
			INT omin=1e9+7;
			INT omax=0;
			for(INT j=0;j<k;j++){
				INT inin=read(INT);
				if(inin&1){
					omin=min(omin,inin);
					omax=max(omax,inin);
				}else{
					emin=min(emin,inin);
					emax=max(emax,inin);
				}
			}
			eget[i]=-omax;
			if(eget[i]==0)eget[i]=emin;
			oget[i]=-emax;
			if(oget[i]==0)oget[i]=omin;
		}
		//check
		INT nwc=c;
		bool hans=1;
		for(INT i=0;i<n;i++){
			nwc+=max(eget[i],oget[i]);
			if(nwc<=0){
				hans=0;
				break;
			}
		}
		if(!hans){
			cout<<"-1"<<endl;
			continue;
		}else{
			deque<bool> que;
			function<bool(INT,INT)> guesser;
			guesser=[&](INT nwc,INT i){
				if(nwc<=0)return false;
				if(i>=n)return true;
				if(guesser(nwc+eget[i],i+1)){que.push_front(true);return true;}
				if(guesser(nwc+oget[i],i+1)){que.push_front(false);return true;}
				return false;
			};
		
			guesser(c,0);
			while(!que.empty()){
				if(que.size()<n)cout<<" ";
				if(que.front()){
					cout<<"Even";
				}else{
					cout<<"Odd";
				}
				que.pop_front();
			}
			cout<<endl;
		}
	}
	return 0;
}



