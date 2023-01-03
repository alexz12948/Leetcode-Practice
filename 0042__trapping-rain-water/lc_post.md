Title: C++ || Easy to Understand with In-Depth Explanation || O(N)
Tags: cpp, c++, easy-understanding, clean code, beginner, beginner friendly, easy

### PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

### Intuition

This is a modified version of the first greater element question

What we want to do is find the bounding heights and calculate the total number of cells that can hold water by utilizing a stack that holds the heights in decreasing order

### Approach

We only add the height to the stack if the current height is smaller than the bar at the top of the stack, which means that the current bar is shorter than the previous bar in the stack. Therefore, if we find a bar taller than the one at the top of the stack, we know that it is bounded by the current height and the height below the top of the stack's height. Lets say we have the `heights = [1,0,2]`. On the stack, we currently have `[1,0]` where 0 is the top of the stack. When we compare the next height to the stack's top, we know that 0 is bounded by the current height (`2`) and the height before (`1`) just based on the stack's properties.

After we know the bounding bars, we find the distance between the two bounding heights (`i - elems.top().HEIGHT - 1`) and we want to find the lowest height. We do this by taking the minimum between the two bounding heights (`min(height[i], elems.top().HEIGHT)`) and subtracting off the popped elements height (since we know that it is located and bounded between the two bounding heights). We add that value onto our answer.

### Complexity

**Time Complexity:** O(n)
**Space Complexity:** O(n)

### Code

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