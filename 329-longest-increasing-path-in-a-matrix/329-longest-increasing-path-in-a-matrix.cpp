class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>indeg(n,vector<int>(m,0));
        vector<vector<int>>dir{{0,-1},{0,1},{1,0},{-1,0}};
        
        queue<int>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(auto d:dir){
                    int r = i+d[0];
                    int c = j+d[1];
                    
                    if(r>=0 and c>=0 and r<n and c<m and matrix[i][j]>matrix[r][c])
                        indeg[i][j]++;
                }
                
                if(indeg[i][j]==0)q.push(i*m+j);
            }
        }
        
        int level=0;
        while(q.size()){
            int qsize=q.size();
            while(qsize--){
                int idx=q.front();
                q.pop();
                
                int sr=idx/m;
                int sc=idx%m;
                for(auto d:dir){
                    int r = sr+d[0];
                    int c = sc+d[1];
                    
                    if(r>=0 and c>=0 and r<n and c<m and matrix[r][c]>matrix[sr][sc] 
                       and --indeg[r][c]==0) q.push(r*m+c);
                }
            }
            
            level++;
        }
        
        return level;
    }
};