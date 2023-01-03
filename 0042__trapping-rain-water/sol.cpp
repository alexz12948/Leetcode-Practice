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
