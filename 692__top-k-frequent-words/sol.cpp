typedef pair<string,int> psi;

class Comparator {
    public:
        int operator() (const psi &p1, psi &p2) {
            if (p1.second == p2.second)
                return p1.first > p2.first;

            return p1.second < p2.second;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        const int n = words.size();

        unordered_map<string,int> freq;
        for (int i = 0; i < n; i++)
            freq[words[i]]++;

        priority_queue<psi, vector<psi>, Comparator> pq (freq.begin(), freq.end());

        vector<string> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = pq.top().first;
            pq.pop();
        }

        return ans;
    }
};