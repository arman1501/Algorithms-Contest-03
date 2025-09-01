//D Edit Distance.
#include <bits/stdc++.h>
using namespace std;

// Function use kore minimum number ta ber korci.
int Min (int a, int b, int c)
{
    return min(a, min(b, c));
}

// two string এer moddhe minimum koto gula operation (Insert, Delete, Replace) lagbe ta ber kora.
int edit(string A, string B)
{
    int n = A.size();       // Length of A.
    int m = B.size();       // Length of B.

    
    // Using vector and edit distance minimum operation.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Using base case in loop.
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;   // If empty B then delete all.
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;   // If empty A then insert all
    }

    //Using nested loop and fill the table.
    for (int i = 1; i <= n; i++)        // Inner loop using.    
    {
        for (int j = 1; j <= m; j++)    // Outer loop using.
        {
            if (A[i - 1] == B[j - 1])   // Condition use.
            {
                dp[i][j] = dp[i - 1][j - 1]; // If same operator then no operation.
            }
                
            else
            {
                dp[i][j] = 1 + Min(
                dp[i - 1][j],        // delete operation
                dp[i][j - 1],        // insert operation
                dp[i - 1][j - 1]    // replace operation.
                );
            }        
        }
    }
    return dp[n][m];    //Final ans.   
}



int main()
{
    int t;
    cin >> t;       // number of test cases.
    while (t--)     // Using while loop for test case.
    {
        string a, b;        // Denote string type variables.
        cin >> a >> b;
        cout << edit(a, b) << " ";      //Print output.
    }
    return 0;
}
