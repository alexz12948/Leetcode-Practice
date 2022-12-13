pair<int,int> dirs[] = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1,0)};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        const int m = image.size(), n = image[0].size();

        if (image[sr][sc] == color)
            return image;

        int orig_color = image[sr][sc];
        stack<pair<int,int>> st;
        st.push(make_pair(sr,sc));
        while (!st.empty()) {
            pair<int,int> coord = st.top();
            st.pop();
            if (!inBounds(coord.first, coord.second, m, n) || 
                !canColor(image[coord.first][coord.second], orig_color, color))
                continue;
                
            image[coord.first][coord.second] = color;

            for (pair<int,int> dir : dirs)
                st.push(make_pair(coord.first + dir.first, coord.second + dir.second));
        }

        return image;
    }
private:
    bool inBounds(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    bool canColor(int pixel_color, int orig_color, int new_color) {
        return pixel_color != new_color && pixel_color == orig_color;
    }
};