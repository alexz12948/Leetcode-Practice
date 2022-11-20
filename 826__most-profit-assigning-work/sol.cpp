/*
Explanation of Solution
-----------------------

The basic idea is that we want to look through the jobs in order of difficulty
and the workers in order of skill. This requires the sorting for each array and
the extra space necessary for the jobs array. Then, you loop through all the workers
in increasing order. For each of them, you loop through the jobs array and keep track
of the best profit for a job with difficulty < the skill of the worker. 

Notice that you do not reset the best profit or the index of the job ever 
since you know that the workers skill is in increasing order, which means that you
just need to keep track of the best profit and can continue to interate the jobs
array IF the next workers skill is greater than the current jobs difficulty. However,
you always just want to keep track of the best profit regardless of difficulty since
one worker can do only one job, so you just want to maximize the profit

Complexity
----------
Time: O(nlogn + mlogm + n + m) --> O(nlogn + mlogm) 
        where m is the number of works and n is the number of jobs
Space: O(n) 
*/
class Solution {
public:
    struct Job {
        int difficulty;
        int profit;
    };

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n = size(difficulty);

        vector<Job> jobs(n);
        for (int i = 0; i < n; i++)
            jobs[i] = {.difficulty = difficulty[i], .profit = profit[i]};

        sort(worker.begin(), worker.end());
        sort(jobs.begin(), jobs.end(),
            [](Job j1, Job j2) {
                return j1.difficulty < j2.difficulty;
            }
        );

        int ans = 0, bestProfit = 0, i = 0;
        for (int skill : worker) {
            while (i < n && skill >= jobs[i].difficulty)
                bestProfit = max(bestProfit, jobs[i++].profit);

            ans += bestProfit;
        }

        return ans;
    }
};
