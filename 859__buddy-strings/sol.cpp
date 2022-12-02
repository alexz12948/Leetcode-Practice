#define LOWERCASE_TO_INDEX(c) (c - 'a')

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        const int n = s.size();
        if (n != goal.size()) return false;

        if (s == goal) {
            vector<int> char_freq(26, 0);

            for (int i = 0; i < n; i++)
                if (++char_freq[LOWERCASE_TO_INDEX(s[i])] > 1)
                    return true;

            return false;
        }

        int first_diff_idx = -1, second_diff_idx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != goal[i]) {
                if (first_diff_idx == -1)
                    first_diff_idx = i;
                else if (second_diff_idx == -1)
                    second_diff_idx = i;
                else 
                    return false;
            }
        }

        return second_diff_idx != -1 && 
               s[first_diff_idx] == goal[second_diff_idx] && 
               s[second_diff_idx] == goal[first_diff_idx];
    }
};
