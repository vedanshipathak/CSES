#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Forward prefix minimum
    vector<long long> pre_min(n);
    pre_min[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pre_min[i] = min(pre_min[i - 1], arr[i]);
    }

    // Backward prefix minimum
    vector<long long> post_min(n);
    post_min[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        post_min[i] = min(post_min[i + 1], arr[i]);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            cout << pre_min[b - 1] << endl;
        } else if (b == n) {
            cout << post_min[a - 1] << endl;
        } else {
            cout << min(post_min[a - 1], pre_min[b - 1]) << endl;
        }
    }

    return 0;
}
