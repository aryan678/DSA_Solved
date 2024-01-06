class Solution {
   public:
    int jobScheduling(vector<int>& startTimes, vector<int>& endTimes, vector<int>& profits) {
        int numJobs = startTimes.size();
        vector<tuple<int, int, int>> jobs(numJobs);
        vector<int> maxProfits(numJobs + 1, 0);

        for (int i = 0; i < numJobs; i++)
            jobs[i] = make_tuple(startTimes[i], endTimes[i], profits[i]);

        sort(jobs.begin(), jobs.end());

        for (int i = numJobs - 1; i >= 0; i--) {
            int nextJobIndex = lower_bound(jobs.begin(), jobs.end(), make_tuple(get<1>(jobs[i]), 0, 0)) - jobs.begin();

            int profitWithCurrentJob = get<2>(jobs[i]) + maxProfits[nextJobIndex];
            int profitWithoutCurrentJob = maxProfits[i + 1];

            maxProfits[i] = max(profitWithCurrentJob, profitWithoutCurrentJob);
        }

        return maxProfits[0];
    }
};