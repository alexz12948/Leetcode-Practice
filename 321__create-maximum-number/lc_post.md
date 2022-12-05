Title: C++ || Easy to Understand with In-Depth Explanation || O(k * (n + k ^ 2))
Tags: cpp, c++, easy-understanding, clean code

### PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

### Intuition

We want to try and take varying amounts of the greatest digits in each list to get a total of k digits, combine them, and update the answer if the current number is bigger than the best answer so far.

### Approach

I will talk about each function first and then talk about how they all come together at the end of this

#### max_k_nums_in_list

Given an array of numbers and an integer k, find the max k numbers inside of that list. This algorithm is pretty much a modified `First Greater Element` question. We need to create an decreasing monotonic stack with some interesting logic. I am also going to keep track of the possible number of elements that can be added into the stack called `capacity`. **Note for the reader:** I am using a vector opposed to the a `stack` because I will need to be able to get the first element of the stack (which is the biggest) and it is just easier to use a vector from the beginning

For the while loop logic, we want to make sure the stack isn't empty (`!max_k_nums_stack.empty()`), the top of the stack is less than current value (`max_k_nums_stack.back() < v[i]`), and that the difference between the length of the array and the current index is greater than the capacity (`n - 1 - i >= capacity`). This will prevent excessive popping and not creating a stack of length k. 

For example, lets say there are 5 elements in an array, the stack has 2 elements, we want the stack to have 4 elements, and we are currently at index 3. Then even if the top value of the stack is smaller than the value, we don't want to pop since then there is no way of creating a stack of size 4. For the math people out there, `n = 5`, `capacity = 2` and `i = 3` ==> `1 >= 2` is not true, so we don't pop anything off.

Note that the `capacity` increases as you pop stuff of the stack and decreases as you push values on. At the end of the function, it should contain the max k numbers in the list in decreasing order

Runtime: O(n) where n is the length of the inputted array

#### merge_stacks

Given 2 arrays, we want to lexigraphically compare the two vectors and push the bigger ones first element (largest value) onto the answer. We repeat this process until one of the arrays are empty, and then If you want to read more about how lexigraphical comparisons work, look [here](https://www.geeksforgeeks.org/compare-two-strings-lexicographically-in-java/)

Runtime: O(k^2). First, we know that `v1.size() + v2.size() == k`. Lets say that one of the vectors has all k elements. Then we would go into one of the while loops below. We need to loop through k elements AND erasing from the front is linear up to the containers size which is k. Therefore, the runtime is k^2

#### maxNumber

Given 2 arrays and an integer k, we want to find the maxNumber we can create from a list of digits. Now we can utilize our functions that we wrote above. First we want to loop from (at worst) 0 to k and try to find the maximum about by taking i values from `nums1` and `k - i` values from `nums2`. Then we merge the arrays that are returned and take the maximum between the current answer and the best answer so far.

Note that the bounds of the loop are a little weird: the lower bound is the minimum between 0 and `k - m` since we know that `k <= m + n`, which means that `k - m <= n`. This enables us to not take too little if the array's size are smaller than k

### Complexity

**Time Complexity:** O(k * (n + k^2)) where the first factor of k is from the outer loop in `maxNumber`, n is from `max_k_nums_in_list`, and k^2 is from `merge_stack`
**Space Complexity:** O(k) for the answer, merged stacks temp array, and the max k nums stack

### Code

```c++
class Solution {
    vector<int> max_k_nums_in_list(vector<int>& v, int k) {
        const int n = v.size();
        vector<int> max_k_nums_stack;
        int capacity = k;
        for (int i = 0; i < n; i++) {
            while(!max_k_nums_stack.empty() && max_k_nums_stack.back() < v[i] && n - 1 - i >= capacity) {
                max_k_nums_stack.pop_back();
                capacity++;
            }

            if (capacity > 0) {
                max_k_nums_stack.push_back(v[i]);
                capacity--;
            }
        }

        return max_k_nums_stack;
    }

    vector<int> merge_stacks(vector<int>& v1, vector<int>& v2) {
        vector<int> ans;
        while (v1.size() > 0 && v2.size() > 0) {
            if (v1 > v2) {
                ans.push_back(v1[0]);
                v1.erase(v1.begin());
            } else {
                ans.push_back(v2[0]);
                v2.erase(v2.begin());
            }
        }

        while (v1.size() > 0) {
            ans.push_back(v1[0]);
            v1.erase(v1.begin());
        }

        while (v2.size() > 0) {
            ans.push_back(v2[0]);
            v2.erase(v2.begin());
        }

        return ans;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size(), m = nums2.size();
        vector<int> ans(k), first_stack, second_stack;
        for (int i = max(0, k - m); i <= min(k, n); i++) {
            first_stack = max_k_nums_in_list(nums1, i);
            second_stack = max_k_nums_in_list(nums2, k - i);

            if (first_stack.size() + second_stack.size() != k) continue;

            ans = max(ans, merge_stacks(first_stack, second_stack));
        }

        return ans;
    }
};
```