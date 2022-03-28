class Solution {
public:
    int n;
    int m;
    bool dfs(int i,int j,int wlen,vector<vector<char>>& board,int curLen,string &word){
        if(curLen==wlen)return true;
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[curLen]){
            return false;
        }
        char ch=board[i][j];
        board[i][j]='*';
        if(dfs(i+1,j,wlen,board,curLen+1,word) or dfs(i-1,j,wlen,board,curLen+1,word) or dfs(i,j+1,wlen,board,curLen+1,word) or dfs(i,j-1,wlen,board,curLen+1,word)) return true;
        
        board[i][j]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int wlen=word.size();
         n=board.size();
         m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,wlen,board,0,word)) return true;
                }
            }
        }
        
        return false;
    }
};