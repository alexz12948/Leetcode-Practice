/*
Explanation of Solution
-----------------------

This is a kind of difficult mathematical question

The idea is that you can break down a complicated large number
into its digits and use recursion to break down the problem

For example 
a^123456 = (a^12345)^10 * a^6 % mod
a^12345 = (a^1234)^10 * a^5 % mod
...

Continue this process until all of the digits are dealt with
Notice that a cannot exceed mod since it is modded by at the end of each
operation

Complexity
----------
Time: O(nlogn)
Space: O(1)
*/

class Solution {
private: 
    typedef long long ll;
    const int MOD = 1337;

    int fastFact(int a, ll b) {
        int ans = 1;
        while (b != 0) {
            if ((b & 1) == 0) {
                a = (1LL * a * a) % MOD;
                b /= 2;
            } else {
                ans = (1LL * ans * a) % MOD;
                b--;
            }
        }

        return ans;
    }

public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return fastFact(superPow(a, b), 10) * fastFact(a, last_digit) % MOD;
    }
};
