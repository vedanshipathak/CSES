#include <bits/stdc++.h>
using namespace std;
int f(int i,int k,vector<int>&arr,int n,vector<int>&dp)
{
    //base condn
     if (i == n - 1) return 0;
    if(i>=n)return INT_MAX;
    //precompute check
    if(dp[i]!=-1)return dp[i];
     int c2=INT_MAX;int mini=INT_MAX;
    for(int x=1;x<=k;x++)
    {
         if(i+x<n)
    c2=abs(arr[i]-arr[i+x])+f(i+x,k,arr,n,dp);
    mini=min(mini,c2);
    }
  
    return dp[i]=mini;
}
int main() {
	// your code goes here
   int n,k;
   cin>>n>>k;
   vector<int>arr(n);
   for(int i=0;i<n;i++)
   cin>>arr[i];
   
   vector<int>dp(n,-1);
   
   cout<<f(0,k,arr,n,dp)<<endl;

}