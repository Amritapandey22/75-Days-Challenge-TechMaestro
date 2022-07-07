class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp=nums[0],minp=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=maxp;
            // if(nums[i]==0){
            //     maxp=minp=1;
            //     continue;
            // }
            //also above case will fail this case [-2,0,-1],here max is 0,so we can't skip this case
            maxp=max({nums[i],nums[i]*maxp,nums[i]*minp});
            minp=min({nums[i],nums[i]*minp,nums[i]*temp});
            
            ans=max(ans,maxp);
        }
        
        return ans;
    }
};