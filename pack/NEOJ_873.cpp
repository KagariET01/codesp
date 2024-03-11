[O[I#include<bits/stdc++.h>
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
int main(){
	INT n,c;
	cin>>n>>c;
	vector<INT> vec;
	for(INT i=0;i<n;i++){
		vec.push_back(read(INT));
	}
	vec.push_back(c);
	INT dp[5][n+1];
	for(INT i=0;i<5;i++){
		for(INT j=0;j<=n;j++){
			dp[i][j]=-1e18;
		}
	}
	for(INT i=0;i<5;i++){
		dp[i][0]=0;
	}

	auto cc=[](INT a,INT b){
		if(a<b)return b-a;
		else return -(a-b)*(a-b);
	};


	for(INT i=1;i<n;i++){
		dp[0][i]=dp[0][i-1]+cc(vec[i-1],vec[i]);
	}

	dp[4][1]=vec[1];

	for(INT i=1;i<n;i++){
		dp[1][i]=dp[0][i-1];
		dp[1][i]+=c-vec[i-1];

		dp[4][i+1]=max(dp[4][i+1],dp[1][i]+cc(c,vec[i+1]));
	}

	for(INT i=1;i<n;i++){
		dp[2][i]=dp[0][i-1];

		dp[4][i+1]=max(dp[4][i+1],dp[2][i]+cc(vec[i-1],vec[i+1]));
	}

	for(INT i=1;i<n-1;i++){
		dp[3][i]=dp[0][i-1];
		INT nwv=vec[i-1]+vec[i+1];
		nwv/=2;
		dp[3][i]+=cc(vec[i-1],nwv);
		dp[4][i+1]=max(dp[4][i+1],dp[3][i]+cc(nwv,vec[i+1]));
	}

	for(INT i=1;i<n;i++){
		dp[4][i]=max(dp[4][i],dp[4][i-1]+cc(vec[i-1],vec[i]));	
	}
	INT ans=-1e18;
	for(INT i=0;i<5;i++){
		ans=max(ans,dp[i][n-1]);
	}
	cout<<ans<<endl;

	return 0;
}

