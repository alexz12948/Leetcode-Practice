class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        unordered_set<int> keys({0});

        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int curr_door = st.top();
            st.pop();

            for (int i = 0; i < rooms[curr_door].size(); i++) {
                int room_key = rooms[curr_door][i];
                if (keys.count(room_key) == 0) {
                    st.push(room_key);
                    keys.insert(room_key);
                    if (keys.size() == n) return true;
                }
            }
        }

        return false;
    }
};