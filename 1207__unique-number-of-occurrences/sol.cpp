/*
Explanation of Solution
-----------------------

The idea is to use the ordered map in the
beginning to get the freq of the elements
and then the second map to see if the
frequencies are unique

You could also do this using a frequency array
since you know the values are bounded in the range
[-1000, 1000]

Complexity
----------
Time: O(n)
Space: O(n) 
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        const int n = arr.size();
        unordered_map<int,int> mp;

        for (int i = 0; i < n; i++)
            mp[arr[i]]++;

        unordered_map<int,int> freq;
        for (pair<int,int> pairs : mp) {
            if (freq[pairs.second]++ == 1) return false;
        }

        return true;
    }
};
