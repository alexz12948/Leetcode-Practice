class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int n = costs.size();

        sort(costs.begin(), costs.end());

        int bar = 0;
        while (bar < n && costs[bar] <= coins)
            coins -= costs[bar++];

        return bar;
    }
};