class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[j]%2==0)swap(nums[i++],nums[j]);
            else j--;
        }
        
        return nums;
    }
};