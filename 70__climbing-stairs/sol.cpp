class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) 
            return n;

        int two_before = 1, one_before = 2, ans;
        for (int i = 2; i < n; i++) {
            ans = one_before + two_before;
            two_before = one_before;
            one_before = ans;
        }

        return ans;
    }
};