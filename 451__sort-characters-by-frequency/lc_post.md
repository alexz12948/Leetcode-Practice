Title: C++ || Easy to Understand with Explanation || O(nlogn)
Tags: cpp, c++, easy-understanding, clean code, multimap, vector, unordered_map

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!!** 🥺😁

## Intuition

**Note to reader** the same intuition applys to both solutions

The intuition is that we want to get the frequency of the characters and then append the characters back in reverse sorted order (from the highest frequency to the lowest).

## Solution with Vector

### Approach 

We want to first get the frequency of the characters in `s`, so using a `unordered_map` would do that job easily. After that, we can convert the `unordered_map` to a `vector` to be able to sort in decending order. Notice that I used a lambda function which just sorts the array in decreasing order based on the frequency. 

After that, we just need to loop through the `vector` and then create the string. For this, we need character to be appended to the string based on the frequency of itself. For example, if `s = "tree"` then the character `'e'` should be appended 2 times.

### Complexity

**Time Complexity:** O(nlogn) because of the sort
**Space Complexity:** O(n)

### Code

```c++
class Solution {
public:
    string frequencySort(string s) {
        const int n = s.size();

        unordered_map<char,int> freq;
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }

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

## Solution with Multimap

### Approach

We still want to first get the frequency of the characters in `s`, so using a `unordered_map` would do that job easily. After this, we want a data structure that is able to insert `n` elements in `logn` time and I chose to use a `multimap` for this, though a `priority_queue` would have worked as well.

You want to specify that the multimap contains elements in decreasing order just insert them into the reverse frequency map. After that,
you want to loop through all the elements in the reverse frequency
map in order and add the character to the answer the number of times that its frequency is in the original string

### Complexity

**Time Complexity:** O(nlogn) because `insert` for `multimap` is `logn` and you are inserting at work `n` elements
**Space Complexity:** O(n)

### Code

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