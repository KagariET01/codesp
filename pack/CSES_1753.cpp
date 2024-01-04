#include<bits/stdc++.h>
using namespace std;
#define INT unsigned long long int
#define PII pair<INT,INT>
#define DBG if(debug)
bool debug=0;
int main(){
	DBG{}else{
		cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	}
	string str1;
	string str2;
	cin>>str1>>str2;
	INT st1=0;
	INT m=1e9+7;
	INT p=30;
	INT st2=0;
	INT ans=0;
	INT mn=1;
	for(char c:str2){
		st2*=p;
		st2+=c-'a';
		st2%=m;
		mn*=p;
		mn%=m;
	}
	DBG cout<<"st2="<<st2<<endl;
	DBG cout<<"mn="<<mn<<endl;
	for(INT i=0;i<str2.size();i++){
		st1*=p;
		st1+=str1[i]-'a';
		st1%=m;
	}
	for(INT i=str2.size();i<str1.size();i++){
		DBG cout<<st1<<endl;
		ans+=(st1==st2);
		if(str1==str2){
			DBG cout<<i<<endl;
		}
		st1*=p;
		st1-=mn*(str1[i-str2.size()]-'a')%m;
		st1+=str1[i]-'a';
		st1%=m;
	}
	ans+=(st1==st2);
	cout<<ans<<endl;
	return 0;
}
