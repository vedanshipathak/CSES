#include<bits/stdc++.h>
using namespace std;
class Disjoint{
 public:
 vector<long long>parent;
 vector<long long >size;
 Disjoint(long long n)
 {
  parent.resize(n+1);
  size.resize(n+1);
  for(long long i=0;i<=n;i++)
  {
    parent[i]=i;
    size[i]=1;
  }
 }
 long long findP(long long node)
 {
  if(node==parent[node])
  return node;
  return parent[node]=findP(parent[node]);
 }
 void unionSize(long long u,long long v)
 {
  long long pu=findP(u);
  long long pv=findP(v);
  if(pu==pv)return ;
  if(size[pu]<size[pv])
  {
    parent[pu]=pv;
    size[pv]+=size[pu];
  }
  else{
    parent[pv]=pu;
    size[pu]+=size[pv];
  }
 }
};
int main()
{
  long long n,m;
  cin>>n>>m;
  
  vector<pair<int,pair<int,int>>>adj;
  for(int i=0;i<m;i++)
  {
    long long u,v,wt;
    cin>>u>>v>>wt;
    adj.push_back({wt,{u,v}});
  }
  Disjoint ds(n);
  long long ans=0;
  sort(adj.begin(),adj.end());
  for(long long i=0;i<m;i++)
  {
    long long u=adj[i].second.first;
    long long v=adj[i].second.second;
    long long w=adj[i].first;
    if(ds.findP(u)==ds.findP(v))
    continue;
    else
    {
    ds.unionSize(u,v);
    ans+=w;
    n--;
    }
  }
  if(n==1)
  cout<<ans<<endl;
  else
  cout<<"IMPOSSIBLE"<<endl;
}