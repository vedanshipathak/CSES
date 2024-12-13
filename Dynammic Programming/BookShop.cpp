// this question is a copy of 0-1 knapsack i.e you just neeed to impplement 0-1 knapsack
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int maxWt;
  cin>>maxWt;
  vector<int>wt(n);
  vector<int>val(n);
  for(int i=0;i<n;i++)
  {
    cin>>wt[i]>>val[i];
   
  }
  //create the dp for change var
  int dp[n+1][maxWt+1];
  //initialize the dp
  for(int i=0;i<n+1;i++)
    {
      for(int j=0;j<maxWt+1;j++)
      {
        if(i==0||j==0)
        dp[i][j]=0;
      }
    }
    for(int i=1;i<n+1;i++)
    {
      for(int j=1;j<maxWt+1;j++)
      {
        if(wt[i-1]<=j)
        dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
        else
        dp[i][j]=dp[i-1][j];
      }
    }
    cout<<dp[n][maxWt]<<endl;
  }



  

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     int n,x;
//     cin>>n>>x;

//     vector<int> page(n),price(n);
//     int a,b;

//     for(int&i : price)
//     cin>>i;

//     for(int&i : page)
//     cin>>i;

//     vector<vector<int>> dp(n+1,vector<int>(x+1,0));

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=x;j++)
//         {
//             //option1 = book number i-1 is not included, hence no pages added.
//             //option2 = book number i-1 is included, hence pages are added.
//             //option1 = dp[i-1][j] ...book not included so total price(j) remains same.
//             //option2 = dp[i-1][j-price[i-1]] + page[i-1]....total price(j) decreased and pages are counted for book i-1.
            
//             dp[i][j] = dp[i-1][j];
//             if(j >= price[i-1])
//             {
//                 dp[i][j] = max (dp[i][j],dp[i-1][j-price[i-1]] + page[i-1]); //max of both the boxes included in dp[i][j]. 
//             }
//         }
//     }

//     cout<< dp[n][x] <<endl;

//     return 0;
// }