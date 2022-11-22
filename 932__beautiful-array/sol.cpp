/*
Explanation of Solution
-----------------------

I don't understand the reasoning for this question in its entirety
and I had to look at the answer (and still don't entirely understand)
but I will try my best to explain it to myself

I believe that the idea is that we want to divide it into the odds
and evens, which would be a good idea because A[k] * 2 != odd + even
regardless. So then, we only have to care about odd + odd and even + even

We also have determined some properties to be able to build beautiful arrays:

* Addition - A[k] * 2 != A[i] + A[j] => 
(A[k] + x) * 2 = A[k] * 2 + 2x != A[i] + A[j] + 2x = (A[i] + x) + (A[j] + x)

* Multiplication = A[k] * 2 != A[i] + A[j] =>
(A[k] * x) * 2 = A[k] * 2x != (A[i] + A[j]) * x = (A[i] * x) + (A[j] * x)

Here is a link to an explanation: https://leetcode.com/problems/beautiful-array/discuss/186679/Odd-%2B-Even-Pattern-O(N)

Complexity
----------
Time: O(n)
Space: O(n) 
*/
class Solution {
public:
    vector<int> memo_beautifulArray(int n, unordered_map<int,vector<int>>& memo) {
        if (memo.count(n) != 1) {
            vector<int> odds = memo_beautifulArray((n + 1) / 2, memo),
                        evens = memo_beautifulArray(n / 2, memo);
            vector<int> build(size(odds) + size(evens));
            int i = 0;
            for (int odd : odds) build[i++] = 2 * odd - 1;
            for (int even : evens) build[i++] = 2 * even;
            memo[n] = build;
        }

        return memo[n];
    }

    vector<int> beautifulArray(int n) {
        unordered_map<int,vector<int>> memo = {{1, {1}}};
        return memo_beautifulArray(n, memo);
    }
};
