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

    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
        cout << 0;
        return;
    }

    // State: dp[i][j] = no. of ways to reach from (i, j) to (n - 1, n -1)

    // Transition: only moving right or down is allowed
    // move left: dp[i][j + 1] contributes
    // move up: dp[i + 1][j] contributes

    // Base Case: dp[n - 1][n - 1] = 1 i.e. we start from (n - 1, n - 1)

    // Final Subproblem: dp[0][0]

    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {

            if (grid[i][j] == '*')
                continue;

            if (i == n - 1 && j == n - 1)
                continue;

            if (i < n - 1)
                dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;

            if (j < n - 1)
                dp[i][j] = (dp[i][j] + dp[i][j + 1]) % MOD;
        }
    }

    cout << dp[0][0];

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