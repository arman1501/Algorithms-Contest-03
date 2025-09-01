#include <bits/stdc++.h> // All header file.
using namespace std;

int main()
{
    int c[] = {50, 25, 10, 5, 1}; // coin types
    int DP[7490] = {0};           // array to store number of ways
    DP[0] = 1;                    // base case: 0 amount → 1 way

    // DP filling for nested loop.
    for (int i = 0; i < 5; i++)
    {
        for (int j = c[i]; j <= 7489; j++)
        {
            DP[j] += DP[j - c[i]];
        }
    }

    int v;           // declear a variables.
    while (cin >> v) // Using while loop.
    {
        cout << DP[v] << endl; // Printing a results.
    }

    return 0;
}
