class Solution {
public:
    int lenOfLIS(vector<int>&nums){
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=temp.back())temp.push_back(nums[i]);
            else{
                int idx=upper_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        
        return temp.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<k;i++){
            vector<int>temp;
            for(int j=i;j<n;j+=k) temp.push_back(arr[j]);
            
            ans+=temp.size()-lenOfLIS(temp);
        }
        
        return ans;
    }
};