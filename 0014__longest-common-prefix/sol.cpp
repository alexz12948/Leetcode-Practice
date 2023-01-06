class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];

        auto [smallest, biggest] = minmax(strs);
        // string smallest = *min_element(strs.begin(), strs.end()), 
        //        biggest = *max_element(strs.begin(), strs.end());

        for (int i = 0; i < smallest.size(); i++)
            if (smallest[i] != biggest[i])
                return smallest.substr(0, i);

        return smallest;
    }
};