class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n = text1.size(), m = text2.size();
        vector<vector<short>> matrix (n + 1, vector<short> (m + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                matrix[i + 1][j + 1] = text1[i] == text2[j] 
                    ? matrix[i][j] + 1 
                    : max(matrix[i + 1][j], matrix[i][j + 1]);

        return matrix[n][m];
    }
};