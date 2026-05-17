#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    // State: dp[i][j] = no. of ways to reach from (0, 0) to (i, j)

    // Transition: only moving right or down is allowed
    // move right: dp[i][j - 1] contributes
    // move down: dp[i - 1][j] contributes

    // Base Case: dp[0][0] = 1 i.e. we start from (0, 0)

    // Final Subproblem: dp[n - 1][n - 1]

    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == '*')
                continue;

            if (i == 0 && j == 0)
                continue;

            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;

            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[n - 1][n - 1];

    // Time Complexity: O(n * n)
    // Space Complexity: O(n * n)
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
}