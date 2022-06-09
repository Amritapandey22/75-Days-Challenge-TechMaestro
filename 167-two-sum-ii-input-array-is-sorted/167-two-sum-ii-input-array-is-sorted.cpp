class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int trg) {
       int l=0;
       int r=nums.size()-1;
        
       while(l<r){
           if(nums[l]+nums[r]<trg)l++;
           else if(nums[l]+nums[r]>trg)r--;
           else return {l+1,r+1};
       }
        
        return {};
    }
};