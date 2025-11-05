// #include <bits/stdc++.h>
// using namespace std;
// int MOD=1e9+7;
// int solve(int n,long long sum,vector<long long>&arr,vector<long long>&dp)
// {
//     //base case
//     if(sum==0)return 1;
//     if(sum<0 )return 0;
    
//     if(dp[sum]!=-1)return dp[sum];
//     int c=0;
//     for(int j=0;j<n;j++)
//     {
       
        
//             c=(c+solve(n,sum-arr[j],arr,dp))%MOD;
        
        
//     }

    
//     return dp[sum]=c;
    
// }

// int main() {
// 	// your code goes here
//     int n;long long sum;
//     cin>>n>>sum;
//     vector<long long>arr(n);
//     for(int i=0;i<n;i++)
//     cin>>arr[i];
//     vector<long long>dp(sum+1,-1);
//     cout<<solve(n,sum,arr,dp);
    
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> dp(target + 1, 0);
    dp[0] = 1; // one way to make sum 0

    for (int i = 1; i <= target; i++) {
        long long ways = 0;
        for (int num : arr) {
            if (i >= num) {
                ways += dp[i - num];
                if (ways >= MOD) ways -= MOD;
            }
        }
        dp[i] = ways;
    }

    cout << dp[target];
    return 0;
}
