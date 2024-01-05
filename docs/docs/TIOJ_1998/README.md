# [`TIOJ 1998`](https://tioj.ck.tp.edu.tw/problems/1998) 網路遮罩
## 標籤
`string` `trie` 
## 程式碼
```cpp
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define DBG if(debug)
bool debug=0;

struct trie{
	bool hnxt[2]={};
	trie *nxt[2]={};
	INT cnt=0;
};
trie root;
INT n,m;
const INT mxn=2e5+5;
const INT mxm=3e5+5;

vector<bool> a[mxn];
vector<bool> b[mxm];

void build(INT n){
	vector<bool> &lst=a[n];
	trie *nw;
	nw=&root;
	for(int i:lst){
		if(!(nw->hnxt[i])){
			nw->hnxt[i]=1;
			nw->nxt[i]=new trie;
		}
		nw=nw->nxt[i];
	}
	nw->cnt++;
}
bool check(INT n){
	vector<bool> &lst=b[n];
	trie *nw;
	nw=&root;
	if(nw->cnt)return 1;
	for(int i:lst){
		if(!(nw->hnxt[i]))return 0;
		nw=nw->nxt[i];
		if(nw->cnt)return 1;
	}
	return 0;
}

int main(){
	DBG{}else{
		cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	}
	cin>>n>>m;
	for(INT i=0;i<n;i++){
		string str;
		cin>>str;
		INT nw=0;
		INT lim=0;
		for(char c:str){
			if(c=='.'||c=='/'){
				for(INT j=7;j>=0;j--){
					a[i].push_back(nw&(1<<j)?true:false);
				}
				nw=0;
			}else{
				nw*=10;
				nw+=c-'0';
			}
		}
		a[i].resize(nw);
		build(i);
	}
	for(INT i=0;i<m;i++){
		string str;
		cin>>str;
		INT nw=0;
		INT lim=0;
		for(char c:str){
			if(c=='.'||c=='/'){
				for(INT j=7;j>=0;j--){
					b[i].push_back(nw&(1<<j));
				}
				nw=0;
			}else{
				nw*=10;
				nw+=c-'0';
			}
		}
		for(INT j=7;j>=0;j--){
			b[i].push_back(nw&(1<<j));
		}
		if(check(i)){
			cout<<"TRUE"<<endl;
		}else{
			cout<<"FALSE"<<endl;
		}
	}

	return 0;
}

```
