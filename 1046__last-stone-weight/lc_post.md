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

* Put elements into a max heap
* Continuously pop off 2 stones until there is 0 or 1 stone
* If the stones are not equal, push the difference back onto the heap

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(NlogN)$$
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

Since we always want to retrieve the heaviest 2 stones as well as possibly put another value back onto the structure, this sounds best suited for a max heap since push/pop are $$O(logN)$$ and can be created in $$O(N)$$ since all of the elements are available upfront

After that, we do exactly what the problem says:
* Pop 2 stones
  * If they are not equal, push the difference
  * If they are equal, do nothing
* Finish when there is 1 or less stone
  * If the heap is empty, return 0
  * If the heap is not empty, return the only stone

## Approach 

We initialize a `priority_queue` using the elements from `stones` since it is the c++ max heap structure

Then, we continuously pop two stones off of the heap. If the two stones are not equal, then we push the differernce of them back onto the heap. We finish when there is 1 stone or less.

At the end, if the queue is empty, we return `0`, otherwise we return the weight of the only surviving stone

## Example

Lets use the first example, where `stones = [2,7,4,1,8,1]`

* Construction of the priority queue

This is what it would look like: `[8,7,4,2,1,1]`

* Iterate until there is 1 or less stone

| Iteration | Stone1 | Stone2 | Stones Equal? | Difference | Priority Queue |
|:---------:|:------:|:------:|:-------------:|:----------:|:--------------:|
|     1     |    8   |    7   |     False     |      1     |  `[4,2,1,1,1]` |
|     2     |    4   |    2   |     False     |      2     |   `[2,1,1,1]`  |
|     3     |    2   |    1   |     False     |      1     |    `[1,1,1]`   |
|     4     |    1   |    1   |      True     |     N/A    |      `[1]`     |

Since there is only 1 stone in the priority queue, we exit out of the while loop and return `1` which is the answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**