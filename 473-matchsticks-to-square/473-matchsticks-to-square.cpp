class Solution {
public:
        bool canKpart(vector<int>& nums, int trgsum,int sum,int k,vector<bool>&vis,int idx){
        if(k==0)return true;
        if(sum==trgsum){
            return canKpart(nums,trgsum,0,k-1,vis,0);
        }
        bool res=false;
        for(int i=idx;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=true;
                res=res or canKpart(nums,trgsum,sum+nums[i],k,vis,i+1);
                vis[i]=false;
            }
        }
        
        return res;
    }
    bool makesquare(vector<int>& nums) {
        int k=4;
         int sum=0,n=nums.size(),maxel=0;
        for(int el:nums){
            sum+=el;
            maxel=max(maxel,el);
        }
        if(sum%k != 0 or maxel>sum/k)return false;
       vector<bool>vis(n,false);
        return canKpart(nums,sum/k,0,k,vis,0);
    }
};