

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

vector<INT>mkpr(INT n){
	vector<INT>re,lst(n);
	for(INT(i)=2;i<n;i++){
		if(!lst[i]){
			re.push_back(i);
		}
		for(INT(j):re){
			if(i*j>=n)break;
			lst[i*j]=j;
			if(j==lst[i])break;
		}
	}
	return(re);
}








int main(){
	cin.tie(0);cout.tie(0);cerr.tie(0);ios::sync_with_stdio(0);
	INT(n);
	cin>>n;
	vector<INT> vec;
	for(INT i=2;i<n;i++){
		while(n%i==0){
			vec.push_back(i);
			n/=i;
		}
		if(i*i>n)break;
	}
	if(n>1)vec.push_back(n);
	if(vec.size()!=2)cout<<"0 0"<<endl;
	else{
		sort(vec.begin(),vec.end());
		cout<<vec[0]<<" "<<vec[1]<<endl;
	}
	return 0;
}



