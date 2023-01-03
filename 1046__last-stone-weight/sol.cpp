class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq (stones.begin(), stones.end());

        int stone1, stone2;
        while (pq.size() > 1) {
            stone1 = pq.top(); pq.pop();
            stone2 = pq.top(); pq.pop();

            if (stone1 != stone2)
                pq.push(stone1 - stone2);
        }

        return pq.empty() ? 0 : pq.top();
    }
};