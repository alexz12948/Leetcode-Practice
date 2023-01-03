C++ || O(N) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

* Use a stack to maintain a monotonically decreasing order of heights for every height
* Every time we pop off the stack, we "fill" the area between the top of the stack and the current height with water and add it to the answer

## Code

```c++
#define HEIGHT first
#define IDX second
typedef pair<int,int> pii;

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int ans = 0;
        stack<pii> elems;

        for (int i = 0; i < n; i++) {
            while (!elems.empty() && elems.top().HEIGHT < height[i]) {
                pii top = elems.top();
                elems.pop();
                if (elems.empty()) break;
                int distance = i - elems.top().IDX - 1;
                int lowest_height = min(height[i], elems.top().HEIGHT) - top.HEIGHT;
                ans += distance * lowest_height;
            }
            elems.push(make_pair(height[i], i));
        }

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

This is a modified version of the first greater element question

What we want to do is find the bounding heights and calculate the total number of cells that can hold water by utilizing a stack that holds the heights in decreasing order

## Approach 

We only add the height to the stack if the current height is smaller than the bar at the top of the stack, which means that the current bar is shorter than the previous bar in the stack. Therefore, if we find a bar taller than the one at the top of the stack, we know that it is bounded by the current height and the height below the top of the stack's height. Lets say we have the `heights = [1,0,2]`. On the stack, we currently have `[1,0]` where 0 is the top of the stack. When we compare the next height to the stack's top, we know that 0 is bounded by the current height (`2`) and the height before (`1`) just based on the stack's properties.

After we know the bounding bars, we find the distance between the two bounding heights (`i - elems.top().HEIGHT - 1`) and we want to find the lowest height. We do this by taking the minimum between the two bounding heights (`min(height[i], elems.top().HEIGHT)`) and subtracting off the popped elements height (since we know that it is located and bounded between the two bounding heights). We add that value onto our answer.

## Example

Lets use the second example, where `height = [4,2,0,3,2,5]`

* i = 0
Stack = `[]` <-- TOP
Ans = `0`

There are no elements on the stack, so we push `{i, heights[i]} = {0, 4}` on

* i = 1
Stack = `[{0, 4}]` <-- TOP
Ans = `0`

`heights[0] > heights[1]`, so we push `{i, heights[i]} = {1, 2}` on

* i = 2
Stack = `[{0, 4}, {1, 2}]` <-- TOP
Ans = `0`

`heights[1] > heights[2]`, so we push `{i, heights[i]} = {2, 0}` on

* i = 3
Stack = `[{0, 4}, {1, 2}, {2, 0}]` <-- TOP
Ans = `0`

`heights[2] < heights[3]`, so we calculate the amount of water between index `1` and `3`. We can add 2 units of water since there is a width of `1` and height of `2`, so `ans = 2`

Stack = `[{0, 4}, {1, 2}]` <-- TOP
Ans = `2`

`heights[1] < heights[3]`, so we calculate the amount of water between index `0` and `3`. We can add 2 units of water since there is a width of `2` and a height of `1`, so `ans = 4`

Stack = `[{0, 4}, {1, 2}]` <-- TOP
Ans = `4`

`heights[0] > heights[3]`, so we push `{i, heights[i]} = {3, 3}` on

* i = 4
Stack = `[{0, 4}, {3,3}]` <-- TOP
Ans = `4`

`heights[3] > heights[4]`, so we push `{i, heights[i]} = {4, 2}` on

* i = 5
Stack = `[{0, 4}, {3, 3}, {4, 2}]` <-- TOP
Ans = `4`

`heights[4] < heights[5]`, so we calculate the amount of water between index `3` and `5`. We can add 1 units of water since there is a width of `1` and a height of `1`, so `ans = 5`

Stack = `[{0, 4}, {3, 3}]` <-- TOP
Ans = `4`

`heights[3] < heights[5]`, so we calculate the amount of water between index `0` and `5`. We can add 4 units of water since there is a width of `4` and a height of `1`, so `ans = 9`

* Aftermath

We return `ans = 9` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**