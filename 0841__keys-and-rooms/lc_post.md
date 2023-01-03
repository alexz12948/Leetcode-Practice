C++ || Easy to Understand with In-Depth Explanation and Examples || O(V + E)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Treat rooms/keys as nodes/edges and run DFS from room `0` to determine if all rooms can be visited

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(V + E)$$ where `V` is the number of rooms and `E` is the number of edges
**Space Complexity:** $$O(V)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We can think of the rooms as nodes and the keys as edges and `rooms` to be an adjacency list. Run DFS from room 0 and see if we can visit all of the rooms

## Approach 

First, we initialize an `unordered_set` to hold all of the keys that we have found already and have it contain 0 since we have that key at the beginning. Additionally, create a stack to be able to run DFS and push 0 since that is going to be our starting node

All we want to do after that is loop through the keys that are found in the room at the top of the stack and if it doesn't exist yet (`keys.count(room_key) == 0`), add it to the set and the stack. Also, we can check if the number of keys is equal to the number of rooms when we insert to allow for an early exit.

At the end, we just return false since we know that the number of keys could not have equaled n (otherwise it would've returned out of the loop)

## Example

Lets do example 2 with `rooms = [[1,3], [3,0,1],[2],[0]]`

1. Visiting room 0
**Set:** `[0]`
**Stack:** `bottom [0] top`

We visit 0 and see that we can add room 1 and 3 to both the set and the stack since we haven't visited it yet. We will visit 3 first since it was the last one inserted

2. Visiting room 3
**Set:** `[0,1,3]`
**Stack:** `bottom [1,3] top`

We visit 3 and see that we cannot add anything since the only key in room 3 is 0, which we already have. We continue to iterate through the stack

3. Visiting room 1
**Set:** `[0,1,3]`
**Stack:** `bottom [1] top`

We visit 1 and see that we cannot add any of the keys since the keys in room 1 are all the keys that we already have. We pop the last element off of the stack and break out of the loop

4. Aftermath

We know that since we did not find all of the keys, we cannot visit all of the rooms (we couldn't get the key for room 2)

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**