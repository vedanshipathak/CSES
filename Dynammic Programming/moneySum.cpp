#include <bits/stdc++.h>
using namespace std;

void solve(int i, int sum, set<int>& ss, vector<int>& arr, int n, vector<vector<bool>>& vis)
{
    ss.insert(sum);
    if(i >= n) return;
    //why we use vis becasue without vis we will get TLE as we will be calculating same state again and again
    //for example if we have arr={1,2,3} then for sum=3 we can get it by (1+2) or just 3 so we will be calculating same state again and again
    if(vis[i][sum]) return;
    vis[i][sum] = true;

    solve(i + 1, sum + arr[i], ss, arr, n, vis);
    solve(i + 1, sum, ss, arr, n, vis);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;

    int maxSum = accumulate(arr.begin(), arr.end(), 0);

    //in this question we are using bool instead int beccause we just need to check if we have already vidsited that state or not , we use int only when we need to store the states
    vector<vector<bool>> vis(n+1, vector<bool>(maxSum+1, false));
    set<int> ss;

    solve(0, 0, ss, arr, n, vis);

    ss.erase(0);

    cout << ss.size() << "\n";
    for(int x : ss) cout << x << " ";
    cout << "\n";

    return 0;
}
