class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();

        int prev_house = 0, prev_2_house = 0;
        for (int i = 0; i < n; i++) {
            int tmp = prev_house;
            prev_house = max(prev_2_house + nums[i], prev_house);
            prev_2_house = tmp;
        }

        return prev_house;
    }
};