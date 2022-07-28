class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;q.push(start);
        int n=arr.size();
        set<int>vis;
        vis.insert(start);
        
        while(q.size()){
            int idx=q.front();
            vis.insert(idx);
            q.pop();
            if(arr[idx]==0)return true;
            if(idx-arr[idx]>=0 and !vis.count(idx-arr[idx]))q.push(idx-arr[idx]);
            if(idx+arr[idx]<n and !vis.count(idx+arr[idx]))q.push(idx+arr[idx]);
        }
        
        return false;
    }
};