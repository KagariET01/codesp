#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define DBG if(debug)
bool debug=0;
INT n,m;
const INT mxn=1005;
const INT mxm=85;
const INT superB=1e9+7;
INT dp[mxn][mxm][5];//  點編號,第ith字元,選擇顏色i時的最佳解(superB代表不可能,0代表所有可能的min
map<char,int> sw={
	{'@',0},
	{'A',1},
	{'U',2},
	{'C',3},
	{'G',4}
};
vector<INT> tree[mxn];
INT lst[mxn][mxm];//  紀錄原始資料
string str[mxn];
INT root=0;

INT mins(INT *l,INT *r){
	INT re=*l;
	while(l!=r){
		re=min(re,*l);
		l++;
	}
	return re;
}

void solve(INT nw,INT p){
	if(tree[nw].empty()){
		if(lst[nw][p]==0){
			for(INT i=0;i<5;i++)
				dp[nw][p][i]=0;
			return;
		}else{
			for(INT i=0;i<5;i++)
				dp[nw][p][i]=superB;
			dp[nw][p][ lst[nw][p] ]=dp[nw][p][0]=0;
			return;
		}
	}else{
		for(INT nxt:tree[nw]){
			solve(nxt,p);
		}
		if(lst[nw][p]==0){
			for(INT c=1;c<5;c++){
				dp[nw][p][c]=0;
				for(INT nxt:tree[nw]){
					dp[nw][p][c]+=min(dp[nxt][p][0]+1,dp[nxt][p][c]);//  顏色未知，所以會產生差值，所以+1,兩兩顏色一樣，沒有漢明差值，不用+1
				}
			}
			dp[nw][p][0]=mins(dp[nw][p]+1,dp[nw][p]+5);
			return;
		}else{
			for(INT c=0;c<5;c++){
				dp[nw][p][c]=superB;
			}
			INT nwc=lst[nw][p];
			dp[nw][p][nwc]=0;
			for(INT nxt:tree[nw]){
				dp[nw][p][nwc]+=min(dp[nxt][p][0]+1,dp[nxt][p][nwc]);
			}
			dp[nw][p][0]=dp[nw][p][nwc];
			return;
		}
	}
}

int main(){
	DBG{}else{
		cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	}
	cin>>n>>m;
	for(INT i=0;i<n;i++){
		INT p,q;
		cin>>p>>q;
		cin>>str[p];
		if(p==q){
			root=p;
		}else{
			tree[q].push_back(p);
		}
		for(INT j=0;j<m;j++){
			lst[p][j]=sw[str[p][j]];
		}
	}
	DBG for(INT i=1;i<=n;i++){
		for(INT j=0;j<m;j++){
			cout<<lst[i][j];
		}
		cout<<endl;
	}
	for(INT i=0;i<m;i++){
		solve(root,i);
	}
	INT ans=0;
	DBG for(INT i=1;i<=n;i++){
		for(INT j=0;j<m;j++){
			for(INT k=0;k<5;k++){
				INT &nw=dp[i][j][k];
				if(nw==superB)cout<<"-1 | ";
				else cout<<dp[i][j][k]<<" | ";
			}
		}
		cout<<endl;
	}
	for(INT i=0;i<m;i++){
		ans+=dp[root][i][0];
	}
	cout<<ans<<endl;
	return 0;
}
