C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

The easiest way to deal with an RPN calculator is to hold a stack of the values. Whenever you see an integer, you push it onto the stack. Whenever you see an operator, you take the first two elements off of the stack, do the operation and push the result back onto the stack. When there are no more tokens, the answer should be at the top of the stack (with only 1 element)

# Approach

Initialize the operators as a set of strings for easy lookup and an empty stack. Then iterate through all of the tokens. If the token is an operator, we know that we need to take the top two elements, perform the operation, and push the result back. I did this by using a switch statement and remember that we can only use constant expressions (aka can only use `char` not `string`). If the token is not an operator, then it must be an integer, so we push it onto the stack.

**Note to reader:** I used a `long long ` opposed to an integer due to integer overflow issues with my submission since we could just continuously multiply and get larger and larger values

We continue this process until we have gone through all of the tokens. At the end, the top value on the stack should be the result since allof the RPN expressions are valid

# Example

Let's say `tokens = ["2","1","+","3","*"]`

We iterate through the elements and I will show this by using a variable `i`

### i = 0
**Stack:** `bottom [] top`

The token is `"2"` so we push the integer value of it onto the stack

### i = 1
**Stack:** `bottom [2] top`

The token is `"1"` so we push the integer value of it onto the stack

### i = 2
**Stack:** `bottom [2,1] top`

The token is `"+"` so we pop the top 2 values on the stack, do the operation (`2 + 1 = 3`), and push the result `3` onto the stack

### i = 3
**Stack:** `bottom [3] top`

The token is `"3"` so we push the integer value of it onto the stack

### i = 4
**Stack:** `bottom [3,3] top`

The token is `"*"` so we pop the top 2 values on the stack, do the operation (`3 * 3 = 9`), and push the result `9` onto the stack

### Aftermath

The only value on the stack is `9`, which is the result from this. Notice how in the solution we only care about evaluating from inside to outside

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

# Code

```c++
typedef long long ll;

class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        const int n = tokens.size();
        unordered_set<string> operators ({"*","+","-","/"});

        stack<ll> calc;
        for (int i = 0; i < n; i++) {
            if (operators.find(tokens[i]) != operators.end()) {
                ll first = calc.top();
                calc.pop();
                ll second = calc.top();
                calc.pop();
                switch (tokens[i][0]) {
                    case '*':
                        calc.push(second * first);
                        break;
                    case '+':
                        calc.push(second + first);
                        break;
                    case '-':
                        calc.push(second - first);
                        break;
                    default:
                        calc.push(second / first);
                }
            } else
                calc.push(stoi(tokens[i]));
        }

        return calc.top();
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**