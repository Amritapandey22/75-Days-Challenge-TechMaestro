class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int idx=1;
        for(int i=0;i+1<nums.size();i++){
            if(nums[i]!=nums[i+1])nums[idx++]=nums[i+1];
        }
        
        return idx;
    }
};