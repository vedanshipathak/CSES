#include <bits/stdc++.h>
using namespace std;
int f(int i,vector<int>&arr,int n,vector<int>&dp)
{
    //base condn
     if (i == n - 1) return 0;
    if(i>=n)return INT_MAX;
    //precompute check
    if(dp[i]!=-1)return dp[i];
    int c1=abs(arr[i]-arr[i+1])+f(i+1,arr,n,dp);
    int c2=INT_MAX;
    if(i+2<n)
    c2=abs(arr[i]-arr[i+2])+f(i+2,arr,n,dp);
    return dp[i]=min(c1,c2);
}
int main() {
	// your code goes here
   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++)
   cin>>arr[i];
   
   vector<int>dp(n,-1);
   
   cout<<f(0,arr,n,dp)<<endl;

}