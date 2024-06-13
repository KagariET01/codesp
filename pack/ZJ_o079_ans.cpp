#include <bits/stdc++.h>
using namespace std;
// 實作量稍微大一點，所以先 define 一些好用的東西
// #define int long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ff first
#define ss second

const int MAXN = 3e5 + 10;

int v[MAXN];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // IO 優化
	unordered_map<int, vector<pii>> mp; // 用來快速查詢每個奇偶差有哪些左端點，pair 的兩個數字分別為 index 和 sum
	int n, k;
	cin >> n >> k;
	int presum = 0; // 前綴和
	int predif = 0; // 前綴奇偶差
	mp[0].push_back({0, 0}); // 處理整個陣列都被選的 edge case
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		presum += v[i]; // 前綴和加上 v[i]
		predif += v[i] % 2 ? -1 : 1; // 計算前綴奇偶差
		if (presum > k) continue;
		mp[predif].push_back({i, presum}); // 根據奇偶差把目前的端點記錄起來
	}
	int ans = mp[0].size() ? mp[0].back().ss : 0; // 處理全部都選左邊的 edge case
	int sufsum = 0; // 後綴和
	int sufdif = 0; // 後綴奇偶差
	for (int i = n; i >= 1; i--) {
		sufsum += v[i]; // 後綴和加上 v[i]
		sufdif += v[i] % 2 ? -1 : 1; // 計算後綴奇偶差
		vector<pii> endpts = mp[-sufdif]; // 所有奇偶差合法的左端點
		int l = 0;
		int r = upper_bound(all(endpts), (pii){i, -1}) - endpts.begin(); // 不考慮重疊到的
		while (l < r) { // 透過二分搜找到最佳左端點 
			int mid = (l + r) / 2;
			if (endpts[mid].ss + sufsum > k)
				r = mid;
			else
				l = mid + 1;
		}
		if (l <= 0) continue;
		ans = max(ans, endpts[l - 1].ss + sufsum); // 嘗試更新答案
	}
	cout << ans << endl; // 輸出答案
}
