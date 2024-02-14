# [`TIOJ 2052`](https://tioj.ck.tp.edu.tw/problems/2052) [`TOI 2018 pB`]() 排列第幾個
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




const INT mxn=1030;
INT c[mxn][mxn];




int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT d;
	string str;
	cin>>d>>str;
	for(INT i=0;i<mxn;i++){
		c[i][0]=1;
		for(INT j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=d;
		}
	}

	map<char,INT> mp;
	for(char c:str){
		mp[c]++;
	}
	INT ans=0;
	INT sp=str.size();
	for(char i:str){
		sp--;
		for(auto &j:mp){//  枚舉第i個字母為j時，會有多少種排列
			if(j.first==i)break;
			INT tmp=1;//  可能的排列數
			j.second--;
			INT left=sp;
			for(pair<char,INT> k:mp){
				tmp*=c[left][k.second];//  [還有多少空格可以填字][字母k.first放入這些空格的方法數]
				tmp%=d;
				left-=k.second;//  這些空格填上字，其他字就不能填在這些空格，所以數量會--
			}
			j.second++;
			ans+=tmp;
			ans%=d;
		}
		mp[i]--;
		if(!mp[i])mp.erase(i);
	}
	cout<<ans<<endl;

	return 0;
}




```
