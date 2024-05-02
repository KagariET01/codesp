#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define PIPII pair<INT,PII>
#define endl '\n'
#define read(x) reader<x>()
#define F first
#define S second
template<typename T>T reader(){T re;cin>>re;return re;}
INT mx[]={1,0,-1,0};
INT my[]={0,1,0,-1};
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT n,w;
	cin>>n>>w;
	vector<INT>c(n);
	vector<INT>t(n);
	for(INT&i:c)cin>>i;
	INT dp[w+1]={};
	for(INT i=0;i<n;i++){
		for(INT j=w;j>=c[i];j--){
			dp[j]=max(dp[j-c[i]]+1,((j)?dp[j-1]:0));
		}
	}
	cout<<dp[w]<<endl;
}

