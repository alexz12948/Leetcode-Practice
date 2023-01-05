C++ || O(NlogN) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Sort the ballons by the endpoint and then greedily determine the number of ballons that can be popped with a single arrow (grouping of balloons). Repeat this process for every ballon group.

## Code

```c++
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int n = points.size();
        sort(points.begin(), points.end(), sort_by_balloon_end);
        int arrow = points[0][1];
        int ans = 1;

        for (int i = 1; i < n; i++) {
            if (arrow >= points[i][0])
                continue;

            arrow = points[i][1];
            ans++;
        }

        return ans;
    }
private:
    static bool sort_by_balloon_end(const vector<int>& p1, const vector<int>& p2) {
        return p1[1] < p2[1];
    }
};
```

## Complexity

**Time Complexity:** $$O(NlogN)$$
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

By using the endpoint to sort by, we know by design that the balloon at the front should have the lowest x value **AND** all the balloons after that should have an x endpoint that is greater than it. Therefore, we just need to check the number of balloons whose start point is less than the current balloons endpoint (since popping the current balloon at the endpoint would also pop it). 

For example, lets say after sorting the balloons look like the following: `[[1,6], [2,8]]`. We know that if the 2nd balloons start point is less than the 1st balloons endpoint that it can be popped in conjunction with the first ballon

The basic idea is to choose the first balloon by endpoint and pop as many balloons as possible that overlap with that balloon. Repeat this process for all balloons that haven't been popped

## Approach 

Sort the array by the end point of the balloons. Then, say that the current balloons end point is where we will shoot the arrow. Now, we need to determine how many other balloons will be popped by this arrow. 

We just need to check if the arrow's value is greater than the balloon's start point. If it is, then by principal (since we sorted the balloons), the arrow must pop that balloon as well. If it doesn't, then we update the location of the arrow to be at the end point of the current balloon and we increase the number of arrows used by 1.

## Example

Lets use the first example where `points = [[10,16],[2,8],[1,6],[7,12]]`.

First, we sort it by endpoint to get the array: `[[1,6],[2,8],[7,12],[10,16]]`

Then, we say that the arrow is at `points[0][1] = 6`

* i = 1
`arrow = 1`

`arrow >= points[1][0] -> 6 >= 2` is `true`, so we know that the second balloon can be popped with the arrow that destorys the first balloon and we just continue

* i = 2
`arrow = 1`

`arrow >= points[2][0] -> 6 >= 12` is `false`, so we know we need another arrow to pop this balloon. We set `arrow = points[2][1] = 12` and increament the number of arrows by 1.

* i = 3
`arrow = 2`

`arrow >= points[3][0] -> 12 >= 10` is `true`, so we know that the second balloon can be popped with the arrow that destorys the first balloon and we just continue

* Aftermath

There is nothing else to do besides return `ans = 2` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**