#include <bits/stdc++.h>
using namespace std;
// int func(int n)
// {
//     if(n==0)
//     return 0;
//     int maxi=0;int temp=n;
//     while(temp!=0)
//     {
//         int d=temp%10;
//         maxi=max(maxi,d);
//         temp=temp/10;
//     }
//     return func(n-maxi)+1;
// }
// int main() {
// 	// your code goes here
// 	int n=7;
//     cout<<func(n);
// }
int main()
{
    int n;
    cin>>n;
    vector<long long>dp(n+1);
    dp[0]=0;
    for(long long  i=1;i<n+1;i++)
    {
        long long maxi=0;
        long long temp=i;
        while(temp!=0)
     {
        long long d=temp%10;
        maxi=max(maxi,d);
        temp=temp/10;
      }
      dp[i]=1+dp[i-maxi];
    }
    cout<<dp[n]<<endl;
}