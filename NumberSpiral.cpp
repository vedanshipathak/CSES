#include<iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    
    while (t--) {
        long long y, x;
        cin >> y >> x;
        
        if (y >= x) {
            // Case where row y is dominant
            if (y % 2 == 0) {
                cout << (y * y - (x - 1)) << "\n";
            } else {
                cout << ((y - 1) * (y - 1) + x) << "\n";
            }
        } else {
            // Case where column x is dominant
            if (x % 2 == 1) {
                cout << (x * x - (y - 1)) << "\n";
            } else {
                cout << ((x - 1) * (x - 1) + y) << "\n";
            }
        }
    }
    return 0;
}
