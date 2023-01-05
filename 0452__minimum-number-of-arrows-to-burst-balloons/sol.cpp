class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int n = points.size();
        sort(points.begin(), points.end(), sort_by_balloon_end);
        int arrow = points[0][1];
        int ans = 1;

        for (int i = 1; i < n; i++) {
            if (arrow >= points[i][0])
                continue;

            arrow = points[i][1];
            ans++;
        }

        return ans;
    }
private:
    static bool sort_by_balloon_end(const vector<int>& p1, const vector<int>& p2) {
        return p1[1] < p2[1];
    }
};