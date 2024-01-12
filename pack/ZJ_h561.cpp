#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define DBG if(debug)
bool debug=1;

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
				DBG cout<<"nw nwid="<<nwid<<endl;
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
			INT m=0;
			INT nxs=3;
			INT nwid=0;
			for(nwid=1;nwid<=n*m;nwid++){
				
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
			
		}
	}else if(n%2==1){
	}else{
	}
	ansl.resize(n*m+1);
	for(INT i=0;i<n;i++){
		for(INT j=0;j<m;j++){
			ansl[mp[i][j]-1]={i,j};
		}
	}
	for(PII i:ansl){
		cout<<i<<endl;
	}
	cout<<ansl[0]<<endl;
	DBG{
		for(INT i=0;i<n;i++){
			for(INT j=0;j<m;j++){
				cout<<mp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
