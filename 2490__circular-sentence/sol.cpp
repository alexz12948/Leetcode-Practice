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
