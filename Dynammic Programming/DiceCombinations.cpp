#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
int solve(int sum,vector<int>&dp)
{
    //base 
    if(sum==0)return 1;
    
    if(sum<0)return 0;
    if(dp[sum]!=-1)return dp[sum];
    int c=0;
    for(int i=1;i<=6;i++)
    {
        c=(c+solve(sum-i,dp))%MOD;//here (c+solve()) should be written than c+=solve() because c can exceed the limit of int}
    }
    return dp[sum]=c;
}
int main() {
	// your code goes here

   int sum;
   cin>>sum;
   vector<int>dp(sum+1,-1);

   cout<<solve(sum,dp);
}
