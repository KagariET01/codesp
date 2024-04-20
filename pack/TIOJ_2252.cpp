

#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define FINT long double
#define superINT INT
#define read(n) reader<n>()
#define PII pair<INT,INT>
#define PFIFI pair<FINT,FINT>
#define PPIIPII pair<PII,PII>
#define pit(n) #n<<":"<<n<<" "
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


PFIFI operator-(PFIFI a,PFIFI b){
	return PFIFI(a.F-b.F,a.S-b.S);
}
PFIFI operator+(PFIFI a,PFIFI b){
	return PFIFI(a.F+b.F,a.S+b.S);
}
PFIFI operator*(PFIFI a,FINT n){
	return PFIFI(a.F*n,a.S*n);
}
PFIFI operator/(PFIFI a,FINT n){
	return PFIFI(a.F/n,a.S/n);
}







int main(){
	cin.tie(0);cout.tie(0);cerr.tie(0);ios::sync_with_stdio(0);
	FINT x,y;
	INT n;
	cin>>x>>y>>n;
	n++;
	PFIFI root=PFIFI(x,y);
	vector<PFIFI>vec(n);
	cin>>vec;
	FINT ans=1e18+7;
	auto len=[](PFIFI a)->FINT{
		return fabs(a.F*a.F)+fabs(a.S*a.S);
	};
	auto fans=[&](INT i)->void{
		FINT l=0,r=1;
		INT c=100000;
		PFIFI p1=vec[i],p2=vec[i+1];
		while(c--){
			FINT cm1=(r-l)/3+l;
			FINT cm2=(r-l)/3*2+l;
			PFIFI m1=(p2-p1)*cm1+p1;
			PFIFI m2=(p2-p1)*cm2+p1;
			m1=m1-root;
			m2=m2-root;
			FINT ml1=len(m1);
			FINT ml2=len(m2);
			if(ml1<ml2){
				r=cm2;
			}else if(ml1>ml2){
				l=cm1;
			}else{
				r=cm2;
				l=cm1;
			}
		//	if(ans>ml1||ans>ml2){
		//		cerr<<pit(i)<<pit(cm1)<<pit(m1)<<pit(ml1)<<pit(l)<<pit(r)<<endl;
		//		cerr<<pit(i)<<pit(cm2)<<pit(m2)<<pit(ml2)<<endl<<endl;
		//	}
			mins(ans,min(ml1,ml2));
		}
	};
	for(INT i=0;i<n;i++){
		PFIFI delt=vec[i]-root;
		FINT l=len(delt);
		mins(ans,l);
		//cerr<<pit(i)<<pit(delt)<<pit(l)<<endl;
	}
	for(INT i=0;i<n-1;i++){
		fans(i);
	}
	cout<<fixed<<setprecision(18)<<sqrt(ans)<<endl;
	return 0;
}



