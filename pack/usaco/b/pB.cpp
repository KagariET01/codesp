
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
	}
	return(ou<<"}");
}
template<typename T>ostream&operator<<(ostream&ou,stack<T>st){
	vector<T>vec;
	while(!st.empty()){
		vec.push_back(st.top());
		st.pop();
	}
	reverse(vec.begin(),vec.end());
	return(ou<<vec);
}









int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n,p;
		cin>>n>>p;
		string stra,strb;
		cin>>stra>>strb;
		stack<pair<INT,bool>> a,b,c;
		auto pb=[&](stack<pair<INT,bool>>&st,string str){
			pair<INT,bool> nw;
			for(char c:str){
				bool nwb=(c-'1');
				if(nw.F==0){
					nw=pair<INT,bool>(1,nwb);
				}else if(nw.S==nwb){
					nw.F++;
				}else{
					st.push(nw);
					nw=pair<INT,bool>(1,nwb);
				}
			}
			st.push(nw);
		};
		pb(a,stra);
		pb(b,strb);
		vector<PII> ans;
		auto checker=[](stack<pair<INT,bool>>&a,
										stack<pair<INT,bool>>&b,
										stack<pair<INT,bool>>&c,
										vector<PII>&ans,
										INT one,INT two,INT three,INT n,string id){
			if(!a.empty() && a.top().F>=n){
				if(a.size()==1)return 2;
				else{
					if(b.empty()){
						b.push(a.top());
						a.pop();
						ans.push_back({one,two});
						return 1;
					}else if(c.empty()){
						c.push(a.top());
						a.pop();
						ans.push_back({one,three});
						return 1;
					}else return 0;
				}
			}
			if(!a.empty()){
				if(!b.empty() && b.top().S==a.top().S){
					if(b.size()<a.size()){
						b.top().F+=a.top().F;
						a.pop();
						ans.push_back({one,two});
					}else{
						a.top().F+=b.top().F;
						b.pop();
						ans.push_back({two,one});
					}
					return 1;
				}else if(!c.empty() && c.top().S==a.top().S){
					if(c.size()<a.size()){
						c.top().F+=a.top().F;
						a.pop();
						ans.push_back({one,three});
					}else{
						a.top().F+=c.top().F;
						c.pop();
						ans.push_back({three,one});
					}
					return 1;
				}else if(a.size()>=2){
					if(b.empty()){
						b.push(a.top());
						a.pop();
						ans.push_back({one,two});
						return 1;
					}else if(c.empty()){
						c.push(a.top());
						a.pop();
						ans.push_back({one,three});
						return 1;
					}else return 0;
				}else return 0;
			}else return 0;
		};
		INT dbgcnt=0;
		while(1){
			if(dbgcnt>=10)break;
			dbgcnt++;
			INT cnt=0;
			INT doa=checker(a,b,c,ans,1,2,3,n,"a");
			if(doa==1)continue;
			if(doa==2)cnt++;
			INT dob=checker(b,a,c,ans,2,1,3,n,"b");
			if(dob==1)continue;
			if(dob==2)cnt++;
			INT doc=checker(c,a,b,ans,3,1,2,n,"c");
			if(doc==2)cnt++;
			if(cnt>=2)break;
		}
		if(a.empty()){
			ans.push_back({3,1});
		}
		if(b.empty()){
			ans.push_back({3,2});
		}
		cout<<ans.size()<<endl;
	}
	return 0;
}



