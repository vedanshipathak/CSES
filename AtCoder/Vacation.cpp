#include <bits/stdc++.h>
using namespace std;

// r = current day, lastCol = last activity done (0,1,2), 3 = no activity yet
int f(int r, int lastCol, vector<vector<int>>& arr, int n, vector<vector<int>>& dp) {
    if (r >= n) return 0;
    if (dp[r][lastCol] != -1) return dp[r][lastCol];

    int res = 0;
    for (int c= 0; c < 3; ++c) {
        if (c != lastCol) {
            res = max(res, arr[r][c] + f(r + 1, c, arr, n, dp));
        }
    }

    return dp[r][lastCol] = res;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    vector<vector<int>> dp(n, vector<int>(4, -1)); // 0,1,2 for A,B,C and 3 = no last activity

    // Start from day 0 with no previous activity
    int maxi = f(0, 3, arr, n, dp);
    cout << maxi << endl;

    return 0;
}
