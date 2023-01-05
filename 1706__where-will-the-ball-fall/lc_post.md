C++ || O(MN) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Simulate a ball dropped in every column and update the answer with whether the ball made it to the bottom or not

## Code

```c++
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr_col = i;
            for (int j = 0; j < m; j++) {
                int next_col = curr_col + grid[j][curr_col];
                if (next_col < 0 || next_col >= n || grid[j][curr_col] != grid[j][next_col]) {
                    curr_col = -1;
                    break;
                }

                curr_col = next_col;
            }
            ans[i] = curr_col;
        }

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(MN)$$
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

The basic idea is to emulate a ball dropped in every column. What we need to realize is that for a ball to go to the next row, the column that the ball is rolling towards needs to be facing in the same direction. 

In other words, if `i` is the current column and `j` is the column that the ball is rolling towards, then we need to ensure that `grid[row][i] == grid[row][j]`. If they are not equal, then the ball will get stuck in the "V" pattern.

Therefore, as we move down, we need to make sure that the ball stays inside of the board's boundaries and the next column is facing in the same direction as the current.

## Approach 

We are iterate through the array in column major order, but we have 2 additional variables to hold the current column and the column that we will move to. To figure out what is the next column, we can just do `curr_col + grid[j][curr_col]` since `grid[j][c]` for any `c` is either `1` for right or `-1` for left.

Then we just check if the ball is inside the boundaries and the next column direction is the same as the current column direction. If this check fails, we set `curr_col = -1` and break so that the answer gets updated with `-1`. If the ball makes it to the bottom, then we just want to update `ans[i]` with the current column that the ball is in since that is what we want to store.

At the end, we just return `ans`

## Example

Lets work through 2 different ball examples from example 1, where `grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]`

**Ball Dropped in Column 1**

* Row 0

The current column is `1`. The next column will be `next_col = curr_col + grid[0][curr_col] = 1 + 1 = 2`. We know that `2` is inside the boundaries and `grid[0][1] == grid[0][2]` so the ball can move to the next row. We update `curr_col = next_col = 2`

* Row 1

The current column is `2`. The next column will be `next_col = curr_col + grid[1][curr_col] = 2 + 1 = 3`. We know that `3` is inside the boundaries but `grid[0][2] != grid[0][3]` so the ball will get stuck in a "V", therefore `ans[1] = -1`

**Ball Dropped In Column 0**

* Row 0

The current column is `0`. The next column will be `next_col = curr_col + grid[0][curr_col] = 0 + 1 = 1`. We know that `1` is inside the boundaries and `grid[0][0] == grid[0][1]` so the ball can move to the next row. We update `curr_col = next_col = 1`

* Row 1

The current column is `1`. The next column will be `next_col = curr_col + grid[1][curr_col] = 1 + 1 = 2`. We know that `2` is inside the boundaries and `grid[1][1] == grid[1][2]` so the ball can move to the next row. We update `curr_col = next_col = 2`

* Row 2

The current column is `2`. The next column will be `next_col = curr_col + grid[2][curr_col] = 2 + -1 = 1`. We know that `1` is inside the boundaries and `grid[2][2] == grid[2][1]` so the ball can move to the next row. We update `curr_col = next_col = 1`

* Row 3

The current column is `1`. The next column will be `next_col = curr_col + grid[3][curr_col] = 1 + 1 = 2`. We know that `2` is inside the boundaries and `grid[3][1] == grid[3][2]` so the ball can move to the next row. We update `curr_col = next_col = 2`

* Row 4

The current column is `2`. The next column will be `next_col = curr_col + grid[4][curr_col] = 2 + -1 = 1`. We know that `1` is inside the boundaries and `grid[4][2] == grid[4][1]` so the ball can move to the next row. We update `curr_col = next_col = 1`

* Aftermath

We reached the bottom of the board, so we update `ans[0] = 1` since that was the column that the ball rolled to

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**