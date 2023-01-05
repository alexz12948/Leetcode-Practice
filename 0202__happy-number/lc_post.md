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

Use [Floyd Cycle Detection Algorithm](https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/) and terminate when they are at the same value. Return whether or not the value that they stopped on is `1`

## Code

```c++
class Solution {
public:
    bool isHappy(int n) {
        int slow = sumOfSquares(n), 
            fast = sumOfSquares(sumOfSquares(n));
        while (slow != fast) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }

        return slow == 1;
    }
private:
    int sumOfSquares(int n) {
        int curr_sum = 0, mod;
        while (n != 0) {
            mod = n % 10;
            curr_sum += mod * mod;
            n /= 10;
        }

        return curr_sum;
    }
};
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We know that all values must loop, so we just have to detect where the loop is. We also know that if the value is ever `1`, it will loop infinitely at `1`. Therefore, we just need to detect a cycle and check whether the location of the cycle is at `1` or some other value. We return whether the location of the loop is at `1`

The cycle detection algorithm that we are using is called the [Floyd Cycle Detection Algorithm](https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/) and can compute whether there is a cycle in $$O(N)$$ time. The basic idea is that there are 2 pointers, one slow and one fast. The slow pointer moves down 1 at a time and the fast pointer moves 2. If there is a cycle, it is proven that the two pointers will eventually meet.

For this problem, we know that there **IS** a cycle, so we can use this to detect whether there is a cycle so we can terminate

## Approach 

Write a function to calculate the sum of squares of the digits of a particular integer. Then initialize 2 variables, one being the `slow` pointer and the other is the `fast` one.

The `slow` should move 1 value down the cycle and the `fast` should move 2. Then, loop until `slow == fast` (which we know must happen at some point). At every iteration, we move the `slow` 1 value and the `fast` 2.

## Example

Lets use the first example, where `n = 19`

| Iteration | Slow | Fast |
|-----------|------|------|
| Init      | 82   | 68   |
| 1         | 68   | 1    |
| 2         | 100  | 1    |
| 3         | 1    | 1    |

We return `slow = 1 == 1` which is `true` and is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**