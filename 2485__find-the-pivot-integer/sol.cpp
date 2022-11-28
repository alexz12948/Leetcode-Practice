/*
Explanation of Solution
-----------------------

You pretty much want to run the algorithm and check if
the sum before is equal to the sum after

Complexity
----------
Time: O(n)
Space: O(1) 
*/
class Solution {
public:
    static int sumOf(int n) {
        int ans = 0;
        while (n) ans += n--;
        return ans;
    }

    int pivotInteger(int n) {
        int ans = -1, before = 1, after = sumOf(n);
        for (int i = 1; i <= n; i++) {
            if (before == after) {
                ans = i;
                break;
            }
            before += i + 1;
            after -= i;
        }

        return ans;
    }
};
