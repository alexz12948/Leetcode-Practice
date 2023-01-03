class Solution {
public:
    string getHint(string secret, string guess) {
        const int n = secret.size();
        unordered_map<char,int> secret_freq;
        int num_bulls = 0, num_cows = 0;

        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i])
                num_bulls++;
            else
                secret_freq[secret[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i] && secret_freq[guess[i]] > 0) {
                secret_freq[guess[i]]--;
                num_cows++;
            }
        }

        return to_string(num_bulls) + "A" + to_string(num_cows) + "B";
    }
};