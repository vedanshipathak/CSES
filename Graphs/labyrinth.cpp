#include <bits/stdc++.h>
using namespace std;

void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& dis, vector<vector<char>>& grid,string &str) {
    int n = grid.size();
    int m = grid[0].size();
    int drow[] = {1, 0, -1, 0};
    int dcol[] = {0, -1, 0, 1};
    string dir="RDLU";
    queue<pair<int, int>> q;
    q.push({r, c});
    vis[r][c] = 1;
    dis[r][c] = 0;
   
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse the neighbors
        for (int i = 0; i < 4; i++) {
            int dr = drow[i] + row;
            int dc = dcol[i] + col;
            char ch=dir[i];
            if (dr >= 0 && dr < n && dc >= 0 && dc < m && grid[dr][dc] != '#' && !vis[dr][dc]) {
                dis[dr][dc] = dis[row][col] + 1; 
                vis[dr][dc] = 1;
                q.push({dr, dc});
                str.push_back(ch);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    string str;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dis(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                bfs(i, j, vis, dis, grid,str);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B' && dis[i][j] != -1) {
                if (ans == -1 || dis[i][j] < ans) {
                    ans = dis[i][j];  
                }
            }
        }
    }

   
    if(ans!=-1)
    {   cout<<"YES"<<endl;
        cout << ans << endl;
        cout<<str<<endl;
    }
    else{
        cout<<"NO"<<endl;
        cout << ans << endl;
    }
    return 0;
}