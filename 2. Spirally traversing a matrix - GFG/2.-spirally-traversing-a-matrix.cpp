// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mt, int r, int c) 
    {
        // code here 
        int minr=0;
        int minc=0;
        int maxr=r-1;
        int maxc=c-1;
        vector<int>ans;
        int total=r*c+1;
        while(minr<=maxr and minc<=maxc and ans.size()!=r*c){
            //right
           for(int i=minc;i<=maxc and ans.size()!=r*c;i++){
              ans.push_back(mt[minr][i]);
             
           } 
           minr++;
           for(int i=minr;i<=maxr and ans.size()!=r*c;i++){
               ans.push_back(mt[i][maxc]);
                
           }
           maxc--;
           for(int i=maxc;i>=minc and ans.size()!=r*c;i--){
               ans.push_back(mt[maxr][i]);
                
           }
           maxr--;
           for(int i=maxr;i>=minr and ans.size()!=r*c;i--){
               ans.push_back(mt[i][minc]);
                
           }
           minc++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends