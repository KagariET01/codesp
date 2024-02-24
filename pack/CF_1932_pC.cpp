
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
	ou<<"";
	for(T(i):vec){
		if(o)ou<<" ";
		o=1;
		ou<<i;
	}
	return(ou<<"");
}










int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n,m;
		cin>>n>>m;
		INT nw=1;
		INT num[n]={};
		for(INT i=0;i<n;i++){
			cin>>num[i];
		}
		string str;
		cin>>str;
		INT l=0,r=n-1;
		INT st=0;
		for(int i=0;i<n-1;i++){
			char c=str[i];
			if(c=='L')st++,l++;
			else r--;
		}

		vector<INT> ans(n);
		ans[n-1]=num[st]%m;
		for(INT i=n-2;i>=0;i--){
			ans[i]=ans[i+1];
			if(str[i]=='L'){
				l--;
				ans[i]*=num[l];
			}else{
				r++;
				ans[i]*=num[r];
			}
			ans[i]%=m;
		}
		cout<<ans<<endl;
	}
	return 0;
}



