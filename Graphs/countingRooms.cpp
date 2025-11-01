#include<bits/stdc++.h>
using namespace std;

void dfs(int r,int c,vector<vector<char>>&grid,vector<vector<int>>&vis,int drow[],int dcol[],int n,int m)
{
   vis[r][c]=1;
   for(int i=0;i<4;i++)
   {
    int dr=r+drow[i];
    int dc=c+dcol[i];
    if(dr>=0 && dc>=0 && dr<n && dc<m && !vis[dr][dc] && grid[dr][dc]=='.')
    dfs(dr,dc,grid,vis,drow,dcol,n,m);
   }
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<char>>grid(n,vector<char>(m));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>grid[i][j];
    }
  }

  int drow[]={1,0,-1,0};
  int dcol[]={0,-1,0,1};

  //now traverse and count the no of provinces
  vector<vector<int>>vis(n,vector<int>(m,0));
  int c=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(grid[i][j]=='.' && !vis[i][j])
      {
        dfs(i,j,grid,vis,drow,dcol,n,m);
        c++;
      }
    }
  }
  cout<<c<<endl;
  return 0;
}