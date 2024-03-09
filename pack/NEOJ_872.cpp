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

INT mx[]={1,0,-1,0};
INT my[]={0,1,0,-1};
map<char,INT> mp;
int main(){
	mp['U']=2;
	mp['D']=0;
	mp['L']=3;
	mp['R']=1;
	INT n,m,r,c;
	cin>>n>>m>>r>>c;
	r--,c--;
	INT g[n][m];
	for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
			cin>>g[i][j];
		}
	}
	INT s;
	cin>>s;
	string str;
	cin>>str;
	INT ans=0;
	for(char ca:str){
		INT nx=r+mx[mp[ca]];
		INT ny=c+my[mp[ca]];
		if(nx<0 || n<=nx || ny<0 || m<=ny)continue;
		if(g[nx][ny]==-1)continue;
		ans+=g[nx][ny];
		g[nx][ny]=0;
		r=nx,c=ny;
	}
	cout<<ans<<endl;
	return 0;
}

