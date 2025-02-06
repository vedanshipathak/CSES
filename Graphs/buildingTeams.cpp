
#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<int>& color, int ic, vector<int> adj[], bool &ans) {
    queue<int> q;
    q.push(node);
    color[node] = ic; 
    while (!q.empty()) {
        int nn = q.front();
        q.pop();
       
        for (auto it : adj[nn]) {
            if (color[it] == -1) {
                color[it] = 1 - color[nn]; 
                q.push(it);
            } else if (color[it] == color[nn]) {
                ans = false;
                return; 
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) { 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

   
    vector<int> color(n + 1, -1);
    bool ans = true;
   
    for (int i = 1; i <= n; i++) {  
        if (color[i] == -1) {
            bfs(i, color, 0, adj, ans);  
            if (!ans) break;  
        }
    }

    if (ans == false) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 1; i <= n; i++) {  
            if (color[i] == 0)
                cout << 1 << " ";
            else
                cout << 2 << " ";
        }
        cout << endl;
    }
}
