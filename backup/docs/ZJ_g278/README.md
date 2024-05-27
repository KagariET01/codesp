# [`APCS 2021 09 pD`]() [`ZJ g278`](https://zerojudge.tw/ShowProblem?problemid=g278) 美食博覽會
## 標籤
`dp` 
## 題解
NOT FOUND  

## 程式碼
```cpp
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define DBG if(debug)
bool debug=0;

INT n,k;
const INT mxn=1000000;
const INT mxk=20;
const INT mxa=100000;
INT a[mxn+5];
bool vis[mxa+5];
INT nw=0;
INT dp[mxk+5][mxn+5];
int main(){
	DBG{}else{
		cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	}
	cin>>n>>k;
	for(INT i=1;i<=n;i++){
		cin>>a[i];
	}
	for(INT i=1;i<=k;i++){
		for(INT j=0;j<=mxa;j++){
			vis[j]=0;
		}
		INT l=1;
		nw=0;
		for(INT j=1;j<=n;j++){
			while(vis[a[j]]){
				vis[a[l]]=0;
				l++;
				nw--;
			}
			vis[a[j]]=1;
			nw++;
			dp[i][j]=nw;
			dp[i][j]+=dp[i-1][l-1];
			dp[i][j]=max(dp[i][j],dp[i][j-1]);
		}
	}
	cout<<dp[k][n]<<endl;
	return 0;
}

```
