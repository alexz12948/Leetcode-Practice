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