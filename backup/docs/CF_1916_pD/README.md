# [`CF 1916 pD`](https://codeforces.com/contest/1916/problem/D) Mathematical Problem
## 標籤
`math` 
## 程式碼
```cpp
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		INT cz=(n-3)/2;
		INT az=0;
		for(;cz>=0;cz--,az+=2){
			cout<<1;
			for(INT i=0;i<cz;i++){
				cout<<0;
			}
			cout<<6;
			for(INT i=0;i<cz;i++){
				cout<<0;
			}
			cout<<9;
			for(INT i=0;i<az;i++){
				cout<<0;
			}
			cout<<endl;
			cout<<9;
			for(INT i=0;i<cz;i++){
				cout<<0;
			}
			cout<<6;
			for(INT i=0;i<cz;i++){
				cout<<0;
			}
			cout<<1;
			for(INT i=0;i<az;i++){
				cout<<0;
			}
			cout<<endl;
		}
		cout<<196;
		for(INT i=0;i<n-3;i++){
			cout<<0;
		}
		cout<<endl;
	}
	return 0;
}

```
