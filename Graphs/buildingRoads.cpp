#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&vis,vector<int>adj[])
{
  vis[node]=1;
  for(auto it:adj[node])
  {
    if(!vis[it])
    {
      dfs(it,vis,adj);
    }
  }
}
int main()
{
  int n,m;
  cin>>n>>m;
  //create an adjacency list 
  vector<int>adj[n+1];
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);

  }
  //now count the connected components
  vector<int>vis(n+1,0);
  int cnt=0;
  vector<int>path;
  for(int i=1;i<=n;i++)
  {
     if(!vis[i])
     { path.push_back(i);
       dfs(i,vis,adj);
       cnt++;
     }
  }
  if(cnt==1)
  {
    cout<<0<<endl;
  }
  else
  {
    cout<<cnt-1<<endl;
    for(int i=1;i<path.size();i++)
    {
      cout<<path[i-1]<<" "<<path[i]<<endl;
    }
  }
    return 0;
}