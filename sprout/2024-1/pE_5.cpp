


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
	INT n;
	cin>>n;
	vector<INT>vec(n*2);
	for(INT&i:vec)cin>>i;
	vector<INT>ans;
	for(INT&i:vec)if(i>0)ans.push_back(i);
	cout<<0<<endl;
	for(INT i=0;i<n;i++){
		if(i)cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
}

