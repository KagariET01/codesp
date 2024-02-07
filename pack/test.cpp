#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,popcnt,sse4,abm")
#include <bits/stdc++.h>
using namespace std;
 
#ifdef WAIMAI
#define debug(HEHE...) cout << "[" << #HEHE << "] : ", dout(HEHE)
void dout() {cout << '\n';}
template<typename T, typename...U>
void dout(T t, U...u) {cout << t << (sizeof...(u) ? ", " : ""), dout(u...);}
#else
#define debug(...) 7122
#endif
 
#define int long long
#define ll long long
#define Waimai ios::sync_with_stdio(false), cin.tie(0)
#define FOR(x,a,b) for (int x = a, I = b; x <= I; x++)
#define pb emplace_back
#define F first
#define S second
 
const int SIZE = 2e5 + 5;
 
int n, k;
int a[SIZE];
 
void solve() {
    cin >> n >> k;
    int sz = 0;
    int l = 1, r = n;
    fill(a + 1, a + n + 1, 0);
    FOR (i, 1, n) if (a[i] == 0) {
        if (i & 1) {
            for (int j = i; j <= n; j += k) a[j] = l++;
        } else {
            for (int j = i; j <= n; j += k) a[j] = r--;
        }
    }
    FOR (i, 1, n) cout << a[i] << " \n"[i == n];
}
 
int32_t main() {
    Waimai;
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
