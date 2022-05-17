class Solution {
public:
    void solve(int idx,vector<int>&num,vector<int>&ds,vector<vector<int>>&ans,int k){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
            
        if(idx==num.size()){
            return;
        }
        ds.push_back(num[idx]);
        solve(idx+1,num,ds,ans,k);
        ds.pop_back();
        solve(idx+1,num,ds,ans,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>num;
        for(int i=1;i<=n;i++)num.push_back(i);
        
        //now generate subseq of length=k
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0,num,ds,ans,k);
        
        return ans;
    }
};