class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int n = nums.size();
        int ans = -1, totalSum = 0, currSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += nums[i];

        for (int i = 0; i < n; i++) {
            totalSum -= nums[i];
            if (totalSum == currSum) {
                ans = i;
                break;
            }

            currSum += nums[i];
        }

        return ans;
    }
};
