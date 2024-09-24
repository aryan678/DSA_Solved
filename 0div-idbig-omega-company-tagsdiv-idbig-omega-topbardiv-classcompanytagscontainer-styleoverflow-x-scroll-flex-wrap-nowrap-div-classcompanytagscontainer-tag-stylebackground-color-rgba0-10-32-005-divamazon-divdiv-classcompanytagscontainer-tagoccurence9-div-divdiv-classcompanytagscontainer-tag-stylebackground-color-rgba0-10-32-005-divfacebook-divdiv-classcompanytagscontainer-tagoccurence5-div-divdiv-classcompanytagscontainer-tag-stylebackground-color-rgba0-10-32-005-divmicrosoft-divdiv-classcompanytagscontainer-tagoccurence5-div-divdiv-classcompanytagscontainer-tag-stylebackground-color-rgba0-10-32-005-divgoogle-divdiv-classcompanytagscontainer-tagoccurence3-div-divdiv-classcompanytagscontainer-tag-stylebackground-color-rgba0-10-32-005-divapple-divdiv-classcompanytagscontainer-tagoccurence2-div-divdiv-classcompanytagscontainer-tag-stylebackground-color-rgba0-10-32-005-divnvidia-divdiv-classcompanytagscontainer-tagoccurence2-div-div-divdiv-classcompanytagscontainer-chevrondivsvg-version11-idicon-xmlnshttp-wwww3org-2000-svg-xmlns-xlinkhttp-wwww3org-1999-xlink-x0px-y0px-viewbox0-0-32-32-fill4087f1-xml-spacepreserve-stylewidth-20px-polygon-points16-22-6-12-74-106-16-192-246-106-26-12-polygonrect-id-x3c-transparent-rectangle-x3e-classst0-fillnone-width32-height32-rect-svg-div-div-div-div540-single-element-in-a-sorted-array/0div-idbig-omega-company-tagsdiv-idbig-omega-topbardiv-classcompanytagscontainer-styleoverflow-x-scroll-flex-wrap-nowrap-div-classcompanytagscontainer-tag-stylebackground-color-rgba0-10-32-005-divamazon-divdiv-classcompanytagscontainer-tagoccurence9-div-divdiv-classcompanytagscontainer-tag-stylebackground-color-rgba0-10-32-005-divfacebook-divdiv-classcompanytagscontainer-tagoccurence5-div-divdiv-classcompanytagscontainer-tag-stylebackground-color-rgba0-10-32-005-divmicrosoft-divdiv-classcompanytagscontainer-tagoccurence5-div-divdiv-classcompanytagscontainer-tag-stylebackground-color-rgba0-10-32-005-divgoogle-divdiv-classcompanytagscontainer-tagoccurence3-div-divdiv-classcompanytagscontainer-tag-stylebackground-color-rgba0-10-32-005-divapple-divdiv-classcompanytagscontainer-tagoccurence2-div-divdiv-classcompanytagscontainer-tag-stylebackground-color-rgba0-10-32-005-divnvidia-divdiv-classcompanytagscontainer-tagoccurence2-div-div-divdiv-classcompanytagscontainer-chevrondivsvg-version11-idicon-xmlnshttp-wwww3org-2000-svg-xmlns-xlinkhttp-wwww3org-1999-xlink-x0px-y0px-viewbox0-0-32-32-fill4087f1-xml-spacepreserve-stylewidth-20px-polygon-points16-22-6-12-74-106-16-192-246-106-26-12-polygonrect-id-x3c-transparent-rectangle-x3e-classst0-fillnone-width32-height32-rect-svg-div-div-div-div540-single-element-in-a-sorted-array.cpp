class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,mid,high=nums.size()-1;
        if(high==0) return nums[0];
        if(nums[0]!=nums[1])    return nums[0];
        if(nums[high]!=nums[high-1])    return nums[high];
        while(low<=high){
            mid=(low+high)/2;
            if((mid%2==0 && nums[mid]==nums[mid+1])||(mid%2!=0 && nums[mid]==nums[mid-1]))
                        low=mid+1;
            else if((mid%2!=0 && nums[mid]==nums[mid+1])||(mid%2==0 && nums[mid]==nums[mid-1]))
                 high=mid-1;
            else 
                 return nums[mid];
                
        }
        return -1;
    }
};