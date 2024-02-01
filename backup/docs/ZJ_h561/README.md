# [`ZJ h561`](https://zerojudge.tw/ShowProblem?problemid=h561) [`TIOJ 2250`](https://tioj.ck.tp.edu.tw/problems/2250) [`TOI 2022 pE`]( ) 間諜(spy)
## 標籤

## 程式碼
```cpp
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define DBG if(debug)
bool debug=0;

INT n,m;
const INT mxn=1005;
INT mp[mxn][mxn];
bool sp=0;
vector<PII> ansl;

ostream &operator<<(ostream &oc,PII &nw){
	return (oc<<nw.first<<" "<<nw.second);
}

PII operator+(PII &a,PII &b){
	return make_pair(a.first+b.first, a.second+b.second);
}


int main(){
	DBG{}else{
		cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	}
	cin>>n>>m;
	if(n>m){//保證n<=m
		swap(n,m);
		sp=1;
	}
	if(n==2){
		if(m<=4){
			cout<<"-1"<<endl;
			return 0;
		}else{
			PII nw={0,0};
			PII nx[]={
				{1,3},
				{-1,-2}
			};
			INT mv=0;//  動作編號
			INT nxs=2;//  nx size
			DBG cout<<"n*m="<<n*m<<endl;
			for(INT nwid=1;nwid<=n*m;nwid++){
				mp[nw.first][nw.second]=nwid;
				nw=nw+nx[mv];
				nw.first+=n;
				nw.second+=m;
				nw.first%=n;
				nw.second%=m;
				mv++;
				mv%=nxs;
			}
		}
	}else if(n==3){
		if(m<=3){
			cout<<"-1"<<endl;
			return 0;
		}else{
			PII nw={0,0};
			PII nx[]={
				{1,2},
				{1,-2},
				{-2,1}
			};
			INT mv=0;
			INT nxs=3;
			INT nwid=0;
			for(nwid=1;nwid<=n*m;nwid++){
				mp[nw.first][nw.second]=nwid;
				nw=nw+nx[mv];
				nw.first+=n;
				nw.second+=m;
				nw.first%=n;
				nw.second%=m;
				mv++;
				mv%=nxs;
			}
		}
	}else if(n==4){
		if(m==4){
			INT nmp[4][4]={
				{16,6,14,8},
				{9,2,11,4},
				{5,13,7,15},
				{1,10,3,12}
			};
			for(INT i=0;i<n;i++){
				for(INT j=0;j<m;j++){
					mp[i][j]=nmp[i][j];
				}
			}
		}else{
			PII nw={0,0};
			PII nx[]={
				{1,2},
				{1,-2},
				{1,2},
				{1,-1}
			};
			INT mv=0;
			INT nxs=4;
			INT nwid=0;
			for(nwid=1;nwid<=n*m;nwid++){
				DBG cout<<nw<<" "<<nwid<<" nxt op:"<<mv<<endl;
				mp[nw.first][nw.second]=nwid;
				nw=nw+nx[mv];
				nw.first+=n;
				nw.second+=m;
				nw.first%=n;
				nw.second%=m;
				mv++;
				mv%=nxs;
			}
		}
	}else if(n%2==1){
		if(n==m){
			PII nw={0,0};
			PII nx[]={
				{1,2},
				{1,-2},
				{1,2}
			};
			INT mv=0;
			INT nxs=4;
			INT nwid=0;
			for(nwid=1;nwid<=n*m;nwid++){
				DBG cout<<nw<<" "<<nwid<<" nxt op:"<<mv<<endl;
				mp[nw.first][nw.second]=nwid;
				if(nwid%n==n-1){
					mv=2;
				}else{
					mv=1-(nwid%n)%2;
				}
				nw=nw+nx[mv];
				DBG cout<<"nx[mv]="<<nx[mv]<<endl;
				nw.first+=n;
				nw.second+=m;
				nw.first%=n;
				nw.second%=m;
			}
		}else{
			PII nw={0,0};
			PII nx[]={
				{1,2},
				{1,-2},
				{1,1}
			};
			INT mv=0;
			INT nxs=4;
			INT nwid=0;
			for(nwid=1;nwid<=n*m;nwid++){
				mp[nw.first][nw.second]=nwid;
				if(nwid%n==0){
					mv=2;
				}else{
					mv=1-(nwid%n)%2;
				}
				DBG cout<<nw<<" "<<nwid<<" nxt op:"<<mv<<endl;
				nw=nw+nx[mv];
				DBG cout<<"nx[mv]="<<nx[mv]<<endl;
				nw.first+=n;
				nw.second+=m;
				nw.first%=n;
				nw.second%=m;
			}
		}
	}else{
		if(n==m){
			PII nw={0,0};
			PII nx[]={
				{1,2},
				{1,-2},
				{1,-3}
			};
			INT mv=0;
			INT nxs=4;
			INT nwid=0;
			for(nwid=1;nwid<=n*m;nwid++){
				DBG cout<<nw<<" "<<nwid<<" nxt op:"<<mv<<endl;
				mp[nw.first][nw.second]=nwid;
				if(nwid%n==n-1){
					mv=2;
				}else{
					mv=1-(nwid%n)%2;
				}
				nw=nw+nx[mv];
				DBG cout<<"nx[mv]="<<nx[mv]<<endl;
				nw.first+=n;
				nw.second+=m;
				nw.first%=n;
				nw.second%=m;
			}
		}else{
			PII nw={0,0};
			PII nx[]={
				{1,2},
				{1,-2},
				{1,-1}
			};
			INT mv=0;
			INT nxs=4;
			INT nwid=0;
			for(nwid=1;nwid<=n*m;nwid++){
				mp[nw.first][nw.second]=nwid;
				if(nwid%n==0){
					mv=2;
				}else{
					mv=1-(nwid%n)%2;
				}
				DBG cout<<nw<<" "<<nwid<<" nxt op:"<<mv<<endl;
				nw=nw+nx[mv];
				DBG cout<<"nx[mv]="<<nx[mv]<<endl;
				nw.first+=n;
				nw.second+=m;
				nw.first%=n;
				nw.second%=m;
			}

		}
	}
	ansl.resize(n*m+1);
	for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
			if(sp){
				ansl[mp[i][j]-1]={j+1,i+1};
				if(mp[i][j]==1){
					ansl[n*m]={j+1,i+1};
				}
			}else{
				ansl[mp[i][j]-1]={i+1,j+1};
				if(mp[i][j]==1){
					ansl[n*m]={i+1,j+1};
				}
			}

		}
	}
	for(PII i:ansl){
		cout<<i<<endl;
	}
	cerr<<"finish"<<endl;
	return 0;
}

```
