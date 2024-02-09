# [`TIOJ 2189`](https://tioj.ck.tp.edu.tw/problems/2189) [`TOI 2020_pB`]( ) 建設人工島
## 標籤

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


INT n;
const INT mxn=1e5+5;
array<vector<PII>,mxn> tree;
INT supermin=-1e9-7;

void upd(INT&a,INT&b,INT c){
	if(c>a){
		b=a,a=c;
	}else if(a>c&&c>b){
		b=c;
	}
}

array<INT,4> dfs(INT nw,INT lst){
	array<INT,4>ans={0,supermin,0,supermin};//{第一長路徑,第二長路徑,子樹的第一長路徑,子樹的第二長路徑}
	for(PII i:tree[nw]){
		if(i.F==lst)continue;
		array<INT,4> d=dfs(i.F,nw);
		upd(ans[0],ans[1],d[0]);
		upd(ans[0],ans[1],d[1]);
		upd(ans[0],ans[1],ans[2]+d[2]+i.S);
		upd(ans[0],ans[1],ans[2]+d[3]+i.S);
		upd(ans[0],ans[1],ans[3]+d[2]+i.S);
		upd(ans[2],ans[3],d[2]+i.S);
		upd(ans[2],ans[3],d[3]+i.S);
	}
	return ans;
}





int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n;
	for(INT i=1;i<n;i++){
		INT a,b,c;
		cin>>a>>b>>c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
	}
	cout<<dfs(0,-1)[1]<<endl;
	return 0;
}




```
