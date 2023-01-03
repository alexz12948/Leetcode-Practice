/*
Explanation of Solution
-----------------------

I feel like I am getting better at doing leetcode questions because
(after some fighting with the compiler), I managed to get the solution
accepted on my first try!! :) very very happy, but now to the explanation

The idea is to use the function `decodeString` over and over until
you come to the end of the string. As you are looping through the string,
if the character you are looking at is not a number, then you just add it onto
the answer and keep moving forward.

If it is a number, then you need to get the number in front of the
bracket and find the matching bracket for that left bracket. Then
you call the `decodeString` function on the distance between the
brackets and then take that string that is returned and add it to
the existing answer the number of times it needs to be (based on
the number that you found before)

Complexity
----------
Time: O(n + m) where n is the length of the input string and m is the
               length of the output string
Space: O(m) 
*/
class Solution {
public:
    int getNumberLength(string s, int idx) {
        int len = 0;
        while (isdigit(s[idx++])) len++;
        return len;
    }

    int findMatchingBracketIdx(string s, int idx) {
        int bracketCount = 1;
        while (bracketCount != 0) {
            idx++;
            if (s[idx] == '[') bracketCount++;
            else if (s[idx] == ']') bracketCount--;
        }

        return idx;
    }

    string decodeString(string s) {
        const int n = size(s);
        int i = 0, len, repeated, matchingIdx;
        string ans = "";
        while (i < n) {
            if (!isdigit(s[i])) {
                ans += s[i++];
            } else {
                len = getNumberLength(s, i);
                repeated = stoi(s.substr(i, len));
                matchingIdx = findMatchingBracketIdx(s, i + len);
                string expand = decodeString(s.substr(i + len + 1, matchingIdx - (i + len + 1)));
                while (repeated--) {
                    ans += expand;
                }
                i = matchingIdx + 1;
            }
        }

        return ans;
    }
};
