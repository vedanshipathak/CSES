#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& arr)
{
    sort(arr.begin(), arr.end()); 
    for (int i = 1; i < n; i++) 
    {
        if (i != arr[i - 1]) 
        {
            return i;
        }
    }
    return n;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    cout << solve(n, arr) << endl;
    return 0;
}
