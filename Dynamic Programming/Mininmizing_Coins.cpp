#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);

    for (int i = 0; i < n; i++)
        cin >> c[i];

    // State: dp[i] = minimum coins required to make sum i using available coins

    // Transition: to form sum i, I can come from
    // i - c_1, i - c_2,.... i - c_n
    // shall consider the minimum of all possibilities

    // Base Case: dp[0] = 0, no coin required

    // Final Subproblem: dp[x]

    vector<int> dp(x + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0 && dp[i - c[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - c[j]]);
        }
    }

    cout << ((dp[x] == INT_MAX) ? -1 : dp[x]);

    // Time Complexity: O(x * n)
    // Space Complexity: O(n)
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