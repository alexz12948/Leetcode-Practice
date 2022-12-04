Title: C++ || Easy to Understand with In-Depth Explanation || O(N)
Tags: cpp, c++, easy-understanding, clean code, beginner, beginner friendly, easy

### PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

### Intuition

Split the string into words and then compare the each word based on the definition of a circular sentence

### Approach

I used the c++ string stream to parse the sentence into words based on the single space between words. Then, I looped through all the words from 0 to n - 1 (since we can't compare the last word) and compared the last character of word `i` to the first character of word `i + 1`. After that, I checked if the last character of the last word is equal to the first character of the first word. If that is true, then it is a circular sentence

### Complexity

**Time Complexity:** O(n) where n is the number of words in the string
**Space Complexity:** O(n)

### Code

```c++
class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        string currWord;
        istringstream ss(sentence);
        while (ss >> currWord)
            words.push_back(currWord);

        const int n = words.size();
        bool is_middle_circular = true;
        for (int i = 0; i < n - 1; i++)
            is_middle_circular &= words[i].back() == words[i + 1].front();

        return is_middle_circular && words[0].front() == words[n - 1].back();
    }
};
```