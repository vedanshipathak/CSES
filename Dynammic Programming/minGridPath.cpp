#include <bits/stdc++.h>
using namespace std;

string solve(int i,int j,vector<vector<char>>&grid,vector<vector<string>>&dp,int n)
{
    //base case
    if(i==n-1 && j==n-1)return string(1,grid[i][j]);
    if(i>=n || j>=n)return "~" ;
    if(dp[i][j]!=".")return dp[i][j];
    
    string right=solve(i,j+1,grid,dp,n);
    string down=solve(i+1,j,grid,dp,n);
    
    return dp[i][j]=grid[i][j]+min(right,down);
    
}
int main() {
	// your code goes here
	int n,m;
	cin>>n;
	vector<vector<char>>grid(n,vector<char>(n));
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>grid[i][j];
	
	vector<vector<string>>dp(n,vector<string>(n,"."));
	string ans=solve(0,0,grid,dp,n);
	cout<<ans<<endl;
	
	return 0;

}
//space optimize