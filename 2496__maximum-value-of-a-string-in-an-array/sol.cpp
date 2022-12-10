class Solution {
public:
    int maximumValue(vector<string>& strs) {
        const int n = strs.size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (isNumber(strs[i]))
                ans = max(ans, stoi(strs[i]));
            else
                ans = max(ans, (int)strs[i].size());
        }

        return ans;
    }
private:
    bool isNumber(string s) {
        for (int i = 0; i < s.size(); i++)
            if (!isdigit(s[i]))
                return false;
        return true;
    }
};