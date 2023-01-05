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

* Precompute the total sum of all the elements in the arrary
* Iterate through `nums` and calculate the current average difference
* If the current average difference is less than the lowest minimum so far, we update the answer and the lowest minimum

## Code

```c++
typedef long long ll;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int n = nums.size();

        ll total_sum = 0;
        for (int i = 0; i < n; i++)
            total_sum += nums[i];

        int minAvgDiff = INT_MAX, ans = 0, currAvgDiff;
        ll first_elements, last_elements, currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            first_elements = currSum / (i + 1);
            last_elements = n - i - 1 != 0 ? (total_sum - currSum) / (n - i - 1) : 0;
            currAvgDiff = abs(first_elements - last_elements);
            if (currAvgDiff < minAvgDiff) {
                minAvgDiff = currAvgDiff;
                ans = i;
            }
        }

        return ans;
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

By using the brute force approach, you must consistently calculate the sum of elements index $$0 \rightarrow i$$ and index $$i+1 \rightarrow n - 1$$. However, by precomputing the prefix sums of every element in O(n), we can calculate the average difference in O(1) time. 

**BUT**, we can make the space complexity even better by only computing the sum of all the elements opposed to the prefix sum

## Approach 

First, we want to calculate the sum of all the elements in the array. Since the total could be greater than what could be stored in an integer, we are using a `long long` instead (type defined as `ll`)

Then, we determine the average of the first `i` elements and last `n - i` elements for every `i` as we iterate. The only weird case is when `n - i - 1 == 0`, which means that the average of the last element is `0`

Then, we just calculate what the current average difference is at index `i` and update the index `ans` and the current `minAvgDiff` if necessary. At the end, we just return the index

## Example

Lets use the first example, where `nums = [2,5,3,9,5,3]`

* Calculate total sum

I won't actually go over this, but the total sum is 27

* Iterate through Array

|   i  | currSum |         first        |                       last                      | minAvgDiff | ans |
|:----:|:-------:|:--------------------:|:-----------------------------------------------:|:----------:|:---:|
| Init |    0    |          N/A         |                       N/A                       |   INT_MAX  |  0  |
|   0  |    2    |  $$\frac{2}{1} = 2$$ |       $$\frac{(27 - 2)}{(6 - 0 - 1)} = 5$$      |      3     |  0  |
|   1  |    7    |  $$\frac{7}{2} = 3$$ |       $$\frac{(27 - 7)}{(6 - 1 - 1)} = 5$$      |      3     |  0  |
|   2  |    10   | $$\frac{10}{3} = 3$$ |      $$\frac{(27 - 10)}{(6 - 2 - 1)} = 5$$      |      3     |  0  |
|   3  |    19   | $$\frac{19}{4} = 4$$ |      $$\frac{(27 - 19)}{(6 - 3 - 1)} = 4$$      |      0     |  3  |
|   4  |    24   | $$\frac{24}{5} = 4$$ |      $$\frac{(27 - 24)}{(6 - 4 - 1)} = 3$$      |      0     |  3  |
|   5  |    27   | $$\frac{27}{6} = 4$$ | $$\frac{(27 - 27)}{(6 - 5 - 1)} \rightarrow 0$$ |      0     |  3  |

At the end, we just return `ans = 3` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**