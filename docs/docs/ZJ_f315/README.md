# [`ZJ f315`](https://zerojudge.tw/ShowProblem?problemid=f315) [`APCS 2020 10 pD`]() 低地距離
## 標籤
`divide` 
## 程式碼
```cpp
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define DBG if(debug)
bool debug=1;

const INT mxn=100000;
vector<PII> vec;
bool hve[mxn+5];
INT solve(vector<PII>::iterator l,vector<PII>::iterator r){
	if(r-l<=1)return 0;
	INT re=0;
	auto mnt=(r-l)/2+l;
	re+=solve(l,mnt);
	re+=solve(mnt,r);
	auto a=l,b=mnt;
	vector<PII> psh;
	psh.reserve(r-l);
	while(a<mnt || b<r){
		if(b>=r){
			psh.push_back(*a);
			a++;
		}else if(a>=mnt || (*a).first>=(*b).first){
			re+=(a-l)*(*b).second;
			psh.push_back(*b);
			b++;
		}else{
			psh.push_back(*a);
			a++;
		}
	}
	for(auto i:psh){
		*l=i;
		l++;
	}
	return re;
}
int main(){
	DBG{}else{
		cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	}
	INT n;
	cin>>n;
	vec.clear();
	for(INT i=0;i<n*2;i++){
		INT inin;
		cin>>inin;
		vec.push_back({inin,hve[inin]?1:-1});
		hve[inin]=1;
	}
	cout<<solve(vec.begin(),vec.end())<<endl;
	
	return 0;
}

```
