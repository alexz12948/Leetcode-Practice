C++ || Easy to Understand with In-Depth Explanation and Examples || O(logN)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

We want to use binary search, but continuously round down since we are trying to find the minimum value that is a bad version. For example, if we find a bad version, we only want to look in the lower half since we know that all values above the current version are bad as well.

# Approach

We want to continue until `low >= high` since we want to continue the bounds until we got the best bound. If `isBadVersion(mid)`, then we know that mid is a bad version and we want to look lower, so we set `high = mid` because technically `mid` could still be the best solution. Otherwise, we set `low = mid + 1` since we know that low is not a possible solution. When the loop terminates we know that low must have the first bad version

# Complexity

**Time Complexity:** $$O(logN)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0, high = n, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (isBadVersion(mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**