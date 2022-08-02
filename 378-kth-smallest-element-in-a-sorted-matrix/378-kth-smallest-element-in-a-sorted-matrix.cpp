class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>ans;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans.push_back(matrix[i][j]);
            }
        }
        priority_queue<int>pq;
        for(int el:ans){
           pq.push(el);
           if(pq.size()>k)pq.pop(); 
        }
        
        return pq.top();
    }
};