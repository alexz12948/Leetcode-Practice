class Solution {
public:
    int currLongestPath = 1;
    vector<vector<int>> children;

    int longestPath(vector<int>& parent, string s) {
        const int n = parent.size();
        children.resize(n);
        for (int i = 1; i < n; i++)
            children[parent[i]].push_back(i);

        dfs(0, s);
        return currLongestPath;
    }
private:
    int dfs(int node, string& s) {
        int longestChain = 0, secondLongestChain = 0;
        for (int child : children[node]) {
            int longestChainFromChild = dfs(child, s);

            if (s[child] == s[node])
                continue;

            if (longestChainFromChild > longestChain) {
                secondLongestChain = longestChain;
                longestChain = longestChainFromChild;
            } else if (longestChainFromChild > secondLongestChain)
                secondLongestChain = longestChainFromChild;
        }

        currLongestPath = max(currLongestPath, longestChain + secondLongestChain + 1);
        return longestChain + 1;
    }
};