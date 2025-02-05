#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int>adj[n+1];
  //creeate the adjacency list
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);

  }
  //now we have to calculate the shortest dis so bfs will come in handy
  vector<int>vis(n+1,0);
  vector<int>parent(n+1,0);
  vector<int>dis(n+1,INT_MAX);
  dis[0]=0;
  queue<int>q;
  q.push(1);
  vis[1]=1;
  while(!q.empty())
  {
     int x=q.front();
     q.pop();
     //traverse the adj list 
     for(auto it:adj[x])
     {
        if(!vis[it])
        {
          if(dis[it]==INT_MAX)
          {
            dis[it]=dis[x]+1;
            parent[it]=x;
            vis[it]=1;
            q.push(it);
          }
        }
     }
  }
  if(dis[n]==INT_MAX)
  cout<<"IMPOSSIBLE"<<endl;
  else{
    vector<int>ans;
    ans.push_back(n);
    while(ans.back()!=1)
    {
      ans.push_back(parent[ans.back()]);
    }
    reverse(ans.begin(),ans.end());
     cout<<ans.size()<<endl;
    for(auto it:ans)
    cout<<it<<" ";
  }
}