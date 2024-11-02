# [`APCS 2024 10 pA`]( ) [`ZJ o711`](https://zerojudge.tw/ShowProblem?problemid=o711) 裝飲料
## 標籤

## 題解
NOT FOUND  

## 程式碼
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n,w1,w2,h1,h2;
	cin>>n>>w1>>w2>>h1>>h2;
	long long int lst=0;//上次注水時，水面最後停留的高度
	long long int a[n];
	for(long long int i=0;i<n;i++){
		cin>>a[i];
	}

	long long int ans=0;//紀錄最大的水位變化量
	long long int nw_button=w1*w1;//目前杯子的"底"
	for(long long int i=0;i<n;i++){
		long long int nw=lst;//目前的水面高度
		long long int in_water=0;//已注入的水量
		while(1){//a[i]的水量分次倒，一次倒一層
			if(nw==h1){
				nw_button=w2*w2;//水位上升到第二層，此時底面積為w2*w2
			}
			if(nw==h1+h2){
				break;//滿水位，跳出
			}
			in_water+=nw_button;
			nw++;
			if(in_water>=a[i]){//已經把所有水到進杯子裡了，跳出
				break;
			}

		}
		ans=max(ans,nw-lst);//更新答案
		lst=nw;
		cerr<<i<<" "<<nw<<endl;
	}
	cout<<ans<<endl;
}

```
