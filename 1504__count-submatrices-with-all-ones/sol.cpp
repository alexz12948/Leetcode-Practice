/*
Explanation of Solution
-----------------------

This is an interesting solution with a surprising solution, which
is really quite elegant imo

The basic idea is that we want to continuously calculate the number
of whole rectangles that include row `i`. What this means is if we had
an array like this (this is pulled directly from the example):

101
110
110

Then we want to only consider 3 different subarrays:

101  100  100
000  100  100
000  000  100

The reason why is we want to know the number of rectangles that
can be made using the top row and iterating downwards. You can
see that in the first iteration there are 2 individual rectangles.
The second iteration has only 1 since there is just 1, 1x2 and
the third also only has 1, 1x3.

We continue to increament the outer value so that then we only consider

110
110

and its subarrays:

110  110
000  110

And how many that yields.

Complexity
----------
Time: O(m * nm) --> nm for the interating over a submatrix and 
                    m for the extra iteration down the rows 
Space: O(n) 
*/
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int m = size(mat), n = size(mat[0]);
        int ans = 0, currLen;

        for (int i = 0; i < m; i++) {
            vector<int> v(n, 1);
            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++)
                    v[k] = v[k] & mat[j][k];

                currLen = 0;
                for (int k = 0; k < n; k++) {
                    currLen = v[k] == 0 ? 0 : currLen + 1;
                    ans += currLen;
                }
            }
        }

        return ans;
    }
};
