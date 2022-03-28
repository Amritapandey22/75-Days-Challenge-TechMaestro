class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int minr=0;
        int minc=0;
        int maxr=n-1;
        int maxc=m-1;
        int total=n*m;
        int count=0;
        vector<int>ans;
        while(minr<=maxr and minc<=maxc and count<total){
            for(int i=minc;i<=maxc and count<total;i++){
               ans.push_back(matrix[minr][i]); 
                count++;
            }
            minr++;
            
            for(int i=minr;i<=maxr and count<total;i++){
                ans.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;
            
            for(int i=maxc;i>=minc and count<total;i--){
                ans.push_back(matrix[maxr][i]);
                count++;
            }
            maxr--;
            
            for(int i=maxr;i>=minr and count<total;i--){
                ans.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        
        return ans;
    }
};