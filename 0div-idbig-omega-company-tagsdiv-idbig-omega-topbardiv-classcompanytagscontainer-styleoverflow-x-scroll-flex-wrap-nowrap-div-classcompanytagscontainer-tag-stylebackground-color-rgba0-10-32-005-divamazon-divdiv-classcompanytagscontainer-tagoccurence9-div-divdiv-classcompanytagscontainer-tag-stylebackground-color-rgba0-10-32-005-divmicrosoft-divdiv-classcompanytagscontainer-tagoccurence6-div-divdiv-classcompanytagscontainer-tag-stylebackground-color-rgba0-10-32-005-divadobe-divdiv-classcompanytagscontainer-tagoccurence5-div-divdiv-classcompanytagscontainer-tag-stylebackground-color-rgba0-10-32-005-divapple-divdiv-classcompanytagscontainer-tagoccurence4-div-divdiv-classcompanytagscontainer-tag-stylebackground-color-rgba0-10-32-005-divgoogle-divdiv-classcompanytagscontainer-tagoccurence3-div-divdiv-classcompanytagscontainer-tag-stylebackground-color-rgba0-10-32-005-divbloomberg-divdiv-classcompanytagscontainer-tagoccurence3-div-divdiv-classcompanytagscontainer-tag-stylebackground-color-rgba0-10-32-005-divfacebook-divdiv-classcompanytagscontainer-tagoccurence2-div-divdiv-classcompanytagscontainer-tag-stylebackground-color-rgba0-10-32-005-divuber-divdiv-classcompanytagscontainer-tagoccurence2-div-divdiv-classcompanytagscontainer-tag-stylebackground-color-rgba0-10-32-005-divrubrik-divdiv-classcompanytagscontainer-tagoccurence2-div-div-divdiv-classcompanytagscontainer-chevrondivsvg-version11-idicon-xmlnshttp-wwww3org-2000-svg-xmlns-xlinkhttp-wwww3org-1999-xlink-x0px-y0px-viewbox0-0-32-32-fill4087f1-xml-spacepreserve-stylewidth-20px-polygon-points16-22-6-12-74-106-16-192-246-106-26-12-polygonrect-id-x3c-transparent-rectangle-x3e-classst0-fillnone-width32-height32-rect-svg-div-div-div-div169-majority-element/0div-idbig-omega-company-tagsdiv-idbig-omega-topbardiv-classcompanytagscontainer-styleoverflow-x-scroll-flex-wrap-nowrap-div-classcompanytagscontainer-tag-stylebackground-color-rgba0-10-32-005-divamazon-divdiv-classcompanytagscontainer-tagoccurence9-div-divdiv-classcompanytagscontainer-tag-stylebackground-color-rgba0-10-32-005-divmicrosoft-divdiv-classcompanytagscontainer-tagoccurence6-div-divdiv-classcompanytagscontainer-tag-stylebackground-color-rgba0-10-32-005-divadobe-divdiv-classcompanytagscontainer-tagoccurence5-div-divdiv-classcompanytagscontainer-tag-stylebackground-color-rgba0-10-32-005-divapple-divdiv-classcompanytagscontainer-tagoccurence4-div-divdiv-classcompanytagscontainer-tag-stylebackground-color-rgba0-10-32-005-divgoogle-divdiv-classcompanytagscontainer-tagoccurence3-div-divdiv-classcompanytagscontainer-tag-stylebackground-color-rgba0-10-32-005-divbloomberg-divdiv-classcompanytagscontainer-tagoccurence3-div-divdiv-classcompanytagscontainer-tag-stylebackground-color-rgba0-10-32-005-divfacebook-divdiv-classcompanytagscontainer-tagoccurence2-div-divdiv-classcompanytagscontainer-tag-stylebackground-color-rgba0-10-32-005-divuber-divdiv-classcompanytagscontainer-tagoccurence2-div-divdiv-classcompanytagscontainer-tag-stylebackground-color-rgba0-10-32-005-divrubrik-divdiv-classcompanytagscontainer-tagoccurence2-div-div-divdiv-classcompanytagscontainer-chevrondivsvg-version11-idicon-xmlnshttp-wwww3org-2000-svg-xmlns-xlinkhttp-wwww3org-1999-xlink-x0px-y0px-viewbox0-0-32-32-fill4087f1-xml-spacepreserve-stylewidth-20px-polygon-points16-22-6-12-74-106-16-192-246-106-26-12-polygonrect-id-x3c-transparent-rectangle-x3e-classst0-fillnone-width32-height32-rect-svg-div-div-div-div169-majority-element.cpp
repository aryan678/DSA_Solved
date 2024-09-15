class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int ctr=0;
        for(int i=0;i<nums.size();i++){
            if(ele==nums[i]) 
                ctr++;
            else{
                ctr--;
                if(ctr==0){  
                    ele=nums[i];
                    ctr++;
                }
            }
        }
        return ele;
    }
};