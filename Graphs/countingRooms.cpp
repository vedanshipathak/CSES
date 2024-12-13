#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int drow[],int dcol[],int i,int j)
{ int n=grid.size();
int m=grid[0].size();
  vis[i][j]=1;
  //traverse te neighbors
  for(int d=0;d<4;d++)
  {
    int dr=drow[d]+i;
    int dc=dcol[d]+j;
    if(dr>=0 &&dr<n && dc>=0 &&dc<m && !vis[dr][dc] && grid[dr][dc]=='.')
    dfs(grid,vis,drow,dcol,dr,dc);
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
  //apply the number of provinces alorithm 
  //for each dot complete the entire dfs
  int drow[]={1,0,-1,0};
  int dcol[]={0,-1,0,1};
  vector<vector<int>>vis(n,vector<int>(m,0));
  int c=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(!vis[i][j] && grid[i][j]=='.')
      {
        dfs(grid,vis,drow,dcol,i,j); 
        c++;
      }
    }
  }
  cout<<c<<endl;
}