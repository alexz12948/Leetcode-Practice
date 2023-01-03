C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Precompute the next smallest height for every height going from left to right and also from right to left. Then, we can go through these arrays and compute the largest area by finding the next smallest bar from left to right to determine the width and multiply it by the height of itself.

## Code

```c++
typedef long long ll;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        ll ans = 0;

        stack<int> elems;
        vector<int> next_smallest_height_to_left(n, -1),
                    next_smallest_height_to_right(n, n);

        for (int i = 0; i < n; i++) {
            while (!elems.empty() && heights[elems.top()] > heights[i]) {
                next_smallest_height_to_right[elems.top()] = i;
                elems.pop();
            }
            elems.push(i);
        }

        // This is done because stack does not have a clear function
        while (!elems.empty()) elems.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!elems.empty() && heights[elems.top()] > heights[i]) {
                next_smallest_height_to_left[elems.top()] = i;
                elems.pop();
            }
            elems.push(i);
        }

        for (int i = 0; i < n; i++) {
            int width = next_smallest_height_to_right[i] - next_smallest_height_to_left[i] - 1;
            ans = max(ans, 1LL * width * heights[i]);
        }

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(N)$$ where $$N$$ is the length of the input array
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We want to keep track of the next smallest height for each bar going from left to right and right to left, which we can precompute using a stack. When we have this, we know that for any given point that the way to figure out its area is finding the distance between the smallest value to the left of it and the smallest value to the right of it to give us the horizontal width of the rectangle and multiplying that by the height of the actual bar itself.

For example, take `[2,1,5,6,2,3]` as the heights. For index 0, the smallest value to the left of it is index -1 (since it doesn't exist, pretend the height is 0) and the smallest value to the right of it is at index 1 (height of 1). Then to find the distance it is 1 - (- 1) - 1 = 1 which is the correct width for the rectangle of this height. Then we multiply the height (2) times the width to get that with index 0, we can get a rectangle of area 2. If you are confused, take a look at the [bottom](#example) for a full walkthrough with this example

## Approach 

Use 2 vectors: one to hold the index of the next smallest value to the left and the other one for the smallest value to the right. We can populate these arrays by using a stack and keeping it monotonically increasing. For finding the smallest height to the right,the way we do that is if the index at the top of the stack's height is greater than the current height, we have found the smallest height relatively to the previous height. Therefore, we pop off the stack and update its position in the array to contain the current index. The same process works when we go in reverse (from right to left).

Then by the end, we just loop through all the heights and calculate the width, multiply it by the height, and update the largest area if it is greater than the answer so far.

## Example

Lets use an example where `heights = [2,1,5,6,2,3]`

**Compute from left to right**

* i = 0
Stack = `[]` <-- TOP
Array = `[-1,-1,-1,-1,-1,-1]`

There are no elements on the stack, so we just push the index `0`

* i = 1
Stack = `[2]` <-- TOP
Array = `[-1,-1,-1,-1,-1,-1]`

Since the stack isn't empty, we compare `heights[elems.top()] = heights[0] = 2` against `heights[i] = heights[1] = 1`. Since the top element is greater than current element, we update it's array index to hold `i = 1` and pop `0` off the stack. The while condition is now false and at the end, we always push the current index onto the stack

* i = 2
Stack = `[1]` <-- TOP
Array = `[1,-1,-1,-1,-1,-1]`

Since the stack isn't empty, we compare `heights[elems.top()] = heights[1] = 1` against `heights[i] = heights[2] = 5`. Since `1 < 5`, we just push the index `2`

* i = 3
Stack = `[1,2]` <-- TOP
Array = `[1,-1,-1,-1,-1,-1]`

Since the stack isn't empty, we compare `heights[elems.top()] = heights[2] = 5` against `heights[i] = heights[3] = 6`. Since `5 < 6`, we just push the index `3`

* i = 4
Stack = `[1,2,3]` <-- TOP
Array = `[1,-1,-1,-1,-1,-1]`

Since the stack isn't empty, we compare `heights[elems.top()] = heights[3] = 6` against `heights[i] = heights[4] = 2`. Since the top element is greater than current element, we update it's array index to hold `i = 4` and pop `3` off the stack. We check the while condition again

Since the stack isn't empty, we compare `heights[elems.top()] = heights[2] = 5` against `heights[i] = heights[4] = 2`. Since the top element is greater than current element, we update it's array index to hold `i = 4` and pop `2` off the stack. We check the while condition again.

Since the stack isn't empty, we compare `heights[elems.top()] = heights[1] = 1` against `heights[i] = heights[4] = 2`. Since `1 < 2`, we just push the index `4`

* i = 5
Stack = `[1,4]` <-- TOP
Array = `[1,-1,4,4,-1,-1]`

Since the stack isn't empty, we compare `heights[elems.top()] = heights[4] = 2` against `heights[i] = heights[5] = 3`. Since `2 < 3`, we just push the index `5`

This generates the array `[1,-1,4,4,-1,-1]` which gives the index of the next smallest height's sindex of a particular height going from left to right

*I am not doing it again for right to left, but it is the same idea*

**Computing the largest area**

Here are the two arrays:
* Left to right = `[1,-1,4,4,-1,-1]`
* Right to left = `[-1,-1,1,2,1,4]`

Now we iterate and calculate the largest area for each

* i = 0
ans = 0

The width is `left_to_right[i] - right_to_left[i] - 1 = left_to_right[0] - right_to_left[0] - 1 = 1 - (-1) - 1 = 1`. Therefore, the largest area is `1 * heights[i] = 1 * heights[0] = 1 * 2 = 2`. We update ans

* i = 1
ans = 2

The width is `left_to_right[i] - right_to_left[i] - 1 = left_to_right[1] - right_to_left[1] - 1 = -1 - (-1) - 1 = -1`. Therefore, the largest area is `-1 * heights[i] = -1 * heights[1] = -1 * 1 = -1`. We do not update ans

* i = 2
ans = 2

The width is `left_to_right[i] - right_to_left[i] - 1 = left_to_right[2] - right_to_left[2] - 1 = 4 - 1 - 1 = 2`. Therefore, the largest area is `2 * heights[i] = 2 * heights[2] = 2 * 5 = 10`. We update ans

* i = 3
ans = 10

The width is `left_to_right[i] - right_to_left[i] - 1 = left_to_right[3] - right_to_left[3] - 1 = 4 - 2 - 1 = 1`. Therefore, the largest area is `1 * heights[i] = 1 * heights[3] = 1 * 6 = 6`. We do not update ans

* i = 4
ans = 10

The width is `left_to_right[i] - right_to_left[i] - 1 = left_to_right[4] - right_to_left[4] - 1 = -1 - 1 - 1 = -3`. Therefore, the largest area is `-3 * heights[i] = -3 * heights[4] = -3 * 2 = -6`. We do not update ans

* i = 5
ans = 10

The width is `left_to_right[i] - right_to_left[i] - 1 = left_to_right[5] - right_to_left[5] - 1 = -1 - 4 - 1 = -6`. Therefore, the largest area is `-6 * heights[i] = -6 * heights[5] = -6 * 3 = -18`. We do not update ans

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**