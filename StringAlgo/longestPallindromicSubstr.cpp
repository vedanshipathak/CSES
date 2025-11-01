#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool isPallindrome(ll i,ll j,string &s,vector<vector<ll>>&dp)
{
    //base case
    if(i>=j)return true;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]!=s[j])return (dp[i][j]=0);

    return (dp[i][j]=isPallindrome(i+1,j-1,s,dp));
}
string longestPallindromicSubstr(string str)
{
    ll n=str.size();
    //start index and max length of string 
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
    ll start=0,maxLen=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=i;j<n;j++)
        {
            if(isPallindrome(i,j,str,dp))
            {
                if(j-i+1>maxLen)
                {
                    maxLen=j-i+1;
                    start=i;
                }
            }
        }
    }
    return str.substr(start,maxLen);
}
int main()
{
    string str;
    cin>>str;

    cout<<longestPallindromicSubstr(str)<<endl;
    return 0;
}