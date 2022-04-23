class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i=2*n-1;i>=0;i--){
            while(st.size()!=0 and st.top()<=nums[i%n])st.pop();
           //if(i==7)cout<<st.top();
            if(ans[i%n]==-1 and st.size()!=0)
              ans[i%n]=st.top();
            else if(st.size()==0)ans[i%n]=-1;
            st.push(nums[i%n]);
        }
        
        return ans;
    }
};