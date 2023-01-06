#define TO_INT(c) ((c) - '0')
#define TO_CHAR(n) ((n) + '0')

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string ans (num1.size() + num2.size(), '0');

        int carry = 0, product;
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                product = TO_INT(ans[i + j + 1]) + TO_INT(num1[i]) * TO_INT(num2[j]) + carry;
                ans[i + j + 1] = TO_CHAR(product % 10);
                carry = product / 10;
            }
            ans[i] += carry;
            carry = 0;
        }

        if (ans[0] == '0')
            return ans.substr(1);

        return ans;
    }
};