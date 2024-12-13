#include<bits/stdc++.h>
using namespace std;

int main() {
    const int MOD = 1e9 + 7;
    vector<int> dice;

    // Dice faces from 1 to 6
    for (int i = 1; i <= 6; i++) 
        dice.push_back(i);
    
    int n = dice.size(); // Number of dice outcomes (1 to 6)
    int sum;
    cin >> sum;

    // Declare the DP array
    int dp[n + 1][sum + 1];

    // Initialize the DP array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) {
                dp[i][j] = 1;  // There's one way to make sum 0 (by not throwing any dice)
            } else if (i == 0) {
                dp[i][j] = 0;  // No way to make any positive sum with zero dice outcomes
            }
        }
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // Initially take the value from the previous row (not using the current dice face)
            dp[i][j] = dp[i - 1][j];

            // If the current dice face can contribute to the sum, include it
            if (dice[i - 1] <= j) {
                dp[i][j] = (dp[i][j] + dp[i][j - dice[i - 1]]) % MOD;
            }
        }
    }

    // The answer will be in dp[n][sum], where n is the number of dice outcomes
    cout << dp[n][sum] << endl;

    return 0;
}
