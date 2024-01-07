
   class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = {};
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                if (diff > INT_MAX || diff < INT_MIN) continue;
                int c1 = 0;
                if (dp[j].find(diff) == dp[j].end()) {
                    c1 = 0;
                } else {
                    c1 = dp[j][diff];
                }
                result += c1;
                int c2 = 0;
                if (dp[i].find(diff) == dp[i].end()) {
                    c2 = 0;
                } else {
                    c2 = dp[i][diff];
                }
                dp[i][diff] = c1 + c2 + 1;
            }
        }

        return result;
    }
};
        