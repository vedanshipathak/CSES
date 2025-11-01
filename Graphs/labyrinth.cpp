#include<bits/stdc++.h>
using namespace std;
void bfs(int r,int c,int n,int m,vector<vector<char>>&grid,int dest_row,int dest_col)
{
    queue<pair<int,int>>q;
    vector<vector<int>>dist(n,vector<int>(m,-1));
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<pair<pair<int,int>,char>>>parent(n,vector<pair<pair<int,int>,char>>(m,{{-1,-1},'.'}));
    q.push({r,c});
    dist[r][c]=0;
    vis[r][c]=1;
    int drow[]={1,0,-1,0};
    int dcol[]={0,-1,0,1};
    string dir="DLUR";
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int dr=drow[i]+row;
            int dc=dcol[i]+col;
            char d=dir[i];
            if(dr>=0 && dc>=0 && dr<n && dc<m && !vis[dr][dc] && (grid[dr][dc]=='.' || grid[dr][dc]=='B'))
            {
                if(dist[dr][dc]==-1)
                {
                    dist[dr][dc]=dist[row][col]+1;
                    parent[dr][dc]={{row,col},d};
                    q.push({dr,dc});
                    vis[dr][dc]=1;
                }
            }
        }

    }
    if(dist[dest_row][dest_col]!=-1)
    {
        vector<char>path;
        int r=dest_row,c=dest_col;
        while(r!=-1 && c!=-1)
        {
          char move = parent[r][c].second;
          path.push_back(move);

           r=parent[r][c].first.first;
           c=parent[r][c].first.second;

        }
        reverse(path.begin(),path.end());
        for(auto it:path)
        cout<<it<<" ";
        cout<<endl;

    }
    else
    cout<<"IMPOSSIBLE"<<endl;

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    int src_row=0,src_col=0;
    int dest_row=0,dest_col=0;
      //find the source and destn coordinates
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A')
            {
                src_row=i;
                src_col=j;
            }
            if(grid[i][j]=='B')
            {
                dest_row=i;
                dest_col=j;
            }
        }
    } 

    //now apply bfs
    bfs(src_row,src_col,n,m,grid,dest_row,dest_col);
  

  return 0;
    
}