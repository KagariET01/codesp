#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define PII pair<INT,INT>
#define DBG if(debug)
bool debug=0;
istream &operator>>(istream &cn,PII &n){
	return (cn>>n.first>>n.second);
}

INT n;
const INT mxn=200000;
PII lst[mxn];
int main(){
	DBG{}else{
		cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	}
	cin>>n;
	for(INT i=0;i<n;i++){
		cin>>lst[i];
	}
	sort(lst,lst+n);
	vector<INT> vec;
	for(INT i=0;i<n;i++){
		INT &nw=lst[i].second;
		if(vec.empty() || nw>=vec.back())vec.push_back(nw);
		else{
			(*upper_bound(vec.begin(),vec.end(),nw))=nw;
		}
	}
	cout<<vec.size()<<endl;
	return 0;
}
