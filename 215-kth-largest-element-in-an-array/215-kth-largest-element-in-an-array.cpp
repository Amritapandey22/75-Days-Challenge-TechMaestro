class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        
        for(int el:nums){
            pq.push(-el);
            if(pq.size()>k)pq.pop();
        }
        
        return -pq.top();
    }
};