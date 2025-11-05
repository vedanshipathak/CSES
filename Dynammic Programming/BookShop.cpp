// // this question is a copy of 0-1 knapsack i.e you just neeed to impplement 0-1 knapsack
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//   int n;
//   cin>>n;
//   int maxWt;
//   cin>>maxWt;
//   vector<int>wt(n);
//   vector<int>val(n);
//   for(int i=0;i<n;i++)
//   {
//     cin>>wt[i]>>val[i];
   
//   }
//   //create the dp for change var
//   int dp[n+1][maxWt+1];
//   //initialize the dp
//   for(int i=0;i<n+1;i++)
//     {
//       for(int j=0;j<maxWt+1;j++)
//       {
//         if(i==0||j==0)
//         dp[i][j]=0;
//       }
//     }
//     for(int i=1;i<n+1;i++)
//     {
//       for(int j=1;j<maxWt+1;j++)
//       {
//         if(wt[i-1]<=j)
//         dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
//         else
//         dp[i][j]=dp[i-1][j];
//       }
//     }
//     cout<<dp[n][maxWt]<<endl;
//   }



//   #include <bits/stdc++.h>
// using namespace std;
// int MOD=1e9+7;

// int solve(int i, int x,vector<int>&price,vector<int>&pgs,int n,vector<vector<int>>&dp)
// {
//     //base case
//     if(i>=n || x<0)return 0;
    
//     if(dp[i][x]!=-1)return dp[i][x];
    
//     //choose 
//     int choose=INT_MIN;
//     if(price[i]<=x)
//     {
//         int c=solve(i+1,x-price[i],price,pgs,n,dp);
//         if(c!=INT_MIN)
//         choose=c+pgs[i];
//     }
//     int not_choose=solve(i+1,x,price,pgs,n,dp);
    
//     return dp[i][x]=max(choose,not_choose);
    
    
// }
// int main() {
// 	// your code goes here
//     int n,x;
//     cin>>n>>x;
//     vector<int>price(n);
//     vector<int>pgs(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>price[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         cin>>pgs[i];
//     }
 
//     vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
//     cout<<solve(0,x,price,pgs,n,dp)<<endl;
// }


  #include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n,x;
    cin>>n>>x;
    vector<int>price(n);
    vector<int>pgs(n);
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>pgs[i];
    }
 
    vector<vector<long long>>dp(n+1,vector<long long>(x+1,LLONG_MIN));
    dp[n][0]=0;
    for(int i=n;i>=0;i--)
    {
        dp[i][0] = 0;//you never assign values for dp[i][0] when i < n. So, you need to set it to 0 here.
      for(int j=1;j<=x;j++)
      {
        long long choose=LLONG_MIN;
        if(price[i]<=j)
        {
            long long c=dp[i+1][j-price[i]];
            if(c!=LLONG_MIN)
            choose=c+pgs[i];
        }
        long long not_choose=dp[i+1][j];
        
        dp[i][j]=max(choose,not_choose);
      }
    }
       if(dp[0][x] == LLONG_MIN) cout<<0<<endl;
       else // 
   cout<<dp[0][x]<<endl;
}