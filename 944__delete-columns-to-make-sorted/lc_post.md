C++ || Easy to Understand with In-Depth Explanation and Examples || O(NM)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Check each column to ensure that it is in sorted order. If any elements breaks the sorting, increase the answer by one and move onto the next column

## Code

```c++
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int n = strs.size(), m = strs[0].size();

        int ans = 0;
        for (int j = 0; j < m; j++)
            for (int i = 1; i < n; i++)
                if (strs[i][j] < strs[i - 1][j]) {
                    ans++;
                    break;
                }

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(NM)$$ where $$N$$ is the number of rows and $$M$$ is the number of columns
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

Iterate in column major order (the outer loop is columns, inner loop is rows) and make sure that each element in the column is greater than or equal to the one before it. In other words, ensure that `strs[i][j] >= str[i - 1][j]`. If any element breaks this rule, then we delete the column and move on

## Approach 

Iterate in column major order but starting at the second row each time. If any element is less than the the element in the previous row, we increase the answer and break out of the loop since we don't need to check the rest of them. 

In other words, we just check to see if `strs[i][j] < strs[i - 1][j]` at any point. If it is, we know it isn't sorted properly and we want to delete the column. We just return `ans` at the end.

## Example

Lets use the second example, where `strs = ["cba","daf","ghi"]`

* Col = 0
  * Row = 1
    Check if `strs[i][j] < strs[i - 1][j] = strs[1][0] < strs[0][0] = 'd' < 'c'`, which is `false` so we go to the next row
  * Row = 2
    Check if `strs[i][j] < strs[i - 1][j] = strs[2][0] < strs[1][0] = 'g' < 'd'`, which is `false` so we go to the next column
* Col = 1
  * Row = 1
    Check if `strs[i][j] < strs[i - 1][j] = strs[1][1] < strs[0][1] = 'a' < 'b'`, which is `true` so we delete the row and move to the next column
* Col = 2
  * Row = 1
    Check if `strs[i][j] < strs[i - 1][j] = strs[1][2] < strs[0][2] = 'f' < 'a'`, which is `false` so we go to the next row
  * Row = 2
    Check if `strs[i][j] < strs[i - 1][j] = strs[2][2] < strs[1][2] = 'i' < 'f'`, which is `false` so we exit the loop

At the end, `ans = 1` which is correct

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**