#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);

    for (int i = 0; i < n; i++)
        cin >> c[i];

    // State: dp[i] = no. of ways to form sum i using available coins

    // Transition: to form a sum 'i', I can come from
    // i - c_1, i - c_2,..., i - c_n

    // Base Case: dp[0] = 1 (not picking any coin)

    // Final subproblem: dp[x]

    vector<int> dp(x + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0)
                dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
        }
    }

    cout << dp[x];

    // Time Complexity: O(n * x)
    // Space Complexity: O(x)
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