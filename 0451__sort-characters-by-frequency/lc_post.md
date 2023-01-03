C++ || O(NlogN) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code - Vector Solution](#code---vector-solution)
  - [Code - Multimap Solution](#code---multimap-solution)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach - Vector](#approach---vector)
  - [Approach - Multimap](#approach---multimap)
  - [Example](#example)

# TL;DR

* Calculate the frequency of all characters
* Organize frequencies to be in reverse sorted order
* Append characters to answer

## Code - Vector Solution

```c++
class Solution {
public:
    string frequencySort(string s) {
        const int n = s.size();

        unordered_map<char,int> freq;
        for (int i = 0; i < n; i++)
            freq[s[i]]++;

        vector<pair<char,int>> freq_arr(freq.begin(), freq.end());

        sort(freq_arr.begin(), freq_arr.end(), [](auto& f1, auto& f2) {
            return f1.second > f2.second;
        });

        string ans = "";
        for (pair<char,int> pair : freq_arr)
            while (pair.second-- > 0) ans += pair.first;

        return ans;
    }
};
```

## Code - Multimap Solution

```c++
class Solution {
public:
    string frequencySort(string s) {
        const int n = s.size();

        unordered_map<char,int> freq;
        for (int i = 0; i < n; i++) 
            freq[s[i]]++;

        multimap<int,char,greater<int>> reverse_freq_map;
        for (auto pair : freq)
            reverse_freq_map.insert(make_pair(pair.second, pair.first));
      
        string ans = "";
        for (pair<int,char> pair : reverse_freq_map)
            ans += string(pair.first, pair.second);

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(NlogN)$$ for both 
(either sort or inserting $$N$$ elements where insert takes $$O(logN)$$ time)
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

**Note to reader** the same intuition applys to both solutions

The intuition is that we want to get the frequency of the characters and then append the characters back in reverse sorted order (from the highest frequency to the lowest).

## Approach - Vector

We want to first get the frequency of the characters in `s`, so using a `unordered_map` would do that job easily. After that, we can convert the `unordered_map` to a `vector` to be able to sort in decending order. Notice that I used a lambda function which just sorts the array in decreasing order based on the frequency. 

After that, we just need to loop through the `vector` and then create the string. For this, we need character to be appended to the string based on the frequency of itself. For example, if `s = "tree"` then the character `'e'` should be appended 2 times.

## Approach - Multimap

We still want to first get the frequency of the characters in `s`, so using a `unordered_map` would do that job easily. After this, we want a data structure that is able to insert `n` elements in `logn` time and I chose to use a `multimap` for this, though a `priority_queue` would have worked as well.

You want to specify that the multimap contains elements in decreasing order just insert them into the reverse frequency map. After that,
you want to loop through all the elements in the reverse frequency
map in order and add the character to the answer the number of times that its frequency is in the original string

## Example

Lets use the first example, where `s = "tree"`

* Get frequencies of each character

The end result would be: `{{t: 1}, {r: 1} , {e: 2}}`

* Put in reverse sorted order

Regardless of data structure, we want the frequencies to be in reverse sorted order. The end result should look like this: `[{e: 2}, {r: 1}, {t: 1}]` or `[{e: 2}, {t: 1}, {r: 1}]`

* Create Answer

Then we iterate through the structure and grab the element and append that character on `frequency` times

| i | char | freq |  ans |
|:-:|:----:|:----:|:----:|
| 0 |   e  |   2  |  ee  |
| 1 |   t  |   1  |  eet |
| 2 |   r  |   1  | eetr |

At the end, we return `"eetr"`, which is a solution

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**