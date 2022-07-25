class Solution {
public:
    int bs(vector<int>& nums, int trg,bool isFirst){
        int l=0,r=nums.size()-1,ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==trg){
              ans=mid;
               if(isFirst) r=mid-1;
               else l=mid+1;                
          }
            else if(nums[mid]>trg)r=mid-1;
            else l=mid+1;
        }
        
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=bs(nums,target,true);
        int end=bs(nums,target,false);
        
        return {start,end};
        
    }
};