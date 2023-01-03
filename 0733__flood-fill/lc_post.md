C++ || Easy to Understand with In-Depth Explanation and Examples || O(N^2)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Run DFS/BFS from `(sr, sc)` and spread to all pixels that are the same as the original color

# Approach

First off, if the source pixel is the same color as the new color, we just want to return the same.

Then, depending on DFS or BFS, we need to initialize a queue for BFS or a stack for DFS. To read more about the differences, look [here](https://www.geeksforgeeks.org/difference-between-bfs-and-dfs/) but I am using DFS since it tends to be faster than BFS. *Note that for my code, you can just switch `stack` with `queue` and `st.top()` with `st.front()` if you are using BFS.* We also want to store the original color of the pixel at `(sr,sc)` and push the starting node onto the structure.

Then we get the coordinate at the top of the stack and pop it off. We check whether the coordinate is in bounds and we can color it in. If we can't, then we continue. Otherwise, we color in that pixel and push all of the possible neighbors from that pixel.

# Complexity

**Time Complexity:** $$O(N^2)$$
**Space Complexity:** $$O(N)$$

# Code

```c++
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
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**