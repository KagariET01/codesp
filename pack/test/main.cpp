#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define f first
#define s second

queue<int> col[1005];
char grid[1005][1005];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			grid[j][i] = str[j];
			if (grid[j][i] == '*') { col[j].push(i); }
		}
	}

	for (int j = 0; j < M; j++) col[j].push(N);

	int maxa = 0;
	int maxl=0,maxr=0,maxu=0,maxd=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (col[j].front() < i) col[j].pop();  // updates the nearest tree
		}
		stack<pi> sta;
		for (int j = 0; j < M; j++) {
			int start = j;
			while (!sta.empty() && col[j].front() - i < sta.top().s) {
				pi cur = sta.top();
				sta.pop();
				start = cur.f;
				if(maxa<(j - cur.f) * cur.s){
					maxa=(j - cur.f) * cur.s;
					maxl=cur.f;
					maxr=j;
					maxu=i;
					maxd=i+cur.s;
				}
			}
			sta.push(make_pair(start, col[j].front() - i));
		}
		while (!sta.empty()) {
			pi cur = sta.top();
			sta.pop();
			if(maxa<(M - cur.f) * cur.s){
				maxa=(M - cur.f) * cur.s;
				maxl=cur.f;
				maxr=M;
				maxu=i;
				maxd=i+cur.s;
			}
			maxa = max(maxa, (M - cur.f) * cur.s);
		}
	}

	cout << maxa << endl;
	cerr<<maxu<<" "<<maxd<<" "<<maxl<<" "<<maxr<<endl;
}
