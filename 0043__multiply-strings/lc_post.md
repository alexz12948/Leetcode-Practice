C++ || O(NM) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

* If either number is `0`, then return `"0"`
* Multiply digits together from ones digit up
* Hold onto the carry for every iteration
* Return the ans

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(NM)$$ where $$N$$ is the size of `num1` and $$M$$ is the size of `num2`
**Space Complexity:** $$O(N + M)$$ for the solution

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We want to perform multiplication just like in elementary school: Multiply digit by digit, carry over any extra, and add it to a running sum of values. An example could be
123 * 45

|   | 1 | 2 | 3 |
|:-:|:-:|:-:|:-:|
| x |   | 4 | 5 |
| ~ | ~ | ~ | ~ |
|   |   | 1 | 5 |
|   | 1 | 0 |   |
|   | 5 |   |   |
|   | 1 | 2 |   |
|   | 8 |   |   |
| 4 |   |   |   |
| ~ | ~ | ~ | ~ |
| 5 | 5 | 3 | 5 |

Notice how we add the values vertically and carry over any extra values 

*Note to reader* I used the `~` character to denote a line since markdown was being weird

## Approach 

We initialize a string of size N + M since it is impossible to have an answer that is > N + M digits. Then we iterate from smallest to largest and calculate the product of the digits and add the carry digit and the value that is originally there (since we are using the answer for intermediate steps as well)

Then, we update the value at `i + j + 1` since that is where the value belongs and grab the amount that we carry over. By the end, we just check whether or not the first digit is '0' since if it is, that means that we only used N + M - 1 digits, so we can just substr the answer to not include the first character. Otherwise, we just return the answer

## Example

Lets use the second example, where `num1 = "123"` and `num2 = "456"`

| (i,j) | i+j+1 | before |         product        |  after | carry |
|:-----:|:-----:|:------:|:----------------------:|:------:|:-----:|
| (2,2) |   5   | 000000 | $$0 + 3 * 6 + 0 = 18$$ | 000008 |   1   |
| (2,1) |   4   | 000008 | $$0 + 3 * 5 + 1 = 16$$ | 000068 |   1   |
| (2,0) |   3   | 000068 | $$0 + 3 * 4 + 1 = 13$$ | 000368 |   1   |
| (1,2) |   4   | 001368 | $$6 + 2 * 6 + 0 = 18$$ | 001388 |   1   |
| (1,1) |   3   | 001388 | $$3 + 2 * 5 + 1 = 14$$ | 001488 |   1   |
| (1,0) |   2   | 001488 | $$1 + 2 * 4 + 1 = 10$$ | 000488 |   1   |
| (0,2) |   3   | 010488 | $$4 + 1 * 6 + 0 = 10$$ | 010088 |   1   |
| (0,1) |   2   | 010088 |  $$0 + 1 * 5 + 1 = 6$$ | 016088 |   0   |
| (0,0) |   1   | 016088 |  $$1 + 1 * 4 + 0 = 5$$ | 056088 |   0   |

Notice that `ans` at the end has a leading `0`, so we remove it and return `ans = "56088"` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**