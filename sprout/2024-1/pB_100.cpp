//AC
#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define endl '\n'
#define read(x) reader<x>()
template<typename T>T reader(){T re;cin>>re;return re;}
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT q,k;
	cin>>q>>k;
	INT nwtot=0;
	priority_queue<INT>pq;
	while(q--){
		INT opt;
		cin>>opt;
		if(opt==1){
			INT x;
			cin>>x;
			x-=nwtot;
			pq.push(x);
			while(pq.size()>k)pq.pop();
		}else if(opt==2){
			nwtot+=read(INT);
		}else{
			if(pq.size()<k)cout<<"No solution"<<endl;
			else			cout<<pq.top()+nwtot<<endl;
		}
	}
}
