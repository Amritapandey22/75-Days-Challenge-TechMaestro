class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum=0;
        for(int el:nums)rsum+=el;
        
        int lsum=0;
        int pvtIdx=-1;
        for(int i=0;i<nums.size();i++){
            rsum-=nums[i];
            if(lsum==rsum)return i;
            lsum+=nums[i];
        }
        
        return pvtIdx;
    }
};