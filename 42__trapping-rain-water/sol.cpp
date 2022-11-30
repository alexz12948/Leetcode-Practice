/*
Explanation of Solution
-----------------------

This is a modified version of the first greater element question

The idea is that we only add the height to the stack if the 
height is smaller than the bar at the top of the stack, which
means that the current bar is shorter than the previous bar
in the stack. Therefore, if we find a bar taller than the
one at the top of the stack, we know that it is bounded by
the current height and the height below the top of the stack's height

This means that we can just pop off the current height and add the
resulting trapped water to the stack

Complexity
----------
Time: O(n)
Space: O(n) 
*/

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
