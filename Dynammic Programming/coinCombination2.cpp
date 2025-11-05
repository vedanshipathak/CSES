#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
int solve(int i,long long sum,long long n,vector<long long>&arr,vector<vector<long long>>&dp)
{
    //base
    if(sum==0)return 1;
    if(i>=n || sum<0)return 0;
    if(dp[i][sum]!=-1)return dp[i][sum];
    int ch=0;
    if(arr[i]<=sum)
    ch=solve(i,sum-arr[i],n,arr,dp)%MOD;
    
    int nc=solve(i+1,sum,n,arr,dp)%MOD;
    
    return dp[i][sum]=(ch+nc)%MOD;
    
}
int main()
{
    long long n;long long sum;
    cin>>n>>sum;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    // vector<vector<long long>>dp(n+1,vector<long long>(sum+1,-1));
    // cout<<solve(0,sum,n,arr,dp);
    
    
    //convert the base into the 
    vector<vector<long long>>dp(n+1,vector<long long>(sum+1,0));
    
    for(long long i=0;i<=n;i++)
    dp[i][0]=1;
    
    for(long long i=n-1;i>=0;i--)
    {
        for(long long s=1;s<=sum;s++)
        {
            long long take=0,not_take=0;
            if(arr[i]<=s)
            take=dp[i][s-arr[i]]%MOD;
            not_take=dp[i+1][s]%MOD;
            
            dp[i][s]=(take+not_take)%MOD;
        }
    }
     cout<<dp[0][sum]%MOD<<endl;
   
}
