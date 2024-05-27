# [`NEOJ 875`](https://neoj.sprout.tw/problem/875/) 2024算法班入芽考_pD 芽芽與新公車
## 標籤

## 題解
NOT FOUND  

## 程式碼
```cpp
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define read(n) reader<n>()
#define P(n,m) pair<n,m>
#define PII P(INT,INT)
template<typename T>T reader(){
	T re;
	cin>>re;
	return re;
}
int main(){
	INT n,m,k;
	cin>>n>>m>>k;
	INT row[n+1]={};
	for(INT i=0;i<m;i++){
		INT l,r;
		cin>>l>>r;
		row[l]=max(row[l],r);
	}
	INT dp[n+1];
	for(INT i=2;i<=n;i++){
		dp[i]=1e9+7;
	}
	dp[1]=0;
	for(INT i=1;i<=n;i++){
		row[i]=max(row[i],row[i-1]);
	}
	/*
	cout<<"bus:"<<endl;
	for(INT i=1;i<=n;i++){
		cout<<row[i]<<" ";
	}
	cout<<endl;
	*/

	for(INT i=1;i<=n;i++){//  no new bus
		dp[row[i]]=min(dp[row[i]],dp[i]+1);
	}
	for(INT i=n-1;i>=1;i--){// fix
		dp[i]=min(dp[i],dp[i+1]);
	}

	for(INT i=n;i>=k+1;i--){// add new bus
		dp[i]=min(dp[i],dp[i-k]+1);
	}

	for(INT i=1;i<=n;i++){//fix
		dp[row[i]]=min(dp[row[i]],dp[i]+1);
	}
	if(dp[n]>n+100){
		cout<< -1<<endl;
	}else{
		cout<<dp[n]<<endl;
	}



	return 0;
}


```
