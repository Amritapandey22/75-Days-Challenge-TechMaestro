class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int,int>mp;
        for(int el:arr1)mp[el]++;
        
        
        vector<int>ans;
        
        for(int el:arr2){
            while(mp[el]>0){
                ans.push_back(el);
               
                mp[el]--;
            }
        }
        
       
            for(auto it:mp){
                while(it.second>0){
                    ans.push_back(it.first);
                    it.second--;
                }
            }
            return ans;
        
        
       
    }
};