#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        vector<int> price(N), weight(N);
        for(int i = 0; i < N; i++) cin >> price[i] >> weight[i];

        int G;
        cin >> G;
        vector<int> MW(G);
        for(int i = 0; i < G; i++) cin >> MW[i];

        int totalValue = 0;

        // প্রতিটি person এর জন্য আলাদা knapsack solve
        for(int p = 0; p < G; p++) {
            int cap = MW[p];
            vector<int> dp(cap + 1, 0); // dp array reset

            for(int i = 0; i < N; i++) {
                for(int w = cap; w >= weight[i]; w--) {
                    dp[w] = max(dp[w], dp[w - weight[i]] + price[i]);
                }
            }

            totalValue += dp[cap]; // এই person এর max value add
        }

        cout << totalValue << endl;
    }

    return 0;
}
