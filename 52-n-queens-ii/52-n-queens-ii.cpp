class Solution {
public:
    vector<bool>row,col,diag,adiag;
    
    int answer(vector<bool>&row,vector<bool>&col,
   vector<bool>&diag,vector<bool>&adiag,int n,int r){
        if(r==n) return 1;
        int count=0;
        
        for(int c=0;c<n;c++){
            if(!col[c] and !diag[r+c] and !adiag[r-c+n-1]){
                col[c] = diag[r+c]= adiag[r-c+n-1]=true;
                count+=answer(row,col,diag,adiag,n,r+1);
                col[c] = diag[r+c]= adiag[r-c+n-1]=false;
            }
        }
        
        return count;
        
    }
    
    int totalNQueens(int n) {
        row.resize(n,false);
        col.resize(n,false);
        diag.resize((2*n)-1,false);
        adiag.resize((2*n)-1,false);
        
        return answer(row,col,diag,adiag,n,0);
    }
};