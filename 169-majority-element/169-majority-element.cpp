class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=nums[0];
        int count=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(val==nums[i])count++;
            else count--;//pairing done or we can say ki kisi aur element ne
            // counter kr dia
            
            if(count==0){
                val=nums[i];
                count=1;
            }
        }
        
        return val;
    }
};