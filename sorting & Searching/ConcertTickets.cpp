#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> tickets(n);
    for(int i = 0; i < n; i++) 
        cin >> tickets[i];

    vector<long long> maxPrice(m);
    for(int i = 0; i < m; i++) 
        cin >> maxPrice[i];

    // Sort tickets in ascending order
    sort(tickets.begin(), tickets.end());
    // Pair each max price with its original index to output results in correct order
    vector<pair<long long, int>> customer(m);
    for(int i = 0; i < m; i++) 
        customer[i] = {maxPrice[i], i};
    
    sort(customer.begin(), customer.end());

    // Result array to store the answer for each customer
    vector<long long> result(m, -1);

    int i = 0, j = 0;  // i for tickets, j for customers
    while(j < m && i < n) {
        // If current ticket price can be afforded by the customer
        if(tickets[i] <= customer[j].first) {
            // Store the ticket for this customer and move to the next ticket
            result[customer[j].second] = tickets[i];
            i++;
        } else {
            // Move to the next customer if no more tickets are affordable
            j++;
        }
    }

    // Output the result in the correct order
    for(int k = m-1; k >=0; k--) {
        cout << result[k] << endl;
    }

    return 0;
}
