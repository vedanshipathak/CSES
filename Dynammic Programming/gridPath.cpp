#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;

int solve(int i,int j,int n,vector<vector<char>>&arr,vector<vector<int>>&dp)
{
    //base case
    if(i>=n || j>=n ||arr[i][j]=='*')return 0;
    if(i==n-1 && j==n-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int right=0;
    if(j+1<n && arr[i][j+1]!='*')
    right=solve(i,j+1,n,arr,dp)%MOD;
    int down=0;
    if(i+1<n && arr[i+1][j]!='*')
    down=solve(i+1,j,n,arr,dp)%MOD;
    
    return dp[i][j]=(right+down)%MOD;
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<vector<char>>arr(n,vector<char>(n));
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    cin>>arr[i][j];
	}
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	cout<<solve(0,0,n,arr,dp)<<endl;
   
}
