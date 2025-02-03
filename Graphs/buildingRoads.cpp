#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int n,int m,vector<int>adj[],vector<int>&vis)
{
  vis[node]=1;
  //traverse the neighbors
  for(auto it:adj[node])
  {
    if(!vis[it])
    {
      dfs(it,n,m,adj,vis);
    }
  }
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<int>adj[n+1];
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  //find the no of connected componenets
  vector<int>vis(n+1,0);
   vector<int> representatives;
  int c=0;
  for(int i=1;i<=n;i++)
  {
     if(!vis[i])
     {  representatives.push_back(i);
      dfs(i,n,m,adj,vis);
      c++;
     }
  }
  cout<<c-1<<endl;
  for (int i = 1; i < representatives.size(); i++) {
        cout << representatives[i - 1] << " " << representatives[i] << endl;
    }
}