#include <bits/stdc++.h>
using namespace std;

int f(int i, int target, vector<long long> &arr, int n, vector<vector<long long>> &dp) {
    if (target == 0) return 0;
    if (i >= n) return INT_MAX;
    if (dp[i][target] != -1) return dp[i][target];

    int nottake = f(i + 1, target, arr, n, dp);
    int take = INT_MAX;
    if (arr[i] <= target) {
        int res = f(i, target - arr[i], arr, n, dp);
        if (res != INT_MAX) take = 1 + res;
    }

    return dp[i][target] = min(take, nottake);
}

int main() {
    int n;
    long long sum;
    cin >> n >> sum;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<long long>> dp(n, vector<long long>(sum + 1, -1));

    int ans = f(0, sum, arr, n, dp);
    if (ans == INT_MAX)
        cout << -1 << endl; 
    else
        cout << ans << endl;

    return 0;
}
