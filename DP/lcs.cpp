#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int lcs(string &S1, string &S2) {
    int m = S1.size();
    int n = S2.size();

    // Initializing a matrix of size (m+1)*(n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Building dp[m+1][n+1] in bottom-up fashion
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // dp[m][n] contains length of LCS for S1[0..m-1]
    // and S2[0..n-1]
    return dp[m][n];
}