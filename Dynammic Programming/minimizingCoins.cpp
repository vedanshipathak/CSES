#include <bits/stdc++.h>
using namespace std;
using ll =long long;
int solve(ll i,ll n,ll x,vector<ll>&arr,vector<vector<ll>>&dp)
{
   //base case
    if(x==0)return 0;
      if(i>=n)return INT_MAX;
  
  if(dp[i][x]!=-1)return dp[i][x];

   ll choose=LLONG_MAX;
   if(arr[i]<=x)
   {int ch=solve(i,n,x-arr[i],arr,dp);
       if(ch!=LLONG_MAX)
       choose=ch+1;
   }
   ll nc=solve(i+1,n,x,arr,dp);
   
   return dp[i][x]=min(choose,nc);
}
int main() {
	// your code goes here

    ll n,x;
    cin>>n>>x;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    vector<vector<ll>>dp(n+1,vector<ll>(x+1,-1));
    
    int ans=(solve(0,n,x,arr,dp)==INT_MAX)?-1:solve(0,n,x,arr,dp);
    cout<<ans;
    
}

