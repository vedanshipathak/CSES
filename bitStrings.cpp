#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute (base^exp) % MOD using binary exponentiation
long long mod_pow(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd, multiply the current base with result
            result = (result * base) % mod;
        }
        base = (base * base) % mod;  // Square the base
        exp /= 2;  // Divide the exponent by 2
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    // Calculate 2^n % MOD using modular exponentiation
    long long ans = mod_pow(2, n, MOD);

    cout << ans << endl;

    return 0;
}
