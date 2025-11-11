#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
int solve(int i,int n ,int sum,vector<vector<int>>&dp)
{
    //base case
    if(i>n ||sum<0)return 0;
    if(sum==0)return 1;
    
     if(dp[i][sum]!=-1)return dp[i][sum];
     int take=0;
    if(i<=sum)
    {
      take=solve(i+1,n,sum-i,dp)%MOD;
      
    }
    int not_take=solve(i+1,n,sum,dp)%MOD;
    
    return dp[i][sum]=(take+not_take)%MOD;
    
}
int main() {
	// your code goes here
    int n;
    cin>>n;
    
    long sum=0;
    for(int i=1;i<=n;i++)
    sum+=i;
    
    
    
    if(sum%2==1)
    cout<<0<<endl;
    else
    {  
        int s=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(s+1,-1));
        cout<<solve(1,n,s,dp)<<endl;
        
    }
    return 0;
}