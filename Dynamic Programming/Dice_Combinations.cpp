#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    // State: dp[i] = no. of ways to form sum i

    // Transition: to reach 'i', I can come from
    // i - 1, i - 2, i- 3, i - 4, i - 5, or i - 6

    // Base Case: dp[0] = 1 (the one way is to not throw the dice)

    // Final Subproblem: dp[n]

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, 6); j++)
            dp[i] = (dp[i] + dp[i - j]) % MOD;
    }

    cout << dp[n];

    // Time Complexity: O(6 * n) ~ O(n)
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