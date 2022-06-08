class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int trg) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(trg-nums[i])!=mp.end()){
                //cout<<mp[2];
                return {i,mp[trg-nums[i]]};
            }
            mp[nums[i]]=i;
           // cout<<mp[nums[i]]<<endl;
        }
        
        return {};
    }
};