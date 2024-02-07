# [`TIOJ 2331`](https://tioj.ck.tp.edu.tw/problems/2331) [`TOI 2023_pB`]( ) 裁員風暴
## 標籤
`binaryS` 
## 題解
NOT FOUND  

## 程式碼
```cpp

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
	INT n,k;
	cin>>n>>k;
	INT a[n];
	for(INT i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	function<INT(INT)> getRK=[&](INT nw){
		INT w=0;//多少人的分<他
		INT r=n-1;
		for(INT i=0;i<n;i++){
			while(r>=0){
				if(a[i]+a[r]>=nw)r--;
				else break;
			}
			w+=n-(r+1);
		}
		for(INT i=n-1;i>=0;i--){
			if(a[i]*2<nw)break;
			else w++;
		}
		return w/2;
	};
	INT l=a[0]*2,r=a[n-1]*2+1;
	while(l<r){
		INT mid=(r-l)/2+l+1;
		INT nw=getRK(mid);
		//cout<<"l:"<<l<<" r:"<<r<<" mid:"<<mid<<" nw:"<<nw<<endl;
		if(nw>=k){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	if(l&1){
		cout<<l<<endl<<"2"<<endl;
	}else{
		cout<<l/2<<endl<<"1"<<endl;
	}

	//cout<<l<<endl;
	return 0;
}




```
