class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1)return;
        int l=0;
        int r=1;
        
        while(r<nums.size()){
            if(nums[r]==0 ){
                r++;
                //continue;
                if(nums[l]!=0)l++;
                continue;
            }
            else if(nums[l]==0)swap(nums[l++],nums[r++]);
            else if(nums[l]!=0 and nums[r]!=0)l++,r++;
           
            
        }
        
    }
};