//AC
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
	INT n,m;
	cin>>n>>m;
	string str[n];
	for(INT i=0;i<n;i++){
		cin>>str[i];
	}
	PII mouse=PII(0,0);
	priority_queue<PIPII,vector<PIPII>,greater<PIPII>>cat;
	INT mp[n][m];
	for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
			mp[i][j]=1e9+7;
		}
	}

	for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
			if(str[i][j]=='@')mouse=PII(i,j);
			else if(str[i][j]=='K'){
				cat.push(PIPII(0,PII(i,j)));
				mp[i][j]=0;
			}
			else if(str[i][j]=='#')mp[i][j]=-1;
		}
	}
	INT q;
	cin>>q;
	while(q--){
		INT t,x,y;
		cin>>t>>x>>y;
		cat.push(PIPII(t,PII(x,y)));
		mp[x][y]=t;
	}

	
	while(!cat.empty()){
		PIPII nw=cat.top();
		cat.pop();
		PII addr=nw.S;
		if(mp[addr.F][addr.S]>nw.F)continue;
		for(INT i=0;i<4;i++){
			INT nx=addr.F+mx[i];
			INT ny=addr.S+my[i];
			if(nx<0||n<=nx||
					ny<0||m<=ny)continue;
			//if(str[nx][ny]=='#')continue;
			if(mp[nx][ny]>nw.F+1){
				mp[nx][ny]=nw.F+1;
				cat.push(PIPII(nw.F+1,PII(nx,ny)));
			}
		}
	}

	if(mp[mouse.F][mouse.S]>=1e9){
		cout<<"= =\""<<endl;
	}else{
		cout<<mp[mouse.F][mouse.S]<<endl;
	}
}

