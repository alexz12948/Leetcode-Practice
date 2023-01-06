C++ || O(N) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Sort the array and greedily grab bars while there are enough coins

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(logN)$$ because sorting needs auxillary space

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We want to greedily grab ice cream bars that are the most cheap first and then gets more expensive. As soon as there aren't enough coins to buy the current cheapest bar, we want to stop iterating and return the number of bars we have purchased

## Approach 

Sort the array in increasing order and iterate while the current index is in the array and the cost of the bar is less than the number of coins. If that is `true` then we purchase the bar by subtracting `costs[bar]` from `coins` and then we increament `bar`

Notice that I am increamenting the interator and subtracting from the number of coins in one line. At the end, we just return the number of bars that we were able to purchase

## Example

Lets use the first example, where `costs = [1,3,2,4,1]` and `coins = 7`

First, we sort the array which yields:
`costs = [1,1,2,3,4]`

Then we iterate and see the number of bars we could grab

| bar # | coins | `costs[bar]` | Can Purchase? |
|:-----:|:-----:|:------------:|:-------------:|
|   0   |   7   |       1      |      Yes      |
|   1   |   6   |       1      |      Yes      |
|   2   |   5   |       2      |      Yes      |
|   3   |   3   |       3      |      Yes      |
|   4   |   0   |       4      |       No      |

We were able to buy 4 bars, so we return 4 which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**