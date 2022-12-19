C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

We want to create a monotonically decreasing queue by using a stack. This basically means we want all the elements in the stack to be decreasing in value. 

We can create one by using a stack. If the stack's top value `top` (the most recently inserted element) is less than the current value `curr` during iteration, then we want to remove the top element until `curr` is less than `top`

Whenever the top element is less than the current element, we know that we want to remove it, but also set the number of days till a warmer day. This is because `curr` must be greater than `top` therefore, we know that the difference between the current index and the index of top will be the number of days until a warmer day.

# Approach

We initialize the answer array to be n elements with value 0. Then we want to loop through all the elements. If the stack is not empty and the top value is less than the current, we want to pop the top element off and set its index to have `i - idx` days till a warmer day. We just want to push the next index onto the stack and continue until there are no more days

# Example

Let `temperatures = [74, 75, 71, 69, 72, 76]`. We initialize our answer to be `[0,0,0,0,0,0]`. Then we start iterating through the array

### i = 0
**Stack**: `bottom [] top`

The stack is empty, so we just push index `0` onto the stack.

### i = 1
**Stack**: `bottom [0] top`

We see that the stack is not empty and the temperature at the top is less than the current temperature (`74 < 75`), so we want to pop `0` off the stack and set its answer to be $$i - idx = 1 - 0 = 1$$ day (since we only had to wait 1 day for a warmer day). After that, we push 1 onto the stack

**Current Answer**: `[1,0,0,0,0,0]`

### i = 2
**Stack**: `bottom [1] top`

We see that the stack is not empty but the temperature at the top is not less than the current temperature (`75 > 71`), so we just push the current index onto the stack

**Current Answer**: `[1,0,0,0,0,0]`

### i = 3
**Stack**: `bottom [1,2] top`

We see that the stack is not empty but the temperature at the top is not less than the current temperature (`71 > 69`), so we just push the current index onto the stack.

**Current Answer**: `[1,0,0,0,0,0]`

### i = 4
**Stack**: `bottom [1,2,3] top`

We see that the stack is not empty and the temperature at the top is less than the current temperature (`69 < 72`), so we want to update the answer at the index of temp `69` with the value of `i - idx = 4 - 3 = 1` and pop 3 off the stack

We see that the stack is not empty and the temperature at the top is less than the current temperature (`71 < 72`), so we want to update the answer at the index of temp `71` with the value of `i - idx = 4 - 2 = 2` and pop 2 off the stack

We see that the stack is not empty but the temperature at the top is not less than the current temperature (`75 > 72`), so we just push the current index onto the stack

**Current Answer**: `[1,0,2,1,0,0]`

### i = 5
**Stack**: `bottom [1,4] top`

We see that the stack is not empty and the temperature at the top is less than the current temperature (`72 < 76`), so we want to update the answer at the index of temp `72` with the value of `i - idx = 5 - 4 = 1` and pop 4 off the stack

We see that the stack is not empty and the temperature at the top is less than the current temperature (`75 < 76`), so we want to update the answer at the index of temp `75` with the value of `i - idx = 5 - 1 = 4` and pop 1 off the stack

The stack is empty so we just push `i` onto the stack

**Current Answer**: `[1,4,2,1,1,0]`

### Aftermath

We know that `76` does not have a value larger than it, so it keeps the value of 0, but everything else is updated and we just return the answer

# Complexity

**Time Complexity:** $$O(N)$$ where $$N$$ is the number of temperatures
**Space Complexity:** $$O(N)$$

# Code

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }

            st.push(i);
        }

        return ans;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**