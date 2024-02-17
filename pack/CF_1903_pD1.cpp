
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
	INT n,q;
	cin>>n>>q;
	INT aa[n];
	for(INT&i:aa)cin>>i;
	while(q--){
		INT a[n];
		for(INT i=0;i<n;i++){
			a[i]=aa[i];
		}
		INT k;
		cin>>k;
		INT ans=0;
		for(INT i=60;i>=0;i--){
			INT need=0;
			for(INT j=0;j<n;j++){
				//cout<<"j:"<<j<<" a[j]:"<<a[j]<<" 1ll<<i:"<<(1ll<<i)<<" ";
				if((a[j] & (1ll<<i) )==0){
					INT nw=a[j]&((1ll<<i)-1);
					nw=(1ll<<i)-nw;
					need+=nw;
					//cout<<"nw:"<<nw;
				}
				if(need>k)break;
				//cout<<endl;
			}
			if(need<=k){
				//cout<<"change:"<<(1ll<<i)<<endl;
				ans|=1ll<<i;
				k-=need;
				for(INT j=0;j<n;j++){
					if((a[j]&(1ll<<i))==0){
						INT nw=a[j]&((1ll<<i)-1);
						nw=(1ll<<i)-nw;
						a[j]+=nw;
					}
				}
			}
			//cout<<"i:"<<i<<" ans:"<<ans<<" k:"<<k<<" need:"<<need<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}



