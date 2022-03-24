class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int trg) {
        unordered_map<int,int>mp;
        //key-num,value-idx
        for(int i=0;i<nums.size();i++){
          if(mp.find(trg-nums[i])!=mp.end()){
              
             return {mp[trg-nums[i]],i};
          }  
            mp[nums[i]]=i;
        }
        
        return {};
    }
};


