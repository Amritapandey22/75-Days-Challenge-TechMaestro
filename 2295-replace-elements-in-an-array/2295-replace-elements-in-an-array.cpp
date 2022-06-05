class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        //it=mp.find(),it-first=key,it->second=vale,find searches the key in the map and not the value
        
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
            
        }
        
        for(auto d:op){
            int delElem=d[0];//this element is definitely present
            int inElem=d[1];
            int idx=mp[d[0]];
            mp.erase(delElem);
            mp[inElem]=idx;
        }
        
        for(auto it:mp){
            nums[it.second]=it.first;
        }
        
        return nums;
    }
};