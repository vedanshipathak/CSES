#include<bits/stdc++.h>
using namespace std;
class Dp{
    public:
    int MOD=1e9+7;
    private:
   int solve(int target,vector<int>&dp) {
    if (target == 0) return 1;
    if (target < 0) return 0;
   
    int ways = 0;
    for (int i = 1; i <= 6; i++) {
        if(dp[i]!=-1)return dp[i];
       dp[i] += solve(target - i,dp);
    }
    return dp[6];
}

    public:
    int findCombination(int target)
    {
        vector<int>dp(7,-1);
        return solve(target,dp);
    }
};
int main()
{
 
    Dp obj;
    int target;
    cin>>target;
    cout<<obj.findCombination(target)<<endl;
}