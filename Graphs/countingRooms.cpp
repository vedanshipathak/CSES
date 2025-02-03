#include<bits/stdc++.h>
using namespace std;
void dfs(int r,int c,vector<vector<char>>&grid,int drow[],int dcol[],int n,int m)
{
  grid[r][c]='#';
  //traverse the neigbhors
  for(int i=0;i<4;i++)
  {
    int dr=drow[i]+r;
    int dc=dcol[i]+c;
    if(dr>=0 && dc>=0 && dr<n && dc<m && grid[dr][dc]=='.')
    {
      dfs(dr,dc,grid,drow,dcol,n,m);
    }
  }
}
void dfsCheck(int r,int c,vector<vector<char>>&grid,int drow[],int dcol[],int n,int m,vector<vector<int>>&vis)
{
  vis[r][c]=1;
  //traverse the neigbhors
  for(int i=0;i<4;i++)
  {
    int dr=drow[i]+r;
    int dc=dcol[i]+c;
    if(dr>=0 && dc>=0 && dr<n && dc<m && grid[dr][dc]=='.' && !vis[dr][dc])
    {
      dfs(dr,dc,grid,drow,dcol,n,m);
    }
  }
}
int main()
{
   int n, m;
   cin>>n>>m;
  vector<vector<char>>grid(n,vector<char>(m));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>grid[i][j];
    }
  }
  //if they are at the egdes then they cannot be covered by walls i.e # therefor conver all floor present on edge to walls
  int drow[]={1,0,-1,0};
  int dcol[]={0,1,0,-1};
  for(int i=0;i<n;i++)
  {if(grid[i][0]=='.')
    dfs(i,0,grid,drow,dcol,n,m);
    if(grid[i][m-1]=='.')
    dfs(i,m-1,grid,drow,dcol,n,m);
  }
  for(int i=0;i<m;i++)
  {  if(grid[0][i]=='.')
    dfs(i,0,grid,drow,dcol,n,m);
    if(grid[n-1][i]=='.')
    dfs(i,m-1,grid,drow,dcol,n,m);
  }
  //now find the no of provinces of floors 
  int c=0;
  vector<vector<int>>vis(n,vector<int>(m,0));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(!vis[i][j] && grid[i][j]=='.')
      {
        dfsCheck(i,j,grid,drow,dcol,n,m,vis);
        c++;
      }
    }
  }
  cout<<c<<endl;
}