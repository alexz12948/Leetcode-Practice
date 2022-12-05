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
