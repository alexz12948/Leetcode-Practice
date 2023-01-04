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

* Figure out the frequency of all of the task difficulties
* If any of them only occur once, return `-1`
* Add the frequency divided by 3 to the `ans` 
* If the `frequency % 3 != 0`, then we need to add an additional group (look at the [intuition](#intuition) for a more thorough explanation)

## Code

```c++
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        const int n = tasks.size();

        unordered_map<int,int> freq;
        for (int i = 0; i < n; i++)
            freq[tasks[i]]++;

        int ans = 0;
        for (auto pair : freq) {
            if (pair.second == 1)
                return -1;

            ans += (pair.second + 2) / 3;
        }

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

First, we need to figure out the frequency of the task difficulties since we need to group the tasks into rounds. If any of the task difficulties only occur once, then return `-1` since we can only make groups of 2 and 3

Now, we need to take a look at some math. We want to consider the frequency % 3. There are 3 different cases to consider:

1. `frequency % 3 == 0` $$\rightarrow$$ we just want to perform $$\frac{freq}{3}$$ rounds of 3 tasks to complete the tasks at that difficulty
2. `frequency % 3 == 1` $$\rightarrow$$ If we do the same thing as the other case, we will eventually get to 1 and there would be no way to group it. Therefore, we perform one less round of 3 to get to `1 + 3 = 4` more of that specific task and then perform 2 rounds of 2. The mathematical way to represent this is $$(\frac{freq}{3} - 1) + 2 \rightarrow \frac{freq}{3} + 1$$ 
3. `frequency % 3 == 2` $$\rightarrow$$ In this case, we will have a round of 2 leftover after all the rounds of 3 are performed (since it has a remainder of 2), so we just need to add one round of 2 to finish all the tasks. The mathematical way to represent this is $$\frac{freq}{3} + 1$$

We can further simply this since we are using integer division (which just rounds down). Notice how when `freq % 3 == 0` does it stay the same value; for `freq % 3 == 1 or freq % 3 == 2`, it increases by one. Therefore, we can just sum up $$(freq + 2) / 3$$ for all tasks. (If this is confusing for you, try it on a couple of numbers)

Notice how case 2 and 3 are the same. Now, we just perform this for all of the task difficulties and return the number of rounds

## Approach 

First, we find the frequencies of all the task difficulties using an `unordered_map`

Then, we loop through all of the frequencies. If a frequency is equal to 1, return `-1` since there is no way to group that one task.

Based on what we determined in the [intuition](#intuition), we just need to add 1 more if the `frequency % 3 != 0`. Once we are done with the loop, we return `ans`

## Example

Lets use the first example, where `tasks = [2,2,3,3,2,4,4,4,4,4]`.

First, we calculate the frequency of each task, which yields:

`{{2: 3}, {3: 2}, {4: 5}}`

Then we loop through all of the pairs and perform the calculation:

* Tasks with difficulty 2
ans = 0

There are 3 tasks so we do `(pair.second + 2) / 3 = (3 + 2) / 3 = 5 / 3 = 1` and we add that to the answer

* Tasks with difficulty 3
ans = 1

There are 2 tasks so we do `(pair.second + 2) / 3 = (2 + 2) / 3 = 1` and we add that to the answer

* Tasks with difficulty 4
ans = 2

There are 5 tasks so we do `(pair.second + 2) / 3 = (5 + 2) / 3 = 2` and we add that to the answer

* Aftermath

We get the minimum number of rounds to be `4`, which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**