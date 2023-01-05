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

* Create 4 pointers to indicate the left, right, top, and bottom row and a direction integer to indicate which direction to travel
* Loop through the array while the bounds are still valid
* Go through directions from right -> down -> left -> up and push values into answer array

## Code

```c++
#define RIGHT 0
#define DOWN  1
#define LEFT  2
#define UP    3

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int left = 0, right = n - 1, 
            top = 0, bottom = m - 1;

        int dir = 0;
        while (left <= right && top <= bottom) {
            switch (dir++ % 4) {
                case RIGHT:
                    for (int i = left; i <= right; i++)
                        ans.push_back(matrix[top][i]);
                    top++;
                    break;
                case DOWN:
                    for (int i = top; i <= bottom; i++)
                        ans.push_back(matrix[i][right]);
                    right--;
                    break;
                case LEFT:
                    for (int i = right; i >= left; i--)
                        ans.push_back(matrix[bottom][i]);
                    bottom--;
                    break;
                case UP:
                    for (int i = bottom; i >= top; i--)
                        ans.push_back(matrix[i][left]);
                    left++;
            }
        }

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(MN)$$ where $$M$$ is the number of rows and $$N$$ is the number of columns
**Space Complexity:** $$O(MN)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We want to continuously move through the directions (right -> down -> left -> up) and aggregate the values in the array as we move along a particular boundary. For example, when we move to the right, we will always be along the top boundary; when we move down, we will always be along the right bound; etc. Therefore, if we know the boundaries of the box, we can continuously iterate along the boundary and collect the values/push them into an answer array

## Approach 

Create the 4 boundaries with variables and a direction pointer to indicate which direction we are heading. Then, we want to loop while bounds of the rectangle are valid. Based on the direction, we want to do different things:

* If we are moving to the right, then we want to move along the top boundary from left to right
* If we are moving to the bottom, then we want to move along the right boundary from top to bottom
* If we are moving to the left, then we want to move along the bottom boundary from right to left
* If we are moving to the top, then we want to move along the left boundary from bottom to top

## Example

Lets use the second example, where `matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]`

We set:
* `top = left = 0`
* `bottom = m - 1 = 2`
* `right = n - 1 = 3`

* Direction 1) Right

We take all the values along the top, then add 1 to the top boundary

`ans = [1,2,3,4]` and `top = top + 1 = 1`

* Direction 2) Down

We take all the values along the right, then subtract 1 from the right boundary

`ans = [1,2,3,4,8,12]` and `right = right - 1 = 2`

* Direction 3) Left

We take all the values along the bottom, then subtract 1 from the bottom boundary

`ans = [1,2,3,4,8,12,11,10,9]` and `bottom = bottom - 1 = 1`

* Direction 4) Up

We take all the values along the left, then add 1 to the left boundary

`ans = [1,2,3,4,8,12,11,10,9,5]` and `left = left + 1 = 1`

* Direction 5) Right

We take all the values along the top, then add 1 to the top boundary

`ans = [1,2,3,4,8,12,11,10,9,5,6,7]` and `top = top + 1 = 2`

Now `top > bottom --> 2 > 1` so we break and return `ans` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**