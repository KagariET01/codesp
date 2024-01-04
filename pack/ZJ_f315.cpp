#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define DBG if(debug)
bool debug=0;

vector<INT> vec;
INT solve(vector<INT>::iterator l,vector<INT>::iterator r){
	if(l==r)return 0;
	INT re=0;
	vector<INT>::iterator mid=(r-l)/2+l;
	re+=solve(l,mid);
	re+=solve(mid,r);

}
int main(){
	DBG{}else{
		cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	}
	INT n;
	cin>>n;
	
	return 0;
}
