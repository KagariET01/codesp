# [`NEOJ 874`](https://neoj.sprout.tw/problem/874/) 2024算法班入芽考_pC 芽芽與密碼鎖
## 標籤

## 題解
NOT FOUND  

## 程式碼
```cpp
[O[I#include<bits/stdc++.h>
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
	INT a,b,c,d;
	a=b=c=d=0;
	for(INT i=0;i<=9;i++){
		if(i)a++,a%=10;

		for(INT j=0;j<=9;j++){
			if(j)b++,b%=10;

			for(INT k=0;k<=9;k++){
				if(k)c++,c%=10;

				for(INT l=0;l<=9;l++){
					if(l)d++,d%=10;
					
					cout<<a<<b<<c<<d<<endl;
				}
			}
		}
	}	
	return 0;
}


```
