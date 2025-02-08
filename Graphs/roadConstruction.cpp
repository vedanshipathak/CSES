#include<bits/stdc++.h>
using namespace std;
class Disjoint{
public:
vector<int>parent,size;
Disjoint(int n)
{
  parent.resize(n+1);
  size.resize(n+1);
  for(int i=0;i<=n;i++)
  {
    parent[i]=i;
    size[i]=1;
  }

}
int findP(int node)
{
  if(node==parent[node])return node;
  return parent[node]=findP(parent[node]);
}
void unionSize(int u,int v)
{
  int pu=findP(u);
  int pv=findP(v);
  if(pu==pv)return;
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
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>>adj;
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj.push_back({u,v});
  }
  Disjoint ds(n);
  int comp=n;
  int maxi=1;//max component size is 1
  for(int i=0;i<m;i++)
  {
     int u=adj[i].first;
     int v=adj[i].second;
     
     if(ds.findP(u)!=ds.findP(v))
     {  ds.unionSize(u,v);
        comp--;
        cout<<comp<<" ";
        maxi=max(maxi,ds.size[ds.findP(u)]);
        cout<<maxi<<endl;
     }
     else
     {cout<<comp<<" ";
       cout<<maxi<<endl;
     }
  }
}