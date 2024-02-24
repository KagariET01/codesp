

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
	INT n;
	while(cin>>n){
		INT tree[n][n]={};
		for(INT i=0;i<n;i++){
			for(INT j=i+1;j<n;j++){
				cin>>tree[i][j];
				tree[j][i]=tree[i][j];
			}
		}
		cout<<"tree:"<<endl;
		for(INT i=0;i<n;i++){
			for(INT j=0;j<n;j++){
				cout<<tree[i][j]<<" ";
			}
			cout<<endl;
		}

		INT dpmx[n][(1ll<<n)]={};//st,已走過
		INT dpmn[n][(1ll<<n)]={};
		for(INT i=0;i<n;i++){
			for(INT j=1;j<(1ll<<n);j++){
				dpmx[i][j]=-1e9-7;
				dpmn[i][j]=1e9+7;
			}
		}
		for(INT j=0;j<(1ll<<n);j++){//已走過的點
			for(INT i=0;i<n;i++){//目前的點
				if(!(j&(1ll<<i)))continue;//如果那個點沒走過
				for(INT k=0;k<n;k++){//下一個點
					if(j&(1ll<<k))continue;//如果那個點走過了
					if(i==k)continue;//如果起點==下一個目的地
					mins(dpmn[k][j|(1ll<<k)],dpmn[i][j]+tree[i][k]);
					maxs(dpmx[k][j|(1ll<<k)],dpmx[i][j]+tree[i][k]);
				}
			}
		}
		cout<<"dpmn[i][...]:";
		for(INT i=0;i<n;i++){
			if(abs(dpmn[i][(1ll<<n)-1])>1000){
				cout<<">1000 ";
			}else{
				cout<<dpmn[i][(1ll<<n)-1]<<" ";
			}
		}
		cout<<endl;
		cout<<"dpmx[i][...]:";
		for(INT i=0;i<n;i++){
			if(abs(dpmx[i][(1ll<<n)-1])>1000){
				cout<<">1000 ";
			}else{
				cout<<dpmx[i][(1ll<<n)-1]<<" ";
			}
		}
		cout<<endl;


		INT mx=-1e9-7,mn=1e9+7;
		for(INT i=0;i<n;i++){
			maxs(mx,dpmx[i][(1ll<<n)-1]);
			mins(mn,dpmn[i][(1ll<<n)-1]);
		}
		cout<<"mx:"<<mx<<" mn:"<<mn<<endl;
		INT gcd=__gcd(mx,mn);
		mx/=gcd;
		mn/=gcd;
		cout<<mx<<"/"<<mn<<endl;
	}
	return 0;
}



