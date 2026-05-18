#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);

    for (int i = 0; i < n; i++)
        cin >> x[i];

    // State: dp[i][k] = number of ways to build a prefix of length i
    // such that the last element of the prefix is k

    // Transition: to reach dp[i][k], I can come from
    // dp[i - 1][k - 1] or dp[i - 1][k] or dp[i - 1][k + 1]
    // {k - 1, k, k + 1} must be valid i.e. in the range [1, m]

    // Base Case: dp[1][k] = 1 if x[0] = 0, or x[0] = k
    // otherwise in no way the prefix of length 1 can end with k

    // Final Subproblem: Summation of dp[n][k] where 1 <= k <= m

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int k = 1; k <= m; k++) {
        if (x[0] == 0 || x[0] == k)
            dp[1][k] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            // finding dp[i][k]
            if (x[i - 1] != 0 && x[i - 1] != k)
                continue;

            for (int prev = k - 1; prev <= k + 1; prev++) {
                if (prev <= 0 || prev > m)
                    continue;

                // transition
                dp[i][k] = (dp[i][k] + dp[i - 1][prev]) % MOD;
            }
        }
    }

    int res = 0;

    for (int k = 1; k <= m; k++)
        res = (res + dp[n][k]) % MOD;

    cout << res;

    // Time Complexity: O(n * m)
    // Space Complexity: O(n * m)
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