Title: C++ || Easy to Understand with In-Depth Explanation || O(n)
Tags: cpp, c++, easy-understanding, clean code, beginner, beginner friendly, easy

### PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

### Intuition

We want to keep track of the next smallest frequency for each bar going from left to right and right to left, which we can precompute using a stack. When we have this, we know that for any given point that the way to figure out its area is finding the distance between the smallest value to the left of it and the smallest value to the right of it to give us the horizontal width of the rectangle and multiplying that by the height of the actual bar itself.

For example, take `[2,1,5,6,2,3]` as the heights. For index 0, the smallest value to the left of it is index -1 (since it doesn't exist, pretend the height is 0) and the smallest value to the right of it is at index 1 (height of 1). Then to find the distance it is 1 - (- 1) - 1 = 1 which is the correct width for the rectangle of this height. Then we multiply the height (2) times the width to get that with index 0, we can get a rectangle of area 2.

Lets do one more example with the same heights as above. For index 3 (height 5), the smallest value to the left of it is index 4 (height of 2) and the smallest value to the right fo it is at index 1 (height 1). Then to find the width, it is 4 - 1 - 1 = 2, which is the correct width for the rectangle of this height. Then we multiply the height (5) by the width (2) and get that with index 3 (height 5), we can get a rectangle of area 10 (which is the solution)

### Approach

Use 2 vectors: one to hold the index of the next smallest value to the left and the other one for the smallest value to the right. We can populate these arrays by using a stack and keeping it monotonically decreasing. For finding the smallest height to the right,the way we do that is if the index at the top of the stack's height is greater than the current height, we have found the smallest height relatively to the previous height. Therefore, we pop off the stack and update its position in the array to contain the current index. The same process works when we go in reverse (from right to left).

Then by the end, we just loop through all the heights and calculate the width, multiply it by the height, and update the largest area if it is greater than the answer so far.

### Complexity

**Time Complexity:** O(n)
**Space Complexity:** O(n)

### Code

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