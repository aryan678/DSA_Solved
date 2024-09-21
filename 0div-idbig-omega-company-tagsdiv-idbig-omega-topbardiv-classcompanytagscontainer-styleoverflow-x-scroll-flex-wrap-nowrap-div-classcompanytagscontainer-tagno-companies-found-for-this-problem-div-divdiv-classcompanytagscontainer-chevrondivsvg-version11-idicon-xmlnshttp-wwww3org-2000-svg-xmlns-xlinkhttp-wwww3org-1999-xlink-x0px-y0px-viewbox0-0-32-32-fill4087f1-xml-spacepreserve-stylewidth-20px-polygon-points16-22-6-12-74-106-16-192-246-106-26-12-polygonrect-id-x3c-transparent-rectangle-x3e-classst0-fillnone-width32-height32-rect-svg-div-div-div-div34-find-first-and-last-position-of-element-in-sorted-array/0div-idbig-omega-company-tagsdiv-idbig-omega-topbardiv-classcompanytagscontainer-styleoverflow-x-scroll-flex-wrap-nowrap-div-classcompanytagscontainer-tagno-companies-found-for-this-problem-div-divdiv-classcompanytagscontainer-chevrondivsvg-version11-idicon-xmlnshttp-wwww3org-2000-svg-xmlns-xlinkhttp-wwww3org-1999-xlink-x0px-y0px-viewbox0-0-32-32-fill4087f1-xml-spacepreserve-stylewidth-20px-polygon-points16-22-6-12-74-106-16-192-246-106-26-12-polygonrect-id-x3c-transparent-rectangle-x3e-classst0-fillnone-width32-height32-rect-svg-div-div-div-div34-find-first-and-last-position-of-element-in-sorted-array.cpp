class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int ans1=-1,ans2=-1;
        while(low<=high){
           int mid=(low+high)/2;
            if(target==nums[mid]){
                ans1=mid;
                high=mid-1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        low=0; high=nums.size()-1;
        while(low<=high){
           int mid=(low+high)/2;
            if(target==nums[mid]){
                ans2=mid;
                low=mid+1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return {ans1,ans2};
    }
};