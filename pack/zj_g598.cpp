#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
INT n,m;
INT p,k;
//n=人數 m=邊數
const INT mxn=20000;
const INT mxp=10000;
const INT mxk=20;
bool vis[mxn+5];
int flag[mxn+5];
vector<PII> orig;//  原始資料
vector<PII> lst[mxp+5];//  員工帶來的資料
vector<INT> tree[mxn];

istream &operator>>(istream &cn,PII n){
	return (cn>>n.first>>n.second);
}

void build(INT a){
	for(INT i=0;i<n;i++){
		flag[i]=0;
		vis[i]=0;
		tree[i].clear();
	}
	for(PII i:orig){
		tree[i.first].push_back(i.second);
		tree[i.second].push_back(i.first);
	}
	for(INT i=1;i<=a;i++){
		for(PII j:orig){
			tree[j.first].push_back(j.second);
			tree[j.second].push_back(j.first);
		}
	}
}

bool dfs(INT nw){
	vis[nw]=1;
	for(INT i:tree[nw]){
		if(!vis[i]){
			flag[i]=3-flag[nw];
			if(!dfs(i))return 0;
		}else if(flag[i]==flag[nw])return 0;
	}
	return 1;
}

bool check(INT a){
	build(a);
	for(INT i=0;i<n;i++){
		if(!vis[i]){
			flag[i]=1;
			if(!dfs(i))return 0;
		}
	}
	return 1;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	orig.resize(m);
	for(INT i=0;i<m;i++){
		cin>>orig[i];
	}
	cin>>p>>k;
	return 0;
}
