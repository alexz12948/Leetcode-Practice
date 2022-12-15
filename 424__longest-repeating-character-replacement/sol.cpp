class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();

        int ans = k, left = 0, maxCharCount = 0, curr_len;
        unordered_map<char,int> freq;
        for (int right = 0, right < n; right++) {
            freq[s[right]]++;
            maxCharCount = max(maxCharCount, freq[s[right]]);

            curr_len = right - left + 1;
            if (curr_len - maxCharCount > k) {
                freq[s[left]]--;
                left++;
                curr_len--;
            }

            ans = max(ans, curr_len);
        }

        return ans;
    }
};