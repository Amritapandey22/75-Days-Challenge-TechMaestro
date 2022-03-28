class Solution {
public:
    bool search(vector<int>& nums, int target) {
       for(int el:nums){
           if(el==target)return true;
       } 
        
        return false;
    }
};