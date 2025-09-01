#include <iostream>   // For cin, cout.
#include <string>     // For string.
#include <sstream>    // For stringstream.
#include <algorithm>  // For max function.
using namespace std;

int main()          // Main fucntion.
{
    string li;      // Full line newar variable.

    while (getline(cin, li))     //Input multiple test case use in while loop.
    {
        if(li.empty())      // If line empty then skip this line.
        {
            continue;
        }

        string s1, s2;      // Declear 2 string type variables.
        stringstream ss(li);    // String line k akta stringstrem e convert kora.
        ss >> s1 >> s2;

        int n = s1.size();      // 1st string er length define.
        int m = s2.size();      // 2nd string er length define.

        int LCS[n + 1][m + 1];     // LCS table create korci.

        // Initial:
        for (int i = 0; i <= n; i++)
        {
            LCS[i][0] = 0;      // Using loop and initial row and column.
        }

        for (int j = 0; j <= m; j++)
        {
            LCS[0][j] = 0;      // Using loop and initial row and column.
        }
            

        // DP table fillup korci.
        for (int i = 1; i <= n; i++)        // Using nested loop.
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])     // Using condition and check.
                {
                    LCS[i][j] = 1 + LCS[i - 1][j - 1];  // Jodi character match hoi taile diogonal +1 kore dibo.
                }
                else
                {
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);      // Jodi character match na hoi taile top or left max hbe.
                }
            }
        }
 
        cout << LCS[n][m] << endl;       // LCS length print.
    }

    return 0;
}
