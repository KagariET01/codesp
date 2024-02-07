
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










int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n,k;
		cin>>n>>k;
		if(n==k){
			for(INT i=0;i<n;i++){
				if(i)cout<<" ";
				cout<<i+1;
			}
			cout<<endl;
			continue;
		}
		INT ans[n];
		INT r=n;
		INT st=0;
		for(st=0;st<k;st+=2){
			ans[st]=r;
			r--;
			for(INT j=st+k;j<n;j+=k){
				ans[j]=r;
				r--;
			}
		}

		INT l=1;
		st=1;
		for(st=1;st<k;st+=2){
			ans[st]=l;
			l++;
			for(INT j=st+k;j<n;j+=k){
				ans[j]=l;
				l++;
			}
		}


		for(INT i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}



