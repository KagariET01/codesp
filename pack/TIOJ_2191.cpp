
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
	INT n;
	cin>>n;
	map<PII,INT> mp;
	vector<PII> vec1;
	for(INT i=0;i<n;i++){
		INT x,y,v;
		cin>>x>>y>>v;
		if(x&y){
			INT gcd=__gcd(x,y);
			x/=gcd;
			y/=gcd;
			if(x<0){
				x=-x;
				y=-y;
			}
		}else if(x==0){
			y=1;
		}else if(y==0){
			x=1;
		}
		mp[PII(y,x)]+=v;
		vec1.push_back(PII(y,x));
	}
	sort(vec1.begin(),vec1.end(),[](PII a,PII b){
		if(a.second==0)return false;
		else if(b.second==0)return true;
		INT gcd=__gcd(a.second,b.second);
		INT aa=a.second/gcd;
		INT bb=b.second/gcd;
		a.first*=bb;
		b.first*=aa;
		return a.first<b.first;
	});
	vector<PII> vec;
	vec.push_back(vec1[0]);
	for(INT i=1;i<n;i++){
		if(vec1[i]!=vec1[i-1]){
			vec.push_back(vec1[i]);
		}
	}
	INT nn=vec.size();
	for(PII i:vec){
		vec.push_back(i);
	}
	INT l=0;
	INT ans=0;
	INT nw=0;
//	cout<<vec<<endl;
	for(INT i=0;i<vec.size();i++){
		nw+=mp[vec[i]];
		while(i-l+1>nn ||( l<=i && nw<0)){
			nw-=mp[vec[l]];
			l++;
		}
		ans=max(ans,nw);
	}
	cout<<ans<<endl;
	return 0;
}




