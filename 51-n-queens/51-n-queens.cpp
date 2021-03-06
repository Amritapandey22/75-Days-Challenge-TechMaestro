class Solution {
public:
    vector<vector<string>> ret;
    int n;
    vector<bool>cols;
    vector<bool>upDiagLft;
    vector<bool>upDiagRgt;
    void dfs(vector<string> &board, int row){
        // exit condition
        if(row == board.size()){
            ret.push_back(board);
            return;
        }
        // iterate every possible position
        for(int i=0;i<board.size();++i){
            if(!cols[i] and !upDiagLft[row-i+n-1] and !upDiagRgt[row+i]){
                // make decision
                cols[i] =upDiagLft[row-i+n-1] =upDiagRgt[row+i]=true;
                board[row][i] = 'Q';
                // next iteration
                dfs(board,row+1);
                // back-tracking
                cols[i] =upDiagLft[row-i+n-1] =upDiagRgt[row+i]=false;
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int N) {
		// return empty if n <= 0
        n=N;
        if(N == 1) return {{"Q"}};
        cols.resize(n,false);
        upDiagLft.resize(2*n-1,false);
        upDiagRgt.resize(2*n-1,false);
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return ret;
    }
};




















// class Solution {
// public:
//     vector<vector<string>>ans;
//     bool isSafe(int i,int j,vector<vector<bool>>&grid){
//         //row check
//         for(int k=0;k<grid.size();k++){
//             if(grid[k][j])return false;
//         }
//         //col check
//         for(int k=0;k<grid.size();k++){
//             if(grid[j][k])return false;
//         }
        
//         //upper diagonal left
//         int u=i;
//         int r=j;
//         while(u and r){
//             if(grid[--u][--r])return false;
//         }
//         //upper diagonal right
//         for(int k=i-1,p=j+1;k>=0 and p<grid.size();k--,p++){
//             if(grid[k][p])return false;
//         }
        
//         return true;
        
//     }
//     void solve(vector<string>&temp,int r,vector<vector<bool>>&grid,int n){
//         if(r==n){
//             //cout<<"jckl";
//            ans.push_back(temp);
//             return;
//         }
//         for(int c=0;c<n;c++){
//             if(isSafe(r,c,grid)){
//                  cout<<"jckl";
//                 grid[r][c]=true;
//                 temp[r][c]='Q';
//                 solve(temp,r+1,grid,n);
//                 grid[r][c]=false;
//                 temp[r][c]='.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//        vector<vector<bool>>grid(n,vector<bool>(n,false));
//         vector<string>temp(n,string(n,'.'));
//         solve(temp,0,grid,n);
        
//         return ans;
//     }
// };