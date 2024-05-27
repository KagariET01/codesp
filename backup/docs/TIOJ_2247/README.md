# [`TIOJ 2247`](https://tioj.ck.tp.edu.tw/problems/2247) [`TOI 2022 pB`]( ) 打鍵盤(keyboard)
## 標籤
`dp` 
## 題解
NOT FOUND  

## 程式碼
```cpp

#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define superINT INT
#define read(n) reader<n>()
#define PII pair<INT,INT>
#define PPIIPII pair<PII,PII>
#define pit(n) #n<<":"<<n
#define MP(n,m) make_pair(n,m)
#define endl '\n'
#define BIG INT_MAX
#define mins(a,b) a=min(a,b)
template<typename T>auto(reader)=[](){T(re);return(cin>>re,re);};


template<typename T1,typename T2>ostream&operator<<(ostream&ou,pair<T1,T2>p){
	return ou<<"{"<<p.first<<","<<p.second<<"}";
}
template<typename T1,typename T2>istream&operator>>(istream&in,pair<T1,T2>&p){
	return in>>p.first>>p.second;
}
template<typename T>ostream&operator<<(ostream&ou,vector<T>vec){
	bool o=0;
	ou<<"{";
	for(T(i):vec){
		ou<<i<<",";
	}
	return(ou<<"\b}");
}

INT mx[]={-1,-1,0,0,1,1};
INT my[]={0,1,-1,1,-1,0};



char keywd[3][12]={
	"QWERTYUIOP",
	"ASDFGHJKL ",
	"ZXCVBNM   "
};
map<char,PII> ky;

map<pair<int,int>,int> l;
void getl(INT x,INT y){
	queue<pair<INT,INT>> que;
	que.push(make_pair(x,y));
	while(!que.empty()){
		INT nwx=que.front().first;
		INT nwy=que.front().second;
		que.pop();
		for(INT i=0;i<6;i++){
			INT nxx=nwx+mx[i];
			INT nxy=nwy+my[i];
			if(nxx<0 || 3<=nxx)continue;
			if(nxy<0 || 10<=nxy)continue;
			if(nxx==x && nxy==y)continue;
			if(l[make_pair(keywd[x][y]-'A',keywd[nxx][nxy]-'A')])continue;
			else{
				l[make_pair(keywd[x][y]-'A',keywd[nxx][nxy]-'A')]=l[make_pair(keywd[x][y]-'A',keywd[nwx][nwy]-'A')]+1;
				que.push(make_pair(nxx,nxy));
			}
		}
	}
}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	for(INT i=0;i<3;i++){
		for(INT j=0;j<10;j++){
			ky[keywd[i][j]]=make_pair(i,j);
		}
	}
	for(INT i=0;i<3;i++){
		for(INT j=0;j<10;j++){
			getl(i,j);
		}
	}
	INT n;
	cin>>n;
	string str;
	cin>>str;
	INT dp[n+5][30][30];
	for(INT i=0;i<=n;i++){
		for(INT j=0;j<26;j++){
			for(INT k=0;k<26;k++){
				dp[i][j][k]=BIG;
			}
		}
	}
	dp[0][5][9]=0;
	for(INT i=1;i<=n;i++){
		for(INT j=0;j<26;j++){//l hand
			for(INT k=0;k<26;k++){
				mins(dp[i][j][str[i-1]-'A'],dp[i-1][j][k]+l[make_pair(k,str[i-1]-'A')]);
				mins(dp[i][str[i-1]-'A'][k],dp[i-1][j][k]+l[make_pair(j,str[i-1]-'A')]);
			}
		}
	}
	INT ans=BIG;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			mins(ans,dp[n][i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;

	for(INT i=0;i<=n;i++){
		for(INT j=0;j<26;j++){
			for(INT k=0;k<26;k++){
				if(dp[i][j][k]==BIG)cout<<"-1 ";
				else cout<<dp[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}




```
