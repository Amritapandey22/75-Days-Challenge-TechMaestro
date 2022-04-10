class Solution {
public:
    int searchInsert(vector<int>& nums, int trg) {
        //basically return floor or ceiling of the number of floor then floor+1=ans else ceil-1=ans;
        int l=0,r=nums.size()-1,probans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
           if(nums[mid]==trg){
               return mid;
           }
           else if(nums[mid]<trg){
               probans=mid;
               l=mid+1;
           }else r=mid-1; 
        }
        
        return probans+1;
        
    }
};