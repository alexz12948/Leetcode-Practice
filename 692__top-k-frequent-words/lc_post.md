C++ || O(KlogN) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

* Find the frequency of all the words
* Create a max heap of the `<string,int>` pairs from the frequency
* Take the top `k` strings from the heap and return

## Code

```c++
typedef pair<string,int> psi;

class Comparator {
    public:
        int operator() (const psi &p1, psi &p2) {
            if (p1.second == p2.second)
                return p1.first > p2.first;

            return p1.second < p2.second;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        const int n = words.size();

        unordered_map<string,int> freq;
        for (int i = 0; i < n; i++)
            freq[words[i]]++;

        priority_queue<psi, vector<psi>, Comparator> pq (freq.begin(), freq.end());

        vector<string> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = pq.top().first;
            pq.pop();
        }

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(NlogK)$$ where $$N$$ is the number of words
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

1. We need to determine the frequency of each word to be able to figure out the most frequent words
2. Once we have the frequency of all the words, we want to put the information in a data structure for us to determine what the top K most frequent strings are. For me, I decided to use a max heap since we want the top `k` most frequent words
3. Pop the first `k` elements from the max heap and put them into an array in order to return

## Approach 

Use an `unordered_map` to determine the frequency of all the words. 

Then, I wrote a Comparator class, which has an interesting comparison to allow this problem to be done in $$O(KlogN)$$. Pretty much, if the frequency is the same between two words, then keep the words in lexicographical order. Otherwise, compare based on frequency alone. 

For more information about the comparison, take a look at [this stackoverflow post](https://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator/48587737). Additionally, you can look at [this solution](https://leetcode.com/problems/top-k-frequent-words/solutions/1274279/cpp-c-priority-queue-custom-comparator-and-solution-explain-o-nlogk-solution/?envType=study-plan&id=level-1&orderBy=most_votes) since they do a good job of explaining the comparison functions

With the hard part being finished, we can start to assemble the answer. We know that we want a `vector<string>` with `k` elements, so we can initialize that upfront. Then, we just take the top `k` elements and put them in order into the `vector` and return it

## Example

Lets use the first example, where `words = ["i","love","leetcode","i","love","coding"]` and `k = 2`

* Determining the frequency

I will not directly go over it, but here is what the resulting map will look like:

`{{"i": 2}, {"love": 2}, {"leetcode": 1}, {"coding": 1}}`

* Creating the max heap

Most of this work is done by the comparison function, but lets just work through 2 of the comparisons

*Comparing {"i": 2} to {"leetcode": 1}*

We first check if the frequency is the same. Since it isn't, return `true` if the first pair has a lower frequency than the second

*Comparing {"i": 2} to {"love": 2}*

Since the frequencies are the same, we need to keep the strings in lexiographical order, so we check if the first pair has a "greater" string than the second pair to maintain the sorted-ness

The heap will look like this: `[{"i": 2}, {"love": 2}, {"coding": 1}, {"leetcode": 1}]`

* Assembling the result

We pop the first `k = 2` elements from the heap and push those in order onto the array

  * i = 0
    Heap: `[{"i": 2}, {"love": 2}, {"coding": 1}, {"leetcode": 1}]`
    Ans: `["", ""]`

    We pop the top element and push `"i"` onto `ans`
  * i = 1
    Heap: `[{"love": 2}, {"coding": 1}, {"leetcode": 1}]`
    Ans: `["i", ""]`

    We pop the top element and push `"love"` onto `ans`
  * Aftermath
    Heap: `[{"coding": 1}, {"leetcode": 1}]`
    Ans: `["i", "love"]`

    We return `ans`, which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**