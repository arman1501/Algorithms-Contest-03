#include <bits/stdc++.h> // All header file.
using namespace std;

int main()
{
    int t;
    cin >> t; // Declear a variable and input users.

    while (t--) // All test case er jonne loop cholbe.
    {
        int n;
        cin >> n; // Declear item number input from users.

        vector<int> price(n), weight(n); // Using veetor for all items and price weight .

        // Use for loop for all items input from users.
        for (int i = 0; i < n; i++)
        {
            cin >> price[i] >> weight[i];
        }

        int v;
        cin >> v;          // Define total people and input from users.
        vector<int> MW(v); // Per people maximum weight capacity (MW) input.

        // Use for loop for all people weight input from users.
        for (int i = 0; i < v; i++)
        {
            cin >> MW[i];
        }

        int totalValue = 0; // Sob people er jonne total value.

        // Per person er jonne alada alada knapsack solve hbe
        for (int p = 0; p < v; p++)
        {
            int cap = MW[p];            // Maximum capacity for people.
            vector<int> dp(cap + 1, 0); // DP array reset

            // Using loop and ulta dik theke capacity komanu hoice.
            for (int i = 0; i < n; i++)
            {
                for (int j = cap; j >= weight[i]; j--)
                {
                    dp[j] = max(dp[j], dp[j - weight[i]] + price[i]);
                }
            }

            totalValue += dp[cap]; // Ei person er max value add
        }

        cout << totalValue << endl; // printing the output.
    }

    return 0;
}
