class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>mp{nums.begin(),nums.end()};
        int ans=1;
        for(int el:nums){
            if(mp.find(el+1)==mp.end()){
                int curr=1;
                //last elemernt found
                while(mp.find(el-curr)!=mp.end()){
                    curr++;
                }
                ans=max(ans,curr);
            }
        }
        
        return ans;
    }
};