class Solution {
public:
    bool check(vector<int>& nums) {
        int ctr=0;      
        for(int i=0; i<nums.size()-1;i++){
          if(nums[i]>nums[i+1])
              ctr++;
      }
        if(ctr==1){
            return nums[0]>=nums[nums.size()-1];
        }
        return ctr<2;
    }
};