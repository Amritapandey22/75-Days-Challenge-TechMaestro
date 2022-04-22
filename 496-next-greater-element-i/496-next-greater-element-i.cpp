class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        
        unordered_map<int,int>mp;
        stack<int>st;
        st.push(-1);
        
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1)mp[nums[i]]=-1;
            while(st.top()!=-1 and st.top()<nums[i])st.pop();
            
            mp[nums[i]]=st.top();
            st.push(nums[i]);
        }
        
        vector<int>ans;
        for(int el:nums1){
            ans.push_back(mp[el]);
        }
        
        return ans;
    }
};