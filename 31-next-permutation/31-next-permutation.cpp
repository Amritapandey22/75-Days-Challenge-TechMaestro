class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int in1,in2;
        //getting the breakpoint
       for(int i=n-2;i>=0;i--){
           if(nums[i]<nums[i+1]) {
               in1=i;
               break;
           }
       } 
        if(in1<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[in1]){
                in2=i;
                break;
            }
        }
        swap(nums[in1],nums[in2]);
        reverse(nums.begin()+in1+1,nums.end());
    }
};