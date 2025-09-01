#include <bits/stdc++.h> // All header file.
using namespace std;

int main()
{
    string s1, s2; // Declear 2 strings input in scquesnce.

    while (getline(cin, s1) && getline(cin, s2)) // Using while loop and and input 2 variables.
    {
        int n = s1.size(); // First string of length : n
        int m = s2.size(); // 2nd string of leangth : m

        int LCS[1001][1001]; // store lengths of LCS

        // Initializeing first column of DP table to 0
        for (int i = 0; i <= n; i++)
        {
            LCS[i][0] = 0; // LCS with empty string is 0
        }

        // Initializeing first row of DP table to 0
        for (int j = 0; j <= m; j++)
        {
            LCS[0][j] = 0; // LCS with empty string is 0
        }

        // Building the DP table using bottom-up approach
        for (int i = 1; i <= n; i++) // loop for each character of s1
        {
            for (int j = 1; j <= m; j++) // loop for each character of s2
            {
                if (s1[i - 1] == s2[j - 1])            // Characters match
                    LCS[i][j] = 1 + LCS[i - 1][j - 1]; // increase LCS by 1
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]); // Taking max of ignoring one char from either string
            }
        }
        cout << LCS[n][m] << endl; // printing the length of LCS
    }
    return 0;
}
