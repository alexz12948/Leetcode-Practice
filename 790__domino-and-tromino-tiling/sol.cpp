typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        if (n == 1 || n == 2)
            return n;
        vector<ll> dp(n, 1);

        dp[1] = 2;
        dp[2] = 5;
        for (int i = 3; i < n; i++)
            dp[i] = (dp[i - 1] * 2LL + dp[i - 3]) % MOD;

        return dp[n - 1];
    }
};