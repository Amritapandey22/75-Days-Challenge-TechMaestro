class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size());
        int most_pos=nums.size()-1;
        int most_neg=0;
        int idx=nums.size()-1;
        //we will start filling the array from backwards and find the elemnt who r contributing in creating the max number and since we know either most negnum or most posnum can do that so we will keep check of that
        
        while(most_neg <= most_pos){
           int lmaxnum= nums[most_neg]*nums[most_neg];
            int rmaxnum= nums[most_pos]*nums[most_pos];
            
            if(lmaxnum>rmaxnum){
                res[idx]=lmaxnum;
                most_neg++;
            }else{
                res[idx]=rmaxnum;
                most_pos--;
            }
            
            idx--;
        }
        
        return res;
    }
};