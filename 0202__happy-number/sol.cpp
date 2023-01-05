class Solution {
public:
    bool isHappy(int n) {
        int slow = sumOfSquares(n), 
            fast = sumOfSquares(sumOfSquares(n));
        while (slow != fast) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }

        return slow == 1;
    }
private:
    int sumOfSquares(int n) {
        int curr_sum = 0, mod;
        while (n != 0) {
            mod = n % 10;
            curr_sum += mod * mod;
            n /= 10;
        }

        return curr_sum;
    }
};