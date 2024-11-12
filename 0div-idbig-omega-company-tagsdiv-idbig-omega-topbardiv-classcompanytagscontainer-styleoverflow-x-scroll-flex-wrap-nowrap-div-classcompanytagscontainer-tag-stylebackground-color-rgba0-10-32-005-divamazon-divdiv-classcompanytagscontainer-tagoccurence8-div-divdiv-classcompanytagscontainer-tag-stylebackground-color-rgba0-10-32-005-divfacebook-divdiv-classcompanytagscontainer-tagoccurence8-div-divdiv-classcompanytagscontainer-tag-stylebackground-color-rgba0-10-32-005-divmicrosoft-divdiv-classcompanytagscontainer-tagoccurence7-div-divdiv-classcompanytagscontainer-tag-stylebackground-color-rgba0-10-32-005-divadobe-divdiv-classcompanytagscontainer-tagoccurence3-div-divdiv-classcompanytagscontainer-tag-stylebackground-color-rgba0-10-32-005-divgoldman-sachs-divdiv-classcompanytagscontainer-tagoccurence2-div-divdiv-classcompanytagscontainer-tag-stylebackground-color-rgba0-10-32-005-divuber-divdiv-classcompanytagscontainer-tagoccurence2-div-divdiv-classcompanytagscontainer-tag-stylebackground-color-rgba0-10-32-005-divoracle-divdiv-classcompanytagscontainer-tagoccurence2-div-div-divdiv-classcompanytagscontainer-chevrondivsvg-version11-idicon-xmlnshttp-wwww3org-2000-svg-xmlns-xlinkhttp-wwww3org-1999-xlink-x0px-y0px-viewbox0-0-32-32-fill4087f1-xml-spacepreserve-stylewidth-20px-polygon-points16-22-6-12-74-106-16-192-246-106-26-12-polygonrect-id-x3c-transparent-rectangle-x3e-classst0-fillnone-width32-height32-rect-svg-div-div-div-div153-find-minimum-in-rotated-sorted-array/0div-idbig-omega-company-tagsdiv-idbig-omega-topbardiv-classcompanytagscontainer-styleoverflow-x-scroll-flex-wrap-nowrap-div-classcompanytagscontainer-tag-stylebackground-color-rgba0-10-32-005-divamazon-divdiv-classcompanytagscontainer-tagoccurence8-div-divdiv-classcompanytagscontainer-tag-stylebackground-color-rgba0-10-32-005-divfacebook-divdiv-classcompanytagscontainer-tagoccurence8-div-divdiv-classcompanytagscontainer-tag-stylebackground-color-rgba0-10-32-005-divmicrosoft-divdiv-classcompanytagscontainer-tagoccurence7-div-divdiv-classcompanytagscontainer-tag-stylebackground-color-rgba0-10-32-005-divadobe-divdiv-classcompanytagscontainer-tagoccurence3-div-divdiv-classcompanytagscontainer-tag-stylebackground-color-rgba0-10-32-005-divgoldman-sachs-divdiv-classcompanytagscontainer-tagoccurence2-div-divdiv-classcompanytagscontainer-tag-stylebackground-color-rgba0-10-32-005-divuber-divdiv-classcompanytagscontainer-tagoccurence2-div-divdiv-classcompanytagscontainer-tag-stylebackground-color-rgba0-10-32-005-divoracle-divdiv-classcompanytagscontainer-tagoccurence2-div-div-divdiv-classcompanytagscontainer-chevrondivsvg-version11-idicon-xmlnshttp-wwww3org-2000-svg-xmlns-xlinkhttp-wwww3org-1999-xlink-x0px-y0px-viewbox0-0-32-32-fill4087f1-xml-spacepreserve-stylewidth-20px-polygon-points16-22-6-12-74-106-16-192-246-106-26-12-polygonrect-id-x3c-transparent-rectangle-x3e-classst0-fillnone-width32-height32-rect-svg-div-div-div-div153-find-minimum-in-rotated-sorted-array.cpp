class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid,mini=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[low]<=nums[mid]) //left sorted
            {
                mini=min(nums[low],mini);
                low=mid+1;
            }
            else if(nums[mid]<nums[high]) //right sorted
            {
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }
        return mini;
    }
};