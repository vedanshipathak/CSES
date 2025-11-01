#include <bits/stdc++.h>
using namespace std;

struct Node {
    struct Node* left;
    struct Node* right;
    int data;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int findDiameter(Node* root, vector<int>& ans) {
    if (root == NULL) return 0;
    
    int lh = findDiameter(root->left, ans);
    int rh = findDiameter(root->right, ans);
      ans[root->data]=lh + rh;

    return 1 + max(lh, rh);
}

Node* createTree(int n, vector<int>& parent) {
    vector<Node*> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    Node* root = nodes[1]; // root is always 1

    for (int i = 0; i < n - 1; i++) {
        int p = parent[i];   // boss
        int child = i + 2;   // employee id
        Node* parNode = nodes[p];
        if (!parNode->left)
            parNode->left = nodes[child];
        else
            parNode->right = nodes[child];
    }

    return root;
}

int main() {
    int n;
    cin >> n;

    vector<int> parent;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        parent.push_back(x);
    }
    Node* root = createTree(n, parent);

    vector<int> ans(n+1);
    findDiameter(root, ans);

    for (int i=1;i<n+1;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
