class Solution {
    vector<int> max_k_nums_in_list(vector<int>& v, int k) {
        const int n = v.size();
        vector<int> max_k_nums_stack;
        int capacity = k;
        for (int i = 0; i < n; i++) {
            while(!max_k_nums_stack.empty() && max_k_nums_stack.back() < v[i] && n - 1 - i >= capacity) {
                max_k_nums_stack.pop_back();
                capacity++;
            }

            if (capacity > 0) {
                max_k_nums_stack.push_back(v[i]);
                capacity--;
            }
        }

        return max_k_nums_stack;
    }

    vector<int> merge_stacks(vector<int>& v1, vector<int>& v2) {
        vector<int> ans;
        while (v1.size() > 0 && v2.size() > 0) {
            if (v1 > v2) {
                ans.push_back(v1[0]);
                v1.erase(v1.begin());
            } else {
                ans.push_back(v2[0]);
                v2.erase(v2.begin());
            }
        }

        while (v1.size() > 0) {
            ans.push_back(v1[0]);
            v1.erase(v1.begin());
        }

        while (v2.size() > 0) {
            ans.push_back(v2[0]);
            v2.erase(v2.begin());
        }

        return ans;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size(), m = nums2.size();
        vector<int> ans(k), first_stack, second_stack;
        for (int i = max(0, k - m); i <= min(k, n); i++) {
            first_stack = max_k_nums_in_list(nums1, i);
            second_stack = max_k_nums_in_list(nums2, k - i);

            if (first_stack.size() + second_stack.size() != k) continue;

            ans = max(ans, merge_stacks(first_stack, second_stack));
        }

        return ans;
    }
};
