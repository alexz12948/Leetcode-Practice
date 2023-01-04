class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        const int n = tasks.size();

        unordered_map<int,int> freq;
        for (int i = 0; i < n; i++)
            freq[tasks[i]]++;

        int ans = 0;
        for (auto pair : freq) {
            if (pair.second == 1)
                return -1;

            ans += (pair.second + 2) / 3;
        }

        return ans;
    }
};