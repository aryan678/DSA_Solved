class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int ctr=0;
        for(int i=0;i<nums.size();i++){
            if(ctr==0){  
                    ele=nums[i];
                    ctr++;
                }
            else if(ele==nums[i]) 
                ctr++;
            else{
                ctr--;
            }
        }
        return ele;
    }
};