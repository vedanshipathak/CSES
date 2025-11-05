#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e12; // safer upper bound

ll solve(ll i, ll n, ll x, vector<ll>& arr, vector<vector<ll>>& dp) {
    if (x == 0) return 0;
    if (i >= n) return INF;

    if (dp[i][x] != -1) return dp[i][x];

    ll choose = INF;
    if (arr[i] <= x) {
        ll ch = solve(i, n, x - arr[i], arr, dp);
        if (ch != INF)
            choose = ch + 1;
    }

    ll nc = solve(i + 1, n, x, arr, dp);

    return dp[i][x] = min(choose, nc);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    // Use vector of size n × (min(x, 10000)) to prevent memory overflow
    ll limit = min(x, 10000LL); // for large x, we cap to avoid MLE
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -1));

    ll ans = solve(0, n, x, arr, dp);
    if (ans >= INF) cout << -1;
    else cout << ans;
}

